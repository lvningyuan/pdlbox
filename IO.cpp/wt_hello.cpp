#include <stdio.h>
#include <string.h>
//#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int  main()
{

  umask(0);//将文件的默认权限置为0

  int fd  = open("myfile",O_WRONLY | O_CREAT ,0644);//创建一个myfile 文件 ，同时赋予权限  ，得到一个对应的文件描述符
  if(fd < 0)
  {
    perror("open");
    return 1;
  }
  else 
  {
    int count =5;//循环5次康康
    const char* msg = "hello JJ !\n";//这里放上\n可以zai  write 的时候 自动换行
    int len =strlen(msg);
    while(count--)
    {
     int n = write(fd,msg,len);//fd  文件描述符，  len 每次 期望  读取多少个字节，返回值为实际每次读取的字节数
    printf("  读取了%d 字节\n",n);
    fflush(stdout);
    }
  }

  close(fd);
  return 0;
}
