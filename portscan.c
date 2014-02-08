/*
 
              ,   .-'"'=;_  , 
              |\.'-~`-.`-`;/|
              \.` '.'~-.` './
              (\`,__=-'__,'/)    WAZZAAAAAAAAP!
           _.-'-.( d\_/b ).-'-._
         /'.-'   ' .---. '   '-.`\
       /'  .' (=    (_)    =) '.  `\
      /'  .',  `-.__.-.__.-'  ,'.  `\
     (     .'.   V       V  ; '.     )
     (    |::  `-,__.-.__,-'  ::|    )
     |   /|`:.               .:'|\   |
     |  / | `:.              :' |`\  |
     | |  (  :.             .:  )  | |
     | |   ( `:.            :' )   | |
     | |    \ :.           .: /    | |
     | |     \`:.         .:'/     | |
     ) (      `\`:.     .:'/'      ) (
     (  `)_     ) `:._.:' (     _(`  )
     \  ' _)  .'           `.  (_ `  /
      \  '_) /   .'"```"'.   \ (_`  /
       `'"`  \  (         )  /  `"'`
   ___        `.`.       .'.'        ___
 .`   ``"""'''--`_)     (_'--'''"""``   `.
(_(_(___...--'"'`         `'"'--...___)_)_)

 by d3lf0

 compiler: gcc -o portscan portscan.c; ./portscan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/signal.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

void *banner(int arg);

main(int argc, char *argv[]) {
 int mysock;
 int begin, end, port;
 struct sockaddr_in vitim;
 struct hostent *host;
 struct servent *service;

 banner(argc);

 begin=atoi(argv[2]);
 end=atoi(argv[3]);

 for(port=begin;port<end;port++) {

  host = gethostbyname(argv[1]);
  if(host==NULL) {
   puts("Error: host unknown!!");
   exit(-1);
  }

  if(mysock=socket(AF_INET,SOCK_STREAM,0)<0) { 
   perror("Socket");
   exit(1);
  }
  vitim.sin_family = host->h_addrtype;
  vitim.sin_port = htons(port);
  vitim.sin_addr = *((struct in_addr *)host->h_addr);
  bzero(&(vitim.sin_zero),8);

  if(connect(mysock,(struct sockaddr *)&vitim, sizeof(vitim))<0) {
    close(mysock);
   } else {
    service = getservbyport(htons(port),"tcp");
    printf("port: \033[36m%d\033[0m -- service:\033[36m %s\033[0m\n", port, service->s_name);
    close(mysock);
   }
  }
}

void *banner(int arg) {
 if(arg>=2) {
  puts("****************************************");
  puts("*************** PortScan ***************");
  puts("****************************************");
 } else {
  puts("<ip_vitim> <port_begin> <port_end>");
  exit(1);
 }
}
