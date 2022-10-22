// vpnclient.c
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>

#define CHK_SSL(err)                 \
    if ((err) < 1)                   \
    {                                \
        ERR_print_errors_fp(stderr); \
        exit(2);                     \
    }
#define CA_DIR "./tls/ca_client"
#define BUFF_SIZE 2000
#define PORT_NUMBER 55555
#define SERVER_IP "10.0.2.2"
struct sockaddr_in peerAddr;

// int a -> char* str
// return str
char *Int2String(int num, char *str);

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

int connectToUDPServer()
{
    int sockfd;
    char *hello = "Hello";

    memset(&peerAddr, 0, sizeof(peerAddr));
    peerAddr.sin_family = AF_INET;
    peerAddr.sin_port = htons(PORT_NUMBER);
    peerAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Send a hello message to "connect" with the VPN server
    sendto(sockfd, hello, strlen(hello), 0,
           (struct sockaddr *)&peerAddr, sizeof(peerAddr));

    return sockfd;
}

int verify_callback(int preverify_ok, X509_STORE_CTX *x509_ctx)
{
    char buf[300];

    X509 *cert = X509_STORE_CTX_get_current_cert(x509_ctx);
    X509_NAME_oneline(X509_get_subject_name(cert), buf, 300);
    printf("subject= %s\n", buf);

    if (preverify_ok == 1)
    {
        printf("Verification passed.\n");
    }
    else
    {
        int err = X509_STORE_CTX_get_error(x509_ctx);
        printf("Verification failed: %s.\n",
               X509_verify_cert_error_string(err));
    }
}

SSL *setupTLSClient(const char *hostname)
{
    // Step 0: OpenSSL library initialization
    // This step is no longer needed as of version 1.1.0.
    SSL_library_init();
    SSL_load_error_strings();
    SSLeay_add_ssl_algorithms();

    SSL_METHOD *meth;
    SSL_CTX *ctx;
    SSL *ssl;

    meth = (SSL_METHOD *)TLSv1_2_method();
    ctx = SSL_CTX_new(meth);

    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);
    if (SSL_CTX_load_verify_locations(ctx, NULL, CA_DIR) < 1)
    {
        printf("Error setting the verify locations. \n");
        exit(0);
    }
    ssl = SSL_new(ctx);

    X509_VERIFY_PARAM *vpm = SSL_get0_param(ssl);
    X509_VERIFY_PARAM_set1_host(vpm, hostname, 0);

    return ssl;
}

int setupTCPClient(const char *hostname, int port)
{
    struct sockaddr_in server_addr;

    // Get the IP address from hostname
    struct hostent *hp = gethostbyname(hostname);

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Fill in the destination information (IP, port #, and family)
    memset(&server_addr, '\0', sizeof(server_addr));
    memcpy(&(server_addr.sin_addr.s_addr), hp->h_addr, hp->h_length);
    //   server_addr.sin_addr.s_addr = inet_addr ("10.0.2.14");
    server_addr.sin_port = htons(port);
    server_addr.sin_family = AF_INET;

    // Connect to the destination
    connect(sockfd, (struct sockaddr *)&server_addr,
            sizeof(server_addr));

    return sockfd;
}

void tunSelected(int tunfd, SSL *ssl)
{
    int len;
    char buff[BUFF_SIZE];

    printf("Client: Got a packet from TUN\n");

    bzero(buff, BUFF_SIZE);
    len = read(tunfd, buff, BUFF_SIZE);
    // sendto(sockfd, buff, len, 0, (struct sockaddr *)&peerAddr, sizeof(peerAddr));
    SSL_write(ssl, buff, len);
}

void socketSelected(int tunfd, SSL *ssl)
{
    int len;
    char buff[BUFF_SIZE];

    printf("Client: Got a packet from the server tunnel\n");

    bzero(buff, BUFF_SIZE);
    // len = recvfrom(sockfd, buff, BUFF_SIZE, 0, NULL, NULL);
    len = SSL_read(ssl, buff, sizeof(buff) - 1);
    if (len == 0)
    {
        printf("检测到服务器关闭，强制结束！\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
    }
    write(tunfd, buff, len);
}

int main(int argc, char *argv[])
{
    int tunfd, sockfd;

    // 模拟DNS域名解析
    // system("cp /etc/hosts.bak /etc/hosts");
    system("echo \"10.0.2.2 www.sun2022.com\" >> /etc/hosts");

    char *hostname = "yahoo.com";
    int port = 443;

    if (argc > 1)
        hostname = argv[1];
    if (argc > 2)
        port = atoi(argv[2]);
    printf("%s\n", hostname);

    /*----------------TLS initialization ----------------*/
    SSL *ssl = setupTLSClient(hostname);
    printf("abc");

    /*----------------Create a TCP connection ---------------*/
    sockfd = setupTCPClient(hostname, port);
    printf("abc");

    /*----------------TLS handshake ---------------------*/
    SSL_set_fd(ssl, sockfd);
    // printf("***");
    int err = SSL_connect(ssl);
    printf("Checking CRT!!!\n");
    CHK_SSL(err);
    // printf("!!!");
    printf("SSL connection is successful\n");
    printf("SSL connection using %s\n", SSL_get_cipher(ssl));
    // printf("abc");

    // TODO: 完成登录
    char username[32];
    char *passwd;

    bzero(username, 32); // memset(username, 0, 32);
    // bzero(passwd, 256);  // memset(passwd, 0, 256);
    int loginID = 0;
    while (loginID == 0)
    {
        printf("请输入VPN服务器用户名：");
        scanf("%s", username);
        int name_len = strlen(username);
        // printf("\n请输入密码：");
        // scanf("%s", passwd);
        passwd = getpass("\n请输入密码：");
        int passwd_len = strlen(passwd);
        char loginBUFF[300];
        memset(loginBUFF, 0, 300);
        strcpy(loginBUFF, username);
        strcpy(loginBUFF + 40, passwd);
        printf("Username: %s\tPassword: %s\t", loginBUFF, loginBUFF + 40);

        SSL_write(ssl, loginBUFF, 300);
        fd_set readFDSet;
        FD_ZERO(&readFDSet);
        FD_SET(sockfd, &readFDSet);
        select(FD_SETSIZE, &readFDSet, NULL, NULL, NULL);
        if (FD_ISSET(sockfd, &readFDSet))
        {
            int len;
            char buff[BUFF_SIZE];

            // printf("Server: Got the username&passwd from the server tunnel\n");
            bzero(buff, BUFF_SIZE);
            // printf("reading...\n");
            // len = recvfrom(sockfd, buff, BUFF_SIZE, 0, NULL, NULL);
            len = SSL_read(ssl, buff, sizeof(buff) - 1);
            buff[len] = '\0';
            // printf("Received: Answer:\t%s\n", buff);
            loginID = buff[0];
            if (loginID == 0)
            {
                printf("登录失败...\n");
            }
            else
            {
                printf("登录成功！\n");
            }
        }
    }
    // create TUN device
    tunfd = createTunDevice();
    // printf("&*&*登录成功！\n");
    char hostID[4] = {0};
    Int2String(loginID, hostID);
    // printf("&*&*！！登录成功！\n");

    char netID[20] = "192.168.53.";
    // printf("&*dsfghs&*登录成功！\n");
    strcat(netID, hostID);
    printf("当前端口：%s\n", netID);

    char cmd1[40] = "ip addr add ";
    strcat(cmd1, netID);
    strcat(cmd1, "/24 dev tun0");
    system(cmd1);
    system("ip link set dev tun0 up ");
    char cmd2[60] = "ip route add 192.168.60.0/24 dev tun0 via ";
    strcat(cmd2, netID);
    system(cmd2);
    char cmd3[60] = "ip route add 192.168.78.0/24 dev tun0 via ";
    strcat(cmd3, netID);
    system(cmd3);
    // Enter the main loop
    while (1)
    {
        fd_set readFDSet;

        FD_ZERO(&readFDSet);
        FD_SET(sockfd, &readFDSet);
        FD_SET(tunfd, &readFDSet);
        select(FD_SETSIZE, &readFDSet, NULL, NULL, NULL);

        if (FD_ISSET(tunfd, &readFDSet))
            tunSelected(tunfd, ssl);
        if (FD_ISSET(sockfd, &readFDSet))
            socketSelected(tunfd, ssl);
    }
}

char *Int2String(int num, char *str) // 10进制
{
    int i = 0;   //指示填充str
    if (num < 0) //如果num为负数，将num变正
    {
        num = -num;
        str[i++] = '-';
    }
    //转换
    do
    {
        str[i++] = num % 10 + 48; //取num最低位 字符0~9的ASCII码是48~57；简单来说数字0+48=48，ASCII码对应字符'0'
        num /= 10;                //去掉最低位
    } while (num);                // num不为0继续循环

    str[i] = '\0';

    //确定开始调整的位置
    int j = 0;
    if (str[0] == '-') //如果有负号，负号不用调整
    {
        j = 1; //从第二位开始调整
        ++i;   //由于有负号，所以交换的对称轴也要后移1位
    }
    //对称交换
    for (; j < i / 2; j++)
    {
        //对称交换两端的值 其实就是省下中间变量交换a+b的值：a=a+b;b=a-b;a=a-b;
        str[j] = str[j] + str[i - 1 - j];
        str[i - 1 - j] = str[j] - str[i - 1 - j];
        str[j] = str[j] - str[i - 1 - j];
    }

    return str; //返回转换后的值
}