#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
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
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	int i=0,b;
	char ch;
	char a[30]={0};
	printf("please input IP Address:");
	while((ch=getchar())!='\n')
	{
	   a[i]=ch;
	   i++;
	}
	printf("please input Port:");
	scanf("%d",&b);
	
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(a);
	serv_addr.sin_port = htons(b);
	
	
	connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	
	//char buffer[40];
	
	student stu1,stu2,stu3;
	sstudent ss;
	while(1)
	{
	   printf("Please write three Students name,id and grade:");
	   scanf("%s", stu1.name);
	   scanf("%s", stu1.id);
	   scanf("%f",&stu1.gr);
	   scanf("%s", stu2.name);
	   scanf("%s", stu2.id);
	   scanf("%f",&stu2.gr);
	   scanf("%s", stu3.name);
	   scanf("%s", stu3.id);
	   scanf("%f",&stu3.gr);
	   send(sock,(char*)&stu1,sizeof(student),0);
	   send(sock,(char*)&stu2,sizeof(student),0);
	   send(sock,(char*)&stu3,sizeof(student),0);
	   recv(sock,(char*)&ss,sizeof(sstudent),0);
	   printf("This three students' average grade:\n");
	   printf("%s\n",ss.id1);
	   printf("%s\n",ss.id2);
	   printf("%s\n",ss.id3);
	   printf("%f\n",ss.av);
	}
	/*while(1)
	{
	  printf("Please write:");
	  scanf("%s", name);
	  scanf("%s", id);
	  scanf("%f",&f);
	  write(sock, name, sizeof(name));
	  write(sock, id, sizeof(id));
	  
	  
	}*/
	
	close(sock);

	return 0;
}


