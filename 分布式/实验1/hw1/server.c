#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
typedef struct Student
{
    char name[40];
    char id[40];
    float gr;
}student;
typedef struct SStudent
{
    char id1[40];
    char id2[40];
    char id3[40];
    float av;
}sstudent;
int main(){
	
	int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.2");
	serv_addr.sin_port = htons(1234);

	
	bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	
	listen(serv_sock, 20);
	printf("IP:127.0.0.2   Port:1234 \n");
	
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	
	student stu1,stu2,stu3;
	sstudent ss;
	char str[1024];
	float f;
	while(1)
	{
	   recv(clnt_sock,(char*)&stu1,sizeof(student),0);
	   recv(clnt_sock,(char*)&stu2,sizeof(student),0);
	   recv(clnt_sock,(char*)&stu3,sizeof(student),0);
	   f=(stu1.gr+stu2.gr+stu3.gr)/3;
	   printf("average grade: %f\n",f);
	   int i;
	   for(i=0;i<sizeof(stu1.id);i++)
	   {
	       ss.id1[i]=stu1.id[i];
	   }
	   for(i=0;i<sizeof(stu2.id);i++)
	   {
	       ss.id2[i]=stu2.id[i];
	   }
	   for(i=0;i<sizeof(stu3.id);i++)
	   {
	       ss.id3[i]=stu3.id[i];
	   }  
	   ss.av=f;
	   send(clnt_sock,(char*)&ss,sizeof(sstudent),0);
	}
	//char str[1024],str1[24];
	/*char name1[40],name2[40],name3[40];
	char ID1[40],ID2[40],ID3[40];
	float f1,f2,f3;
	while(1)
	{
	   read(clnt_sock, name1, sizeof(name1));
	   read(clnt_sock, ID1, sizeof(ID1));
	   read(clnt_sock, name1, sizeof(name1));
	   printf("client send: %s\n",str);
	    if(str[0]=='e'&&str[1]=='n'&&str[2]=='d')
	       break;
	}*/
	
	/*while(1)
	{  
	   read(clnt_sock, str1, sizeof(str1));
	   recv(str,(char*)&stu,sizeof(stu),0);
	    printf("client send: %s\n",stu.name);
	     printf("%s\n",stu.id);
	     printf("%f\n",stu.gr);
	}*/
	close(clnt_sock);
	close(serv_sock);

	return 0;
}


