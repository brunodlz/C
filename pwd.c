#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
 uid_t uid;
 struct passwd *pwd;

 uid = getuid();
 printf("user's UID is %d.\n",(int)uid);

 if(!(pwd=getpwuid(uid)))
 {
  printf("unable to get user's password file record!\n");
  endpwent();
  return 1;
 }

 printf("user's home directory is %s\n",pwd->pw_dir);
 endpwent();

 return 0;
}
