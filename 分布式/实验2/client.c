#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>
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
int main(int argc,char *argv[])
{
	int sockfd;
	int confd;
	struct hostent *he;	
	struct sockaddr_in addr_ser;	 
	struct sockaddr_in addr_file;	 
	
	if(argc!=3){	
		perror("Please input the server port!\n");
		exit(1);
	}
	he=gethostbyname((char *)argv[1]);	 
	if(he==NULL){	
		perror("Cannot get host by name!\n");
		exit(1);
	} 
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);	
	if(sockfd==-1){	
		perror("Create socketfd failed!\n");
		exit(1);
	}
		
	memset(&addr_ser,0,sizeof(addr_ser));
	addr_ser.sin_family = AF_INET;
	addr_ser.sin_port = htons((unsigned short)atoi(argv[2]));
	addr_ser.sin_addr = *((struct in_addr *) he->h_addr);
		
	confd = connect(sockfd, (struct sockaddr *)&addr_ser, sizeof(addr_ser));	 
	if(confd == -1){	 
		perror("Connectfd error!\n");
		exit(1);
	}
	student stu1,stu2,stu3;
	sstudent ss;
	while(1){	 		
		printf("--------------------------------------------------\n");
		printf("Please write three Students name,id and grade:");
		scanf("%s", stu1.name);
	        scanf("%s", stu1.id);
	        scanf("%f",&stu1.gr);
	        send(sockfd,(char*)&stu1,sizeof(student),0);
	        scanf("%s", stu2.name);
	        scanf("%s", stu2.id);
	        scanf("%f",&stu2.gr);
	        while(strcmp(stu1.id,stu2.id)==0)
	        {
	            printf("You have entered a duplicate ID, please re-enter:");
	            scanf("%s", stu2.name);
	            scanf("%s", stu2.id);
	            scanf("%f",&stu2.gr);
	        }
	        send(sockfd,(char*)&stu2,sizeof(student),0);
	        scanf("%s", stu3.name);
	        scanf("%s", stu3.id);
	        scanf("%f",&stu3.gr);
	        while((strcmp(stu1.id,stu3.id)==0)||(strcmp(stu3.id,stu2.id)==0))
	        {
	             printf("You have entered a duplicate ID, please re-enter:");
	             scanf("%s", stu3.name);
	             scanf("%s", stu3.id);
	             scanf("%f",&stu3.gr);
	        }
	        send(sockfd,(char*)&stu3,sizeof(student),0);
	        recv(sockfd,(char*)&ss,sizeof(sstudent),0);
		printf("Receive from server,this three students' average grade:\n");
	        printf("%f\n",ss.av);
	        printf("this three students' id:%s\n",ss.id[0]);
	        printf("%s\n",ss.id[1]);
	        printf("%s\n",ss.id[2]);
		fflush(stdout);
		}
	close(sockfd);
	return 0; 
}

