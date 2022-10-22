#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <shadow.h>
#include <crypt.h>
#include <sys/types.h>
#include <signal.h>

// check crt
#define CHK_SSL(err)                 \
    if ((err) < 1)                   \
    {                                \
        ERR_print_errors_fp(stderr); \
        exit(2);                     \
    }
#define CHK_ERR(err, s) \
    if ((err) == -1)    \
    {                   \
        perror(s);      \
        exit(1);        \
    }
#define PORT_NUMBER 55555
#define BUFF_SIZE 2000

struct vpnserver
{
    /* data */
};

// 当前会话空余id
int sessionID = 1;
int *psessionID = &sessionID;
struct sockaddr_in peerAddr;

// // setup TCP Server
int setupTCPServer();

// // 收到报文并以ssl发送
void processRequest(SSL *ssl, int sockfd);

// Create Tun Device
int createTunDevice();

// Init UDP Server
// int initUDPServer();

// Got a packet from TUN
void tunSelected(int tunfd, SSL *sockfd);

// Got a packet from the client tunnel
void socketSelected(int tunfd, SSL *sockfd);

int login(char *user, char *passwd)
{
    struct spwd *pw;
    char *epasswd;
    pw = getspnam(user);
    if (pw == NULL)
    {
        return 0;
    }
    printf("Login name: %s\n", pw->sp_namp);
    printf("Passwd : %s\n", pw->sp_pwdp);
    epasswd = crypt(passwd, pw->sp_pwdp);
    if (strcmp(epasswd, pw->sp_pwdp))
    {
        return -1;
    }
    return 1;
}

void newSession(int signum)
{
    // keep ID between 1 & 254
    sessionID %= 254;
    sessionID++;
}

int main(int argc, char *argv[])
{
    int tunfd, sockfd;

    tunfd = createTunDevice();
    system("ip addr add 192.168.78.100/24 dev tun0");
    system("ip link set dev tun0 up ");
    system("ip route add 192.168.53.0/24 dev tun0 via 192.168.78.100");

    SSL_METHOD *meth;
    SSL_CTX *ctx;
    SSL *ssl;
    int err;

    // Step 0: OpenSSL library initialization
    // This step is no longer needed as of version 1.1.0.
    SSL_library_init();
    SSL_load_error_strings();
    SSLeay_add_ssl_algorithms();

    struct sockaddr_in sa_client;
    size_t client_len;
    int listen_sock = setupTCPServer();

    // 端口复用
    int reuse = 1;
    if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0)
    {
        perror("setsockopet error\n");
        return -1;
    }
    // struct sockaddr servaddr;
    // if ((bind(listen_sock, (struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
    // {
    //     perror("bind error\n");
    //     return -1;
    // }

    // 建立SSL服务功能
    // Step 1: SSL context initialization
    meth = (SSL_METHOD *)TLSv1_2_method();
    ctx = SSL_CTX_new(meth);
    SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);
    // Step 2: Set up the server certificate and private key
    SSL_CTX_use_certificate_file(ctx, "./tls/cert_server/server.crt", SSL_FILETYPE_PEM);
    int passFlag = SSL_CTX_use_PrivateKey_file(ctx, "./tls/cert_server/server.key", SSL_FILETYPE_PEM);
    if (passFlag)
        printf("密码正确！\n");
    else
        printf("密码错误！\n");
    // Step 3: Create a new SSL structure for a connection
    ssl = SSL_new(ctx);

    // 为会话生成对应ID
    struct sigaction new_session;
    new_session.sa_flags = 0;
    new_session.sa_handler = newSession; //信号处理函数

    sigaction(SIGUSR1, &new_session, NULL);

    // SSL服务开启，等待客户端ssl连接
    while (1)
    {
        int sockfd = accept(listen_sock, (struct sockaddr_in *)&sa_client, &client_len);
        // 收到一个客户端的ssl请求，建立子进程
        if (fork() == 0)
        { // The child process
            close(listen_sock);
            // int reuse = 1;
            // if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0)
            // {
            //     perror("setsockopet error\n");
            //     return -1;
            // }
            SSL_set_fd(ssl, sockfd);
            int err = SSL_accept(ssl);
            CHK_SSL(err);
            printf("SSL connection established!\n");
            kill(getppid(), SIGUSR1);

            // TODO: 完成登录

            /*通过已连接的sockfd获取客户端的ip和port*/
            socklen_t addrLen;
            struct sockaddr_in cliAddr;
            char addr_client[INET_ADDRSTRLEN]; // INET_ADDRSTRLEN这个宏系统默认定义 16
            // int port = ntohs(sa_client.sin_port);
            addrLen = sizeof(cliAddr);
            if (-1 == getpeername(sockfd, (struct sockaddr *)&cliAddr, &addrLen))
            {
                return 1;
            }
            strncpy(addr_client, (const char *)inet_ntoa(cliAddr.sin_addr), 64);
            int port = (int)ntohs(cliAddr.sin_port);

            // Login in Part !!!
            int loginflag = 0;
            while (loginflag < 1)
            {
                fd_set readLOGIN;
                FD_ZERO(&readLOGIN);
                FD_SET(sockfd, &readLOGIN);
                select(FD_SETSIZE, &readLOGIN, NULL, NULL, NULL);
                if (FD_ISSET(sockfd, &readLOGIN))
                {
                    int len;
                    char buff[BUFF_SIZE];

                    printf("Server: Got the username&passwd from the client  %s : %d tunnel\n", addr_client, port);

                    bzero(buff, BUFF_SIZE);
                    // printf("reading...\n");
                    // len = recvfrom(sockfd, buff, BUFF_SIZE, 0, NULL, NULL);
                    len = SSL_read(ssl, buff, sizeof(buff) - 1);
                    if (len == 0)
                    {
                        printf("%s : %d 放弃登录...\n", addr_client, port);
                        SSL_shutdown(ssl);
                        SSL_free(ssl);
                        exit(0);
                    }
                    buff[len] = '\0';
                    printf("Received: Username: %s\tPassword: %s\n", buff, buff + 40);
                    loginflag = login(buff, buff + 40);
                    // loginflag = 1;
                    // printf("???%d\n", loginflag);
                    char answer[2];
                    bzero(answer, 2);
                    if (loginflag == 1)
                        answer[0] = sessionID;
                    SSL_write(ssl, answer, 2);
                }
            }

            printf("%s : %d 成功登录！当前会话ID：%d\n", addr_client, port, *psessionID);

            // 设置端口复用
            if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0)
            {
                perror("setsockopet error\n");
                return -1;
            }

            //开始监听
            while (1)
            {
                // printf("+++");
                fd_set readFDSet;

                FD_ZERO(&readFDSet);
                FD_SET(sockfd, &readFDSet);
                FD_SET(tunfd, &readFDSet);
                select(FD_SETSIZE, &readFDSet, NULL, NULL, NULL);

                if (FD_ISSET(tunfd, &readFDSet))
                {
                    tunSelected(tunfd, ssl);
                }
                if (FD_ISSET(sockfd, &readFDSet))
                    socketSelected(tunfd, ssl);
            }
            SSL_shutdown(ssl);
            SSL_free(ssl);
            close(sockfd);

            return 0;
        }
        else
        { // The parent process
            // printf("close parent!\n");
            close(sockfd);
        }
    }
}

int createTunDevice()
{
    int tunfd;
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));

    ifr.ifr_flags = IFF_TUN | IFF_NO_PI;

    tunfd = open("/dev/net/tun", O_RDWR);
    ioctl(tunfd, TUNSETIFF, &ifr);

    return tunfd;
}

void tunSelected(int tunfd, SSL *ssl)
{
    int len;
    char buff[BUFF_SIZE];

    printf("Server: Got a packet from TUN, send to sessionID: %d\n", *psessionID);

    bzero(buff, BUFF_SIZE);
    len = read(tunfd, buff, BUFF_SIZE);
    int src_C = buff[14], src_D = buff[15];
    int dst_C = buff[18], dst_D = buff[19];
    if (dst_C != 53)
    {
        return;
    }
    if (dst_D != sessionID)
    {
        write(tunfd, buff, len);
        return;
    }

    // u_char srcIP[4];
    // memcpy(srcIP, buff + 12, 4);
    // for (int i = 0; i < 40; ++i)
    //     printf("%d %d\n", i, buff[i]);
    sleep(0.01);
    // sendto(sockfd, buff, len, 0, (struct sockaddr *)&peerAddr, sizeof(peerAddr));
    SSL_write(ssl, buff, len);
}

void socketSelected(int tunfd, SSL *ssl)
{
    int len;
    char buff[BUFF_SIZE];

    printf("Server: Got a packet from tunnel, sessionID: %d\n", *psessionID);

    bzero(buff, BUFF_SIZE);
    // len = recvfrom(sockfd, buff, BUFF_SIZE, 0, NULL, NULL);
    len = SSL_read(ssl, buff, sizeof(buff) - 1);
    // printf("sock_len: %d", len);
    if (len == 0)
    {
        printf("检测到退出，会话ID：%d退出登录...\n", *psessionID);
        SSL_shutdown(ssl);
        SSL_free(ssl);
    }
    write(tunfd, buff, len);
}

int setupTCPServer()
{
    struct sockaddr_in sa_server;
    int listen_sock;

    listen_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    CHK_ERR(listen_sock, "socket");
    memset(&sa_server, '\0', sizeof(sa_server));
    sa_server.sin_family = AF_INET;
    sa_server.sin_addr.s_addr = INADDR_ANY;
    sa_server.sin_port = htons(4433);
    int err = bind(listen_sock, (struct sockaddr *)&sa_server, sizeof(sa_server));
    CHK_ERR(err, "bind");
    err = listen(listen_sock, 5);
    CHK_ERR(err, "listen");
    return listen_sock;
}