#ifndef _SOCKETTCP_H_
#define _SOCKETTCP_H_
#include<WinSock2.h>  //Windowsƽ̨�����ͷ�ļ�
#pragma comment(lib,"ws2_32.lib") //���ļ�
#include<stdbool.h>
#include<stdio.h>
#define PORT 8888 //�˿ں�  >1024
#define err(errMsg) printf("[line:%d]%s failed code %d",__LINE__,errMsg,WSAGetLastError())

//�������
bool init_Socket();
//�ر������
bool close_Socket();
//���������
SOCKET CreateServerSocket();
#endif // ! _SOCKETTCP_H_#pragma once
