#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>
#include<iostream>

#define buffer_size 1024
using namespace std;
int socket_fd,sendbytes,recvbytes;
char buffer_in[buffer_size]={};
char buffer_out[buffer_size]={};

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

void* thrd_recv(void *arg)
{
    sstudent temp;
while(1){
    memset(buffer_in , 0, sizeof(buffer_in));
    if ((recvbytes = recv(socket_fd, buffer_in, buffer_size, 0)) <0)
        {
            perror("recv");
            exit(1);
        }
    if(recvbytes>0){
        if (strcmp(buffer_in,"hello")==0)
            {
                /* code */
            }else{
            memset(&temp,0,sizeof(sstudent));
            memcpy(&temp,&buffer_in,sizeof(buffer_in));
            printf("%f\n%s\n%s\n%s\n", temp.av,temp.id[0],temp.id[1],temp.id[2]);}
        }
    }
}

int main()
{
    pthread_t thread[1];
    student temp;
    socket_fd = socket(AF_INET, SOCK_STREAM,0);
    if(socket_fd == -1)
    {
        cout<<"socket 创建失败："<<endl;
        exit(-1);
    }
    cout<<"请输入连接的ip"<<endl;
    char ip[15]="127.0.0.1";
    //cin>>ip;
    cout<<"请输入端口"<<endl;
    unsigned short port=8888    ;
    //cin>>port;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    cout<<inet_ntoa(addr.sin_addr)<<endl;
    int res = connect(socket_fd,(struct sockaddr*)&addr,sizeof(addr));
    if(res == -1)
    {
        cout<<"bind 链接失败："<<endl;
        exit(-1);
    }
    cout<<"bind 链接成功："<<endl;
    pthread_create(&thread[0],NULL,thrd_recv,(void*)0);
    while (1)
    {
        memset(buffer_out, 0, sizeof(buffer_out));
        //cout<<buffer_in<<endl;
        memset(&temp,0,sizeof(temp));
        cout<<"请输入成绩："<<endl;
        cin>>temp.gr;
        if (temp.gr<0)
        {
            cout<<"wrong grade"<<endl;
            continue;
        }
        cout<<"请输入学号(该栏若输入exit，则断开链接)："<<endl;
        cin>>temp.id;
        cout<<"请输入姓名："<<endl;
        cin>>temp.name;
        if (strcmp(temp.id,"exit")==0)
        {
            send(socket_fd,"exit",sizeof("exit"),0);
            break;
        }
        send(socket_fd,(char*)&temp,sizeof(student),0);
        
    }
    
    close(socket_fd);

    return 0;
}
