#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
  int fd = open("myfile",O_RDONLY);
  if(fd < 0)
  {
    perror("open");
    return 1;
  }

  const char* msg = "hello  JJ !\n";
  char buff[1024];

  //int count =5;
  while(1)
  {
    ssize_t s =read(fd ,buff,strlen(msg));//给 buff 数组   缓冲区中读
    if(s > 0)//读到就输出
    {
      printf("%s",buff);
    }
    else 
    {
      break;
    }
  }
  close(fd);
  return 0;
}
