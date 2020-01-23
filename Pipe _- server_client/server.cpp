#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  printf("ok  ！\n");
  umask(0);

  if(mkfifo("mypipe",0644) < 0)
  {
    perror("mkfifo");
    exit(1);
  }
  printf("ok !\n");

  int rfd = open("mypipe",O_RDONLY);
  printf("ok !\n");
  
  if(rfd < 0)
  {
    perror("open");
    exit(1);
  }
  printf("  ok\n");
  char buff[1024]; 

  while(1)
  {
    buff[0] = 0;
    printf("please  wait...\n");

    ssize_t s= read(rfd,buff,sizeof(buff)-1);//读了   S字街
    sleep(1);
    if(s > 0)
    {
      buff[s]= '\0'; 
      printf("client says %s :\n",buff);
      
    }
    else if(s == 0)
    {
      printf("client  quit ,exit now !\n");
      exit(0);
    }
    else
    {
      perror("read error \n");
      exit(1);
    }
  }
  close(rfd);
  return 0;
}
