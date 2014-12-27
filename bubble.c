/*
                        .      .
               ./       |      |        \.
             .:(        |i __ j|        ):`.
           .'   `._     |`::::'|     _.'    `.
         .'        "---.j `::' f.---"         `.
   _____/     ___  ______      __    __   ___   \_   __
  |      \   |   ||      |`__'|  \  /  | |   | |" \ |  |
  |  .-.  | .'   `|_    _|\--/|   \/   |.'   `.|   \|  |
  |  |_|  | |  i  | |  |  :"":|        ||  i  ||    |  |
  |       / | .^. | |  |  ::::|        || .^. ||       |
  |  .-.  \ | | | | |  |   :: |        || | | ||  |\   |
  |  | |  |.' """ `.|  |      |  i  i  j' """ `.  | \  | 
  |  `-'  ||   _   ||  |      |  |\/|  |   _   |  | [  |
 [|      / |  | |  ||  |      |  |  |  |  | |  |  | |  |].
 ] `-----'  :--' `--::--'      `--' ::--"--::`--"--' `--':[
 |      __  ::-"""`.:' "--.    .----::.----:: ,.---._    :|
 [  .-""  "`'              \  /      "      `'       `-. :].
 ]:.'                        \/                          `.:[
 |/                                                        \|

 by brn0s

 compiler: gcc -o bubble bubble.c; ./bubble

*/

#include <stdio.h>
#include <stdlib.h>

void *banner(int arg);

int main(int argc, char *argv[])
{
 int numbers[10],swap;
 int i,j;

 banner(argc);

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

 printf("\n");

 for(i=0;i<10;i++)
 {
  printf("number: %d\n",numbers[i]);
 }

 return 0;
}

void *banner(int arg)
{
 if(arg>=2)
 {
  puts("*******************************************");
  puts("*************** Bubble Sort ***************");
  puts("*******************************************");
 }
}
