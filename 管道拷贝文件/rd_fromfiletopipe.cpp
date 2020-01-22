
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define ERR_EXIT(m)\
  do\
{\
  perror(m);\
  exit(EXIT_FAILURE);\
}while(0)



//读文件 ，写入命名管道
int main (int argc, char* argv[])
{
  //在程序中  创建一个   命名管道  tp;
  mkfifo("tp",0644);
  int infd;
  infd =open("abc",O_RDONLY);//创建一个文件描述符 + abc文件 ，仅读

  printf("tp pipe 1\n");
    if(infd < 0)//创建失败
    ERR_EXIT("open");//打印错误码，
  //否则，创建成功

  printf("topipe 2\n");
  int outfd = open("tp",O_WRONLY);//open  file  by tp 文件描述符outfd ，仅写
   printf("  3333");
  if(outfd  < 0) 
    ERR_EXIT("open");
  
  printf("to pipe 3\n");
  char buf[1024];
  int n;
  printf("核心写入管道开始\n");
  while((n =read(infd, buf, 1024)) > 0)
  {
    printf("写入管道\n");
    write(outfd,buf,n);//读多少，写多少 //写入命名管道 fd
  }

  close(infd);//写入数组之后 ，及时关闭读文件描述符
  close(outfd);//写完成 ，及时关闭写文件描述符
  return 0;
}
