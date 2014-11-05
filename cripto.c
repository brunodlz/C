#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *criptografar(char *c, int n, int p);
char *descriptografar(char *c, int n, int p);

int main()
{
 char *texto;
 int posicao=0;

 printf("mensagem: ");
 scanf("%[^\n]%*c",texto);

 printf("posicao: ");
 scanf("%d",&posicao);

 char *cripto = criptografar(texto,strlen(texto),posicao);

 printf("\ntexto criptografado: \033[36m%s\033[0m", cripto);

 char *descrip = descriptografar(cripto,strlen(cripto),posicao);

 printf("\ntexto descriptografado: \033[36m%s\033[0m\n\n", descrip); 

 return 0;
}

char *criptografar(char *c, int n, int p)
{
 for(int i=0; i < n; i++)
 {
  c[i] = c[i] + p;
 }
 return c;
}

char *descriptografar(char *c, int n, int p)
{
 for(int i=0; i < n; i++)
 {
  c[i] = c[i] - p;
 }
 return c;
}
