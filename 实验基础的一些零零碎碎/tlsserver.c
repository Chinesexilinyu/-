#include <arpa/inet.h>
#include <fcntl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <shadow.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <crypt.h>

#define BUFF_SIZE 2000
//#define DEBUG

#define CHK_SSL(err) if ((err) < 1) { ERR_print_errors_fp(stderr); exit(2); }
#define CHK_ERR(err,s) if ((err)==-1) { perror(s); exit(1); }
void endRequest(SSL *ssl);
int  setupTCPServer();                   // Defined in Listing 19.10
void processRequest(SSL* ssl, int sock); // Defined in Listing 19.12
int LoginVerify(SSL *ssl);
int main(){

  SSL_METHOD *meth;
  SSL_CTX* ctx;
  SSL *ssl;
  int err;

  // Step 0: OpenSSL library initialization 
  // This step is no longer needed as of version 1.1.0.
  SSL_library_init();
  SSL_load_error_strings();
  SSLeay_add_ssl_algorithms();

  // Step 1: SSL context initialization
  meth = (SSL_METHOD *)TLSv1_2_method();
  ctx = SSL_CTX_new(meth);
  SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);
  // Step 2: Set up the server certificate and private key
  SSL_CTX_use_certificate_file(ctx, "./cert_server/server.crt", SSL_FILETYPE_PEM);
  SSL_CTX_use_PrivateKey_file(ctx, "./cert_server/server.key", SSL_FILETYPE_PEM);
  // Step 3: Create a new SSL structure for a connection
  ssl = SSL_new (ctx);
  
  
  printf("%d: Handshake\n", getpid());
          //CHK_SSL(err);
  if (LoginVerify(ssl) != 1){ 
  printf("%d: Login Fail！\n", getpid());
  endRequest(ssl);
  return 0;
  }
  printf("%d: Login success!\n", getpid());
  struct sockaddr_in sa_client;
  size_t client_len;
  int listen_sock = setupTCPServer();

  while(1){
    int sock = accept(listen_sock, (struct sockaddr*)&sa_client, &client_len);
    if (fork() == 0) { // The child process
       close (listen_sock);

       SSL_set_fd (ssl, sock);
       int err = SSL_accept (ssl);
       CHK_SSL(err);
       printf ("SSL connection established!\n");

       processRequest(ssl, sock);
       close(sock);
       return 0;
    } else { // The parent process
        close(sock);
    }
  }
}
void endRequest(SSL *ssl) {
  if (ssl != NULL) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
  }
}

int setupTCPServer()
{
    struct sockaddr_in sa_server;
    int listen_sock;

    listen_sock= socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    CHK_ERR(listen_sock, "socket");
    memset (&sa_server, '\0', sizeof(sa_server));
    sa_server.sin_family      = AF_INET;
    sa_server.sin_addr.s_addr = INADDR_ANY;
    sa_server.sin_port        = htons (4433);
    int err = bind(listen_sock, (struct sockaddr*)&sa_server, sizeof(sa_server));
    CHK_ERR(err, "bind");
    err = listen(listen_sock, 5);
    CHK_ERR(err, "listen");
    return listen_sock;
}

void processRequest(SSL* ssl, int sock)
{
    char buf[1024];
    int len = SSL_read (ssl, buf, sizeof(buf) - 1);
    buf[len] = '\0';
    printf("Received: %s\n",buf);

    // Construct and send the HTML page
    char *html =
	"HTTP/1.1 200 OK\r\n"
	"Content-Type: text/html\r\n\r\n"
	"<!DOCTYPE html><html>"
	"<head><title>Hello World</title></head>"
	"<style>body {background-color: black}"
	"h1 {font-size:3cm; text-align: center; color: white;"
	"text-shadow: 0 0 3mm yellow}</style></head>"
	"<body><h1>Hello, world!</h1></body></html>";
    SSL_write(ssl, html, strlen(html));
    SSL_shutdown(ssl);  SSL_free(ssl);
}
int LoginVerify(SSL *ssl) {
  char *input;
  char username[100];
  char password[1000];
  char request[BUFF_SIZE];

    // if not clear, the string would be weird
  memset(&username, 0, sizeof(username));
  memset(&password, 0, sizeof(password));
  memset(&request, 0, BUFF_SIZE);


  int len = SSL_read(ssl,request,BUFF_SIZE-1);
  request[len] = '\0';

  // username
  input = strtok(request, " ");
  if (!input) {
    printf("Invalid username\n");
    return -1;
  }
  strcpy(username, input);
  
  // password
  input = strtok(NULL, " ");
  if (!input) {
    printf("Invalid password\n");
    return -1;
  }
  strcpy(password, input);

  // check the shadow
  struct spwd *pw;
  char *epasswd;
  pw = getspnam(username);
  if (pw == NULL) {
    printf("Invalid account\n");
    return -1;
  }
  char*success= "login success!";
  // return the result
  /*epasswd = crypt(password, pw->sp_pwdp);
  char*fail = "login fail!";
  char*success= "login success!";
  if (strcmp(epasswd, pw->sp_pwdp)) {
    printf("Username and password do not match\n");
    SSL_write(ssl, fail, strlen(fail));
    return -1;
  }*/
  SSL_write(ssl, success, strlen(success));
  return 1;
}



