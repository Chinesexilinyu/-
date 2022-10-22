#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

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

	
	char str[256];
	while(1)
	{
	   read(clnt_sock, str, sizeof(str));
	   printf("client send: %s\n",str);
	   if(str[0]=='e'&&str[1]=='n'&&str[2]=='d')
	       break;
	}
	
	close(clnt_sock);
	close(serv_sock);

	return 0;
}


