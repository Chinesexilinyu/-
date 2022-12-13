//多线程服务器代码
//createby:jty

/*------------------------------------------------------------------------
 * 头文件
 *------------------------------------------------------------------------
 */

//TCPmetechod.c的头文件 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <netinet/in.h>

//errexit.c的头文件 
#include <stdarg.h>

//passivesock.c的头文件 
#include <netdb.h>
#include <errno.h>

/*------------------------------------------------------------------------
 * 宏定义 
 *------------------------------------------------------------------------
 */

//
#define WORKERS 2
 
//TCPmetechod.c的宏定义 
#define	QLEN		  32	/* maximum connection queue length--最多连接的队列数量	*/
#define	BUFSIZE		4096
#define	INTERVAL	5	/* secs--单独显示记录线程的等待时长 */

//线程池函数宏定义：
 
//尾插法添加一个结点入队列 
#define LL_ADD(item, list) do {							\
	if (list == NULL){									\
		list=item;										\
	}													\
	else{												\
		item->prev = list;								\
		while(list->next != NULL){						\
			list = list->next;							\
		}												\
    	list->next = item;								\
    	item->next = item->prev;						\
    	item->prev = list;								\
    	list = item->next;								\
		item->next = NULL;								\
	}													\
} while(0)
 
//将一个结点从队列中删除 
#define LL_REMOVE(item, list) do {                              \
    if (item->prev != NULL) item->prev->next = item->next;      \
    if (item->next != NULL) item->next->prev = item->prev;      \
    if (item == list)   list = item->next;                      \
    item->prev = item->next = NULL;                             \
} while(0)

/*------------------------------------------------------------------------
 * 全局变量定义--copy from passivesock.c  
 *------------------------------------------------------------------------
 */ 
 
extern int	errno;
unsigned short	portbase = 0;	/* port base, for non-root servers	*/

/*------------------------------------------------------------------------
 * 结构体定义--包含状态、线程池 
 *------------------------------------------------------------------------
 */
 
//状态输出结构体 
struct {
	pthread_mutex_t	st_mutex;
	unsigned int	st_concount;
	unsigned int	st_contotal;
	unsigned long	st_contime;
	unsigned long	st_bytecount;
} stats;

typedef struct MANAGER ThreadPool;
typedef struct JOB JOB;

//执行队列结构体  
struct WORKER {
    pthread_t thread;
    ThreadPool *pool;
    int terminate;	//停止工作 
 
    struct WORKER *next;
    struct WORKER *prev;
};

//任务队列结构体 
struct JOB {
    void * (*func)(void *arg);   //任务函数
    void *user_data;            //任务函数的参数 
 
    struct JOB *next;
    struct JOB *prev;
};
 
//管理组件结构体 
struct MANAGER {
    struct WORKER *workers;  //执行队列 
    struct JOB *jobs;      //任务队列
	
	int num;
    pthread_cond_t jobs_cond;           //任务队列条件等待变量 
    pthread_mutex_t jobs_mutex;              //任务队列加锁 
};
typedef struct Student
{
    char name[40];
    char id[40];
    float gr;
}student;
typedef struct SStudent
{
    char id[3][40];
    float av;
}sstudent;
/*------------------------------------------------------------------------
 * 函数的声明 
 *------------------------------------------------------------------------
 */
 
//线程池引入函数 
int threadPoolCreate(ThreadPool *pool, int numWorkers); 
int threadPoolDestory(ThreadPool *pool); 
void threadPoolPush(ThreadPool *pool, void *(*func)(void *arg), void *arg);

//TCPmtechod.c中函数 
void prstats(void);
int	TCPechod(int fd);
int	errexit(const char *format, ...);
int	passiveTCP(const char *service, int qlen);

//passiveTCP.c中函数 
int	passivesock(const char *service, const char *transport, int qlen);

/*------------------------------------------------------------------------
 * main - Concurrent TCP server for ECHO service--main函数 
 *------------------------------------------------------------------------
 */
 
int main(int argc, char *argv[])
{
	char *service = "echo";	/* service name or port number	*/
	struct sockaddr_in fsin;	/* the address of a client	*/
	unsigned int alen;		/* length of client's address	*/
	int	msock;			/* master server socket		*/
	int	ssock;			/* slave server socket		*/
	
	//判断输入合法 
	switch (argc) {
	case	1:
		break;
	case	2:
		service = argv[1];
		break;
	default:
		errexit("usage: TCPechod [port]\n");
	}
	msock = passiveTCP(service, QLEN);

	//创建线程池 
	ThreadPool pool;
	int workers = WORKERS;
	int ret = threadPoolCreate(&pool,workers);
	if(ret < 0){
		fprintf(stdout, "threadpool_create failed!\n");
		return ret;
	}
	printf("IP:127.0.0.1   Port: %s\n",service);
	while (1) {
		alen = sizeof(fsin);
		ssock = accept(msock, (struct sockaddr *)&fsin, &alen);
		if(ssock < 0){
			if(errno == EINTR)
				continue;
			errexit("accept: %s\n", strerror(errno));
		}
		threadPoolPush(&pool,TCPechod, ssock);
	}
	threadPoolDestory(&pool);
}

/*------------------------------------------------------------------------
 * threadCallback --线程的初始化--入口函数 
 *------------------------------------------------------------------------
 */

static void* threadCallback(void *args)
{
    struct WORKER *worker = (struct WORKER*)args;
    //worker有两种状态：执行或是等待  

    while (1) {
    	//条件等待加锁 
        pthread_mutex_lock(&worker->pool->jobs_mutex);
     
		//若任务队列为空 
        while(worker->pool->jobs == NULL){
        	//终止信号 
            if(worker->terminate)
				break;
			//条件等待 
            pthread_cond_wait(&worker->pool->jobs_cond, &worker->pool->jobs_mutex);
        }
 		
 		//终止信号退出 
        if(worker->terminate){
        	//条件等待解锁 
            pthread_mutex_unlock(&worker->pool->jobs_mutex);
            break;
        }
        
        //打印提示信息
        printf("\n~~~~~~~~~~~~~~~~Thread %lu is awake!~~~~~~~~~~~~~~~~\n\n",worker->thread);
        
        struct JOB *job = worker->pool->jobs;
        LL_REMOVE(job, worker->pool->jobs);
		//条件等待解锁 
        pthread_mutex_unlock(&worker->pool->jobs_mutex);
        //执行响应函数 
        job->func(job->user_data);
        worker->pool->num--; 
    }
 
    free(worker);
    pthread_exit(NULL);     //线程退出 
}

/*------------------------------------------------------------------------
 * threadPoolCreate --线程池的初始化 
 *------------------------------------------------------------------------
 */
 
int threadPoolCreate(ThreadPool *pool, int numWorkers)
{
	pool->num = 0;
	
	pthread_t th;
	pthread_attr_t ta;
	
	//线程属性 
	(void) pthread_attr_init(&ta);
	(void) pthread_attr_setdetachstate(&ta, PTHREAD_CREATE_DETACHED);
	(void) pthread_mutex_init(&stats.st_mutex, 0);
	
	//输出显示线程创建 
	if (pthread_create(&th, &ta, (void * (*)(void *))prstats, 0) < 0)
		errexit("pthread_create(prstats): %s\n", strerror(errno));
	
    if(numWorkers < 1)
		numWorkers = 1;
    if(pool == NULL)
		return -1;
    memset(pool, 0, sizeof(ThreadPool));
	pool->workers=NULL;
	pool->jobs=NULL;
 	
 	//初始化条件变量和互斥锁 
 	//结构体赋值--内存拷贝
    pthread_cond_t blank_cond = PTHREAD_COND_INITIALIZER;
    memcpy(&pool->jobs_cond, &blank_cond, sizeof(pthread_cond_t));
    pthread_mutex_t blank_mutex = PTHREAD_MUTEX_INITIALIZER;
    memcpy(&pool->jobs_mutex, &blank_mutex, sizeof(pthread_mutex_t));
	
	fprintf(stdout, "\n--------------------------------------------------------------------------------\n");
	//初始化执行队列 
    int i = 0;
    for (i = 0; i < numWorkers; i++) {
        struct WORKER *worker = (struct WORKER *)malloc(sizeof(struct WORKER));
        if (worker == NULL) {
            perror("malloc");
            return -2;
        }
        memset(worker, 0, sizeof(struct WORKER));
		worker->next=NULL;
		worker->prev=NULL;
        
        worker->pool = pool;
 		
 		//线程指针变量，属性设置为空，线程执行函数，传入执行函数的参数 
        int ret = pthread_create(&worker->thread, &ta, threadCallback, worker);
        if (ret) {
            perror("pthread_create");
            free(worker);
            return -3;
        }
        fprintf(stdout, "worker thread: %lu\n", worker->thread);
 

 		//形成一个执行队列
        LL_ADD(worker, pool->workers);
    }
    fprintf(stdout, "--------------------------------------------------------------------------------\n");
    return 0;
}

/*------------------------------------------------------------------------
 * threadPoolPush --创建任务队列--往线程池里加入一个任务 
 *------------------------------------------------------------------------
 */

void threadPoolPush(ThreadPool *pool, void *(*func)(void *arg), void *arg)
{
	//创建一个任务 
	JOB *job=(JOB*)malloc(sizeof(JOB));

	if(job==NULL){
		perror("malloc");
		exit(1);
	}
    memset(job, 0, sizeof(JOB));
    job->func = func;
    job->user_data = arg;
	job->next=NULL;
	job->prev=NULL;

	//将任务加入到线程池中 
    pthread_mutex_lock(&pool->jobs_mutex);
	if(job!=NULL)
    	LL_ADD(job, pool->jobs);
    pool->num++;
    if(pool->num > WORKERS){
		printf("\n~~~~~~~~~~~~~~~~Waiting client number is %d.~~~~~~~~~~~~~~~~\n\n",(pool->num - WORKERS));
		fflush(stdout);
	}
	else{
    	pthread_cond_signal(&pool->jobs_cond);  //唤醒一个线程
	}
    pthread_mutex_unlock(&pool->jobs_mutex);
}

/*------------------------------------------------------------------------
 * threadPoolDestory --将所有线程都删除 
 *------------------------------------------------------------------------
 */

int threadPoolDestory(ThreadPool *pool)
{
    struct WORKER *worker = NULL;
    for (worker = pool->workers; worker != NULL; worker = worker->next){
        worker->terminate = 1;
    }
    //唤醒所有线程 
    pthread_mutex_lock(&pool->jobs_mutex);
    int ret = pthread_cond_broadcast(&pool->jobs_cond);
    pthread_mutex_unlock(&pool->jobs_mutex);
 
    return ret;
}

/*------------------------------------------------------------------------
 * TCPechod - echo data until end of file--线程运行函数 
 *------------------------------------------------------------------------
 */
 
int TCPechod(int fd)
{
	time_t	start;
	int	cc=0,i,j;
        student stu;
	sstudent ss;
	float f[4];
	start = time(0);
	(void) pthread_mutex_lock(&stats.st_mutex);
	stats.st_concount++;
	(void) pthread_mutex_unlock(&stats.st_mutex);
	while (recv(fd,(char*)&stu,sizeof(student),0)) 
	{
	        f[cc]=stu.gr;
	        for(i=0;i<sizeof(stu.id);i++)
	        {
	              ss.id[cc][i]=stu.id[i];
                }
                cc++;
		if(cc>2)
		{
	           cc=0;
	           f[3]=(f[0]+f[1]+f[2])/3;
	           ss.av=f[3];
	           send(fd,(char*)&ss,sizeof(sstudent),0);
	        }
	}
	(void) close(fd);
	(void) pthread_mutex_lock(&stats.st_mutex);
	stats.st_contime += time(0) - start;
	stats.st_concount--;
	stats.st_contotal++;
	(void) pthread_mutex_unlock(&stats.st_mutex);
	return 0;
}

/*------------------------------------------------------------------------
 * prstats - print server statistical data--在服务器端每隔5秒显示一下历史数据 
 *------------------------------------------------------------------------
 */
 
void prstats(void)
{
	time_t	now;

	while (1) {
		(void) sleep(INTERVAL);

		(void) pthread_mutex_lock(&stats.st_mutex);
		now = time(0);
		(void) printf("--- %s", ctime(&now));
		(void) printf("%-32s: %u\n", "Current connections",
			stats.st_concount);
		(void) printf("%-32s: %u\n", "Completed connections",
			stats.st_contotal);
		if (stats.st_contotal) {
			(void) printf("%-32s: %.2f (secs)\n",
				"Average complete connection time",
				(float)stats.st_contime /
				(float)stats.st_contotal);
		}
		(void) pthread_mutex_unlock(&stats.st_mutex);

	}
} 

/*------------------------------------------------------------------------
 * errexit - print an error message and exit--错误展示函数 
 *------------------------------------------------------------------------
 */
 
int errexit(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(1);
}

/*------------------------------------------------------------------------
 * passivesock - allocate & bind a server socket using TCP or UDP--Socket 
 *------------------------------------------------------------------------
 */
 
int passivesock(const char *service, const char *transport, int qlen)
/*
 * Arguments:
 *      service   - service associated with the desired port
 *      transport - transport protocol to use ("tcp" or "udp")
 *      qlen      - maximum server request queue length
 */
{
	struct servent	*pse;	/* pointer to service information entry	*/
	struct protoent *ppe;	/* pointer to protocol information entry*/
	struct sockaddr_in sin;	/* an Internet endpoint address		*/
	int	s, type;	/* socket descriptor and socket type	*/

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;

    /* Map service name to port number */
	if ( pse = getservbyname(service, transport) )
		sin.sin_port = htons(ntohs((unsigned short)pse->s_port)
			+ portbase);
	else if ((sin.sin_port=htons((unsigned short)atoi(service))) == 0)
		errexit("can't get \"%s\" service entry\n", service);

    /* Map protocol name to protocol number */
	if ( (ppe = getprotobyname(transport)) == 0)
		errexit("can't get \"%s\" protocol entry\n", transport);

    /* Use protocol to choose a socket type */
	if (strcmp(transport, "udp") == 0)
		type = SOCK_DGRAM;
	else
		type = SOCK_STREAM;

    /* Allocate a socket */
	s = socket(PF_INET, type, ppe->p_proto);
	if (s < 0)
		errexit("can't create socket: %s\n", strerror(errno));

    /* Bind the socket */
	if (bind(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
		errexit("can't bind to %s port: %s\n", service,
			strerror(errno));
	if (type == SOCK_STREAM && listen(s, qlen) < 0)
		errexit("can't listen on %s port: %s\n", service,
			strerror(errno));
	return s;
}

/*------------------------------------------------------------------------
 * passiveTCP - create a passive socket for use in a TCP server--TCP传输 
 *------------------------------------------------------------------------
 */
 
int passiveTCP(const char *service, int qlen)
/*
 * Arguments:
 *      service - service associated with the desired port
 *      qlen    - maximum server request queue length
 */
{
	return passivesock(service, "tcp", qlen);
}

