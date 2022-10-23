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

	//�ͻ�����������
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (INVALID_SOCKET == clifd)
	{
		err("accept");
	}
	//������ͻ���ͨ��


	char recvbuf[BUFSIZ] = { 0 };
	char sendbuf[BUFSIZ] = { 0 };
	printf("Client connected...\n");

	while (true)
	{
		//������Ϣ
		if (0 < recv(clifd, recvbuf, BUFSIZ, 0))
		{
			printf("recv:%s\n", recvbuf);
			memset(recvbuf, 0, sizeof(recvbuf));

		}


		//���ͻ��˷�����Ϣ
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
	//WSA   Windows�첽�׽���
	//parm1 �����Socket�汾
	//parm2 ��������
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
	//1  �����յ�Socket
	//af ��ַЭ����
	//type ����Э�����ͣ� ��ʽ�׽��� ���ݱ��׽���
	//protocol ʹ�õľ��崫��Э��
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET)
	{
		err("socket");
		return INVALID_SOCKET;
	}


	//2 �󶨶˿���ip��ַ
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.S_un.S_addr = ADDR_ANY;
	if (SOCKET_ERROR == bind(fd, (sockaddr*)&addr, sizeof(addr)))//SOCKET_ERROR == bind(fd, (sockaddr*)&addr, sizeof(addr))
	{
		err("bind");
		return false;
	}
	//����
	listen(fd, 10);

	return fd;

}