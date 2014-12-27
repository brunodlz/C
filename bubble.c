#include <stdio.h>

int main()
{
 int numbers[10],swap;
 int i,j;

 for(i=0;i<10;i++)
 {
  printf("number: "); scanf("%d",&numbers[i]);
 }

 for(i=1;i<10;i++)
 {
  for(j=0;j<10-1;j++)
  {
   if(numbers[j]>numbers[j+1])
   {
    swap = numbers[j];
    numbers[j] = numbers[j+1];
    numbers[j+1] = swap;
   }
  }
 }

 printf("*****************\n");

 for(i=0;i<10;i++)
 {
  printf("number: %d\n",numbers[i]);
 }

 return 0;
}
