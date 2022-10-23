#include"Server.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{

	init_Socket();
	SOCKET serfd = CreateServerSocket();

Sign:printf("IP:127.0.0.1\n");
	printf("Listening port:%d \n", PORT);
	printf("wait Client connect...\n");

	//客户端请求连接
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (INVALID_SOCKET == clifd)
	{
		err("accept");
	}
	//可以与客户端通信


	char recvbuf[BUFSIZ] = { 0 };
	char sendbuf[BUFSIZ] = { 0 };
	printf("Client connected...\n");

	while (true)
	{
		//接收消息
		if (0 < recv(clifd, recvbuf, BUFSIZ, 0))
		{
			printf("recv:%s\n", recvbuf);
			memset(recvbuf, 0, sizeof(recvbuf));

		}


		//给客户端发送消息
		printf("send>");
		gets_s(sendbuf, BUFSIZ);



		if (SOCKET_ERROR == send(clifd, sendbuf, strlen(sendbuf), 0))
		{
			err("send");
			printf("\n");
			printf("Client disconnected\n");
			goto Sign;
		}

		if (INVALID_SOCKET == clifd)
		{
			err("accept");
			return false;
		}


	}
	closesocket(clifd);
	closesocket(serfd);
	close_Socket();
	system("pause");

	return 0;

}




bool init_Socket()
{
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		printf("WSAStartup failed code %d", WSAGetLastError());
		return false;
	}
	//WSA   Windows异步套接字
	//parm1 请求的Socket版本
	//parm2 传出参数
	return true;
}

bool close_Socket()
{
	if (0 != WSACleanup())
	{
		printf("WSACleanup failed code %d", WSAGetLastError());
		return false;
	}
	return true;
}





SOCKET CreateServerSocket()
{
	//1  创建空的Socket
	//af 地址协议族
	//type 传输协议类型： 流式套接字 数据报套接字
	//protocol 使用的具体传输协议
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET)
	{
		err("socket");
		return INVALID_SOCKET;
	}


	//2 绑定端口与ip地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.S_un.S_addr = ADDR_ANY;
	if (SOCKET_ERROR == bind(fd, (sockaddr*)&addr, sizeof(addr)))//SOCKET_ERROR == bind(fd, (sockaddr*)&addr, sizeof(addr))
	{
		err("bind");
		return false;
	}
	//监听
	listen(fd, 10);

	return fd;

}