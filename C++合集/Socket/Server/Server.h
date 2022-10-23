#ifndef _SOCKETTCP_H_
#define _SOCKETTCP_H_
#include<WinSock2.h>  //Windows平台网络库头文件
#pragma comment(lib,"ws2_32.lib") //库文件
#include<stdbool.h>
#include<stdio.h>
#define PORT 8888 //端口号  >1024
#define err(errMsg) printf("[line:%d]%s failed code %d",__LINE__,errMsg,WSAGetLastError())

//打开网络库
bool init_Socket();
//关闭网络库
bool close_Socket();
//创建服务端
SOCKET CreateServerSocket();
#endif // ! _SOCKETTCP_H_#pragma once
