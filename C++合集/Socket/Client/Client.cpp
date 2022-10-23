#include"Client.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{

	init_Socket();
	SOCKET fd = CreateClientSocket("127.0.0.1");
	printf("Server connected...\n");
	printf("tip:Enter 'end' to end the connection\n");

	//������Ϣ
	char recvbuf[BUFSIZ] = { 0 };
	char sendbuf[BUFSIZ] = { 0 };
	char endbuf[BUFSIZ] = { "end" };
	while (true)
	{
		//������Ϣ
		printf("send>");
		gets_s(sendbuf, BUFSIZ);

		//����'end'�Ͽ�����
		if (strcmp(sendbuf, endbuf) == 0)
		{
			return false;
		}
		if (SOCKET_ERROR == send(fd, sendbuf, strlen(sendbuf), 0))
		{
			err("send");
		}

		//������Ϣ
		if (0 < recv(fd, recvbuf, BUFSIZ, 0))
		{

			printf("recv:%s\n", recvbuf);
			memset(recvbuf, 0, sizeof(recvbuf));

		}


	}



	closesocket(fd);
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





SOCKET CreateClientSocket(const char* ip)
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


	//2 ���������������
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.S_un.S_addr = inet_addr(ip);
	if (INVALID_SOCKET == connect(fd, (struct sockaddr*)&addr, sizeof(addr)))
	{
		err("connect");
		return false;
	}

	return fd;

}
