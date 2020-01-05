#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
int main()
{
//创建服务器
  int sock =socket(AF_INET,SOCK_DGRAM,0);
  if(sock<0)
  {
    perror("socket");
    return -1;
  }


//2 sock 绑定端口号 

  sockaddr_in addr; 
  addr.sin_family=AF_INET;
  addr.sin_port=htons(9090);//端口号   //主机序转为网络字节序
  addr.sin_addr.s_addr=inet_addr("0");//本机地址
//ip  地址也是一个整数，但 inet_addr 函数自己转化成了网络字节序  ，即 内部实现了

  int ret =bind(sock,(sockaddr*)&addr,sizeof(addr));
  if(ret<0)
  {
    perror("bind");
    return -1;
  }




  //绑定成功  服务器启动完成  
  //1 初始化
  // 2进入主循环 死循环
  //       1 读取请求
  //       2 处理服务器收到的请求 ，
  //       3 作出响应
  // 

  while(true)
  {
   printf("server running ok\n");
    //1  接收
    char buf[1024*10]={0};  //缓冲区
    sockaddr_in  peer;//对端  我们不管 ，自己初始化
    socklen_t len =sizeof(peer);
    ssize_t read_size = recvfrom(sock,  buf,  sizeof(buf)-1, 0,(sockaddr*)&peer,&len);
    if(read_size<0)
    {
      perror("recvfrom");
        continue;//考虑容错，不因一次错误而停止服务
    }
    buf[read_size]='\0';

    //2 略


    //3 响应
   int write_size = sendto(sock,buf,strlen(buf),0,(sockaddr*)&peer,len);
   if(write_size<0)

   {
     perror("sendto");
     continue;
   }
   printf(" [%s:%d]  buf:   %s\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port),buf);
  }
close(sock);
  return 0;
}
