#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
  int wfd = open("myfile",O_WRONLY);
  if(wfd < 0)
  {
    perror("open");
    exit(1);
  }

  char buff[1024];
  while(1)
  {
    buff[0] = 0;
    printf("please  Enter !\n");
    fflush(stdout);
    ssize_t s =read(0,buff,strlen(buff));//从键盘进行标准输入
    if(s > 0)
    {
      buff[s] = 0;
      write(wfd,buff,s);
    }
    else if(s <= 0)
    {
      perror("read");
      exit(1);
    }
  }
  close(wfd);
  return 0;
}
