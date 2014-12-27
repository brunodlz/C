#include <stdio.h>
#include <string.h>

int main()
{
 char string[5][20], aux[20];
 int x, y;

 for(x=0;x<5;x++)
 {
  printf("word: "); scanf("%s",string[x]);
 }

 for(x=1;x<5;x++)
 {
  for(y=1;y<5;y++)
  {
   if(strcmp(string[y - 1],string[y])>0)
   {
    strcpy(aux,string[y - 1]);
    strcpy(string[y - 1],string[y]);
    strcpy(string[y],aux);
   }
  }
 }

 printf("***************\n");

 for(x=0;x<5;x++)
 {
  printf("%s\n",string[x]);
 }

 return 0;
}
