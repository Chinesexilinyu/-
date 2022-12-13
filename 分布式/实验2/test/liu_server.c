#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include<pthread.h>
#include<queue>
#include<set>
using namespace std;

typedef struct Student
{
    char name[40];
    char id[40];
    float gr;
}student;
typedef struct Stu_fd
{
    student stu;
    int sock_fd;
}stu_fd;

typedef struct SStudent
{
    char id[3][40];
    float av;
}sstudent;

queue<stu_fd> que;
pthread_mutex_t lock;

void * tcpthread(void * arg){
    int sockFd = *(int*)arg;
    char recvbuf[256]={};
    ssize_t srecv=0;
    student temp;
    stu_fd Te;
    while (1)
    {
        memset(recvbuf,0,sizeof(recvbuf));
        srecv=recv(sockFd,recvbuf,sizeof(recvbuf),0);
        // if(srecv <= 0){
        //     if((ETIMEDOUT != 0) && (EWOULDBLOCK != 0)){
        //         close(sockFd);
        //         fprintf(stderr,"TCP server bind error!\n");
        //         return (void *)(-1);
        //     }
        //     continue;
        // }
        //cout<<srecv;
        if (srecv>0)
        {
            if (strcmp(recvbuf,"exit")==0)
            {
                printf("%d\n", sockFd);
                break;
            }
            memset(&temp,0,sizeof(student));
            memcpy(&temp,&recvbuf,sizeof(recvbuf));
            printf("%f,%s,%s\n", temp.gr,temp.id,temp.name);
            Te.stu=temp;
            Te.sock_fd=sockFd;
            pthread_mutex_lock(&lock);
            que.push(Te);
            pthread_mutex_unlock(&lock);
            
        }
    }
    close(sockFd);
    return (void *)0;
}

void *write_thread(void *  arg)
{
    set<int> fd;
    float avg=0;
    sstudent temp;
    while (1)
    {
        if (que.size()>=3)
        {
            stu_fd tmp;
            pthread_mutex_lock(&lock);
            for (int i = 0; i < 3; i++)
            {
                tmp=que.front();
                memcpy(&temp.id[i],&tmp.stu.id,sizeof(tmp.stu.id));
                temp.av+=tmp.stu.gr;
                fd.insert(tmp.sock_fd);
                que.pop();
            }
            pthread_mutex_unlock(&lock);
            temp.av/=3;
            for (set<int>::iterator i = fd.begin(); i !=fd.end(); )
            {
                send(*i,(char*)&temp,sizeof(sstudent),0);
                i=fd.erase(i);
            }
            fd.clear();
            temp.av=0;
        }
        usleep(500);
    }
    
}

int main()
{
    int res=pthread_mutex_init(&lock,NULL);
    if (res!=0)
    {
        cout<<"mutex failed,exit"<<endl;
        return 0;
    }
    pthread_t wtid;
    pthread_create(&wtid,NULL,write_thread,(void*)0);
    pthread_t tid[20];
    int sockfdconn[20];
    //socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        cout << "socket 创建失败： "<< endl;
        exit(1);
    }
    unsigned short port=8888;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);//将一个无符号短整型的主机数值转换为网络字节顺序，即大尾顺序(big-endian)
    addr.sin_addr.s_addr = INADDR_ANY;//net_addr方法可以转化字符串，主要用来将一个十进制的数转化为二进制的数，用途多于ipv4的IP转化。
    
    res = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &res, sizeof(int));
    if(res < 0){
        fprintf(stderr,"TCP reuseADDR error!\n");
        return -1;
    }
    
    //bind
    res = bind(socket_fd,(struct sockaddr*)&addr,sizeof(addr));
    if (res == -1)
    {
        cout << "bind创建失败： " << endl;
        exit(-1);
    }
    cout << "bind ok 等待客户端的连接" << endl<<"本地监听ip:port : "<<inet_ntoa(addr.sin_addr)<<":"<<port<<endl;

    //listen
    listen(socket_fd,30);
    struct sockaddr_in client;
    socklen_t len = sizeof(client);

    //accept
    int fd = -1;

    char buffer_in[255]={};
    char buffer_out[255]={};
    while (1)
    {
        fd=accept(socket_fd,(struct sockaddr*)&client,&len);
        if (fd == -1)
        {
            cout << "accept错误\n" << endl;
            continue;
        }
        send(fd,"hello",sizeof("hello"),0);
        char *ip = inet_ntoa(client.sin_addr);
        cout << "客户： 【" << ip << "】连接成功" << endl;
        memset(buffer_in, 0, sizeof(buffer_in));
        memset(buffer_out, 0, sizeof(buffer_out));
        //读取
        sockfdconn[0]=fd;
        cout<<sockfdconn[0]<<endl;
        int res1=pthread_create(&tid[0], NULL, tcpthread, (void*)&sockfdconn[0]);
        if (res1<0)
        {
            cout<<"线程启用失败，关闭连接"<<endl;
            close(fd);

        }
    }
    //关闭
    close(socket_fd);
    return 0;
}

