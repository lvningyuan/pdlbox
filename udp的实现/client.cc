#include <cstdio>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstring>



//命令行参数让可选择的 服务器的 IP 可变
//./client 127.0.0.1
int main(int argc,char*argv[])
{
  int sock= socket(AF_INET,SOCK_DGRAM,0);
  if(sock<0)
  {
    perror("socket");
    return  1;
  }

  //客户端不要 bind 让系统自动分配   若是 客户端bind，其他客户端  qq   Wechat  也绑定了同一个端口号，将会导致出错
  while(1)
  {
    char buf[1024*10];
    printf("请输入一段话\n");
    fflush(stdout);//刷新缓存
    scanf("%s",buf);

    //准备 服务器的IP  和 sockaddr;

    sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr(argv[1]);
    addr.sin_port=htons(9090);

    //向服务器发送
    sendto(sock,buf,strlen(buf),0,(sockaddr*)&addr,sizeof(addr));

    //从服务器接收返回结果
    char buf_out[1024*10]={0};
    ssize_t read_size = recvfrom(sock,buf_out,sizeof(buf_out)-1,0,NULL,NULL);
    if(read_size<0)
    {
      perror("recvfrom");
      return 1;
    }
    buf_out[read_size]='\0';
    printf("server  reap:  %s\n",buf_out);

  }

  return 0;
}
