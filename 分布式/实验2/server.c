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

 
#include <stdarg.h>


#include <netdb.h>
#include <errno.h>


#define WORKERS 2
 

#define	QLEN		  32	
#define	BUFSIZE		4096
#define	INTERVAL	5	
 
#define LL_ADD(item, list) do {							
	if (list == NULL){									
		list=item;										
	}													
	else{												
		item->prev = list;								
		while(list->next != NULL){						
			list = list->next;							
		}												
    	list->next = item;								
    	item->next = item->prev;						
    	item->prev = list;								
    	list = item->next;							
		item->next = NULL;								
	}													
} while(0)
 

#define LL_REMOVE(item, list) do {                              
    if (item->prev != NULL) item->prev->next = item->next;      
    if (item->next != NULL) item->next->prev = item->prev;      
    if (item == list)   list = item->next;                      
    item->prev = item->next = NULL;                             
} while(0)

 
extern int	errno;
unsigned short	portbase = 0;	 

struct {
	pthread_mutex_t	st_mutex;
	unsigned int	st_concount;
	unsigned int	st_contotal;
	unsigned long	st_contime;
	unsigned long	st_bytecount;
} stats;

typedef struct MANAGER ThreadPool;
typedef struct JOB JOB;

 
struct WORKER {
    pthread_t thread;
    ThreadPool *pool;
    int terminate;	 
 
    struct WORKER *next;
    struct WORKER *prev;
};


struct JOB {
    void * (*func)(void *arg);   
    void *user_data;            
 
    struct JOB *next;
    struct JOB *prev;
};
 

struct MANAGER {
    struct WORKER *workers;  
    struct JOB *jobs;      
	
	int num;
    pthread_cond_t jobs_cond;           
    pthread_mutex_t jobs_mutex;               
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

 

int threadPoolCreate(ThreadPool *pool, int numWorkers); 
int threadPoolDestory(ThreadPool *pool); 
void threadPoolPush(ThreadPool *pool, void *(*func)(void *arg), void *arg);


void prstats(void);
int	TCPechod(int fd);
int	errexit(const char *format, ...);
int	passiveTCP(const char *service, int qlen);


int	passivesock(const char *service, const char *transport, int qlen);

 
int main(int argc, char *argv[])
{
	char *service = "echo";	
	struct sockaddr_in fsin;	
	unsigned int alen;		
	int	msock;			
	int	ssock;			
	
	
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


static void* threadCallback(void *args)
{
    struct WORKER *worker = (struct WORKER*)args;

    while (1) {
    	
        pthread_mutex_lock(&worker->pool->jobs_mutex);
     
		
        while(worker->pool->jobs == NULL){
        	 
            if(worker->terminate)
				break;
			
            pthread_cond_wait(&worker->pool->jobs_cond, &worker->pool->jobs_mutex);
        }
 		
 		
        if(worker->terminate){
        	 
            pthread_mutex_unlock(&worker->pool->jobs_mutex);
            break;
        }
        
        
        printf("\n~~~~~~~~~~~~~~~~Thread %lu is awake!~~~~~~~~~~~~~~~~\n\n",worker->thread);
        
        struct JOB *job = worker->pool->jobs;
        LL_REMOVE(job, worker->pool->jobs);
		
        pthread_mutex_unlock(&worker->pool->jobs_mutex);
        
        job->func(job->user_data);
        worker->pool->num--; 
    }
 
    free(worker);
    pthread_exit(NULL);     
}

 
int threadPoolCreate(ThreadPool *pool, int numWorkers)
{
	pool->num = 0;
	
	pthread_t th;
	pthread_attr_t ta;
	
	(void) pthread_attr_init(&ta);
	(void) pthread_attr_setdetachstate(&ta, PTHREAD_CREATE_DETACHED);
	(void) pthread_mutex_init(&stats.st_mutex, 0);
	
	if (pthread_create(&th, &ta, (void * (*)(void *))prstats, 0) < 0)
		errexit("pthread_create(prstats): %s\n", strerror(errno));
	
    if(numWorkers < 1)
		numWorkers = 1;
    if(pool == NULL)
		return -1;
    memset(pool, 0, sizeof(ThreadPool));
	pool->workers=NULL;
	pool->jobs=NULL;
 	
    pthread_cond_t blank_cond = PTHREAD_COND_INITIALIZER;
    memcpy(&pool->jobs_cond, &blank_cond, sizeof(pthread_cond_t));
    pthread_mutex_t blank_mutex = PTHREAD_MUTEX_INITIALIZER;
    memcpy(&pool->jobs_mutex, &blank_mutex, sizeof(pthread_mutex_t));
	
	fprintf(stdout, "\n--------------------------------------------------------------------------------\n");
	
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
 		 
        int ret = pthread_create(&worker->thread, &ta, threadCallback, worker);
        if (ret) {
            perror("pthread_create");
            free(worker);
            return -3;
        }
        fprintf(stdout, "worker thread: %lu\n", worker->thread);
 

        LL_ADD(worker, pool->workers);
    }
    fprintf(stdout, "--------------------------------------------------------------------------------\n");
    return 0;
}


void threadPoolPush(ThreadPool *pool, void *(*func)(void *arg), void *arg)
{
	
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

    pthread_mutex_lock(&pool->jobs_mutex);
	if(job!=NULL)
    	LL_ADD(job, pool->jobs);
    pool->num++;
    if(pool->num > WORKERS){
		printf("\n~~~~~~~~~~~~~~~~Waiting client number is %d.~~~~~~~~~~~~~~~~\n\n",(pool->num - WORKERS));
		fflush(stdout);
	}
	else{
    	pthread_cond_signal(&pool->jobs_cond);  
	}
    pthread_mutex_unlock(&pool->jobs_mutex);
}


int threadPoolDestory(ThreadPool *pool)
{
    struct WORKER *worker = NULL;
    for (worker = pool->workers; worker != NULL; worker = worker->next){
        worker->terminate = 1;
    }
    
    pthread_mutex_lock(&pool->jobs_mutex);
    int ret = pthread_cond_broadcast(&pool->jobs_cond);
    pthread_mutex_unlock(&pool->jobs_mutex);
 
    return ret;
}

 
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

 
int errexit(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(1);
}

 
int passivesock(const char *service, const char *transport, int qlen)
{
	struct servent	*pse;	
	struct protoent *ppe;	
	struct sockaddr_in sin;	
	int	s, type;	

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;

	if ( pse = getservbyname(service, transport) )
		sin.sin_port = htons(ntohs((unsigned short)pse->s_port)
			+ portbase);
	else if ((sin.sin_port=htons((unsigned short)atoi(service))) == 0)
		errexit("can't get \"%s\" service entry\n", service);

	if ( (ppe = getprotobyname(transport)) == 0)
		errexit("can't get \"%s\" protocol entry\n", transport);

	if (strcmp(transport, "udp") == 0)
		type = SOCK_DGRAM;
	else
		type = SOCK_STREAM;

	s = socket(PF_INET, type, ppe->p_proto);
	if (s < 0)
		errexit("can't create socket: %s\n", strerror(errno));

	if (bind(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
		errexit("can't bind to %s port: %s\n", service,
			strerror(errno));
	if (type == SOCK_STREAM && listen(s, qlen) < 0)
		errexit("can't listen on %s port: %s\n", service,
			strerror(errno));
	return s;
}

 
int passiveTCP(const char *service, int qlen)
{
	return passivesock(service, "tcp", qlen);
}

