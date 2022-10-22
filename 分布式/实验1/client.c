#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

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
	
	char buffer[40];
	while(1)
	{
	  printf("Please write:");
	  scanf("%s", buffer);
	  write(sock, buffer, sizeof(buffer));
	  if(buffer[0]=='e'&&buffer[1]=='n'&&buffer[2]=='d')
	      break;
	}
	
	close(sock);

	return 0;
}


