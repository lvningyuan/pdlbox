#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define ERR_EXIT(m)\
  do\
{\
  perror(m);\
  exit(EXIT_FAILURE);\
}while(0);
int main (int argc, char* argv[])
{
  int outfd = open("abc.bak",O_WRONLY  | O_CREAT | O_TRUNC,0666);//.bak为备份文件,CREAT 不存在就创建，存在该文件，O_TRUNC会将文件清零，
  if(outfd < 0)   //其实这里  目的就是创建一个空的 备份文件
    ERR_EXIT("open");

  int  infd = open("tp",O_RDONLY);//获取 tp管道的文件描述符
  if(infd < 0)
  {
    ERR_EXIT("open");
  }

  char buf[1024];//缓冲区
  int n;//读取计数

  while( (n=read(infd ,buf,1024)) > 0)
  {
    printf("%s\n",buf);
    write(outfd,buf,n);//读多少，写多少
  }

  close(infd);
  close(outfd);
  unlink("tp");//减少链接数，删除目录
  return 0;
}

