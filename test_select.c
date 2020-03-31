#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main()
{
  fd_set read_fds;//fd_set 是一个结构体数组
  FD_ZERO(&read_fds);//初始化全0
  FD_SET(0,&read_fds);//设置read_fds 中的 0号位即 stdin

  while(1)
  {
    printf(">");
    fflush(stdout);

    //监听一个，即read_fds的第一个----> 标准输入
    //                    stdin  stdout  stderr  timeval
    int ret = select(1, &read_fds, NULL, NULL, NULL);//timeout 设置为阻塞等待
    if(ret < 0)
    {
      perror("select");
      continue;
    }

    //监听成功
    

    // 判断read_fds中第一个fd  --->stdin是否为真
    if(FD_ISSET(0, &read_fds))
    {
      char buf [1024] = {0};
      read(0, buf, sizeof(buf) - 1);//为真 ，就从stdin中读取数据存到 buf中
      printf("input is : %s", buf);
    }
    else 
    {
      printf("error invalied fd \n");
      continue;
    }

    FD_ZERO(&read_fds);//清空fd_set 结构体数组
    FD_SET(0, &read_fds);
  }

  return 0;
}

