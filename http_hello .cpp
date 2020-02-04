#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void Usage()
{
  printf("usage : ./server [ip] [port]\n");
}

int main(int argc,char* argv[])
{
  if(argc != 3 )
  {
    Usage();
    return 1;
  }

  int fd = socket(AF_INET,SOCK_STREAM,0);
  if(fd < 0)
  {
    perror("socket");
    return 1;
  }

  sockaddr_in addr; 
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(argv[1]);
  addr.sin_port = htons(atoi(argv[2]) ) ; 

  int ret = bind(fd,(sockaddr*)&addr,sizeof(addr));
  if(ret < 0)
  {
    perror("bind");
    return 1;
  }
  ret =listen(fd,10);

  if(ret < 0)
  {
    perror("listen");
    return 1;
  }
  while(1)
  {
    sockaddr_in peer_addr;

    socklen_t len =0;
    ret = accept(fd,(sockaddr*)&peer_addr,&len);
    if(ret < 0)
    {
      perror("accept"); 
      continue;
    }

    char  input_buf[1024 * 1024] = {0};
    ssize_t n = read(fd,input_buf,sizeof(input_buf)-1);
    if(n < 0 )
    {
      perror("read");
      return 1;
    }

    printf("request :%s\n",input_buf);
    char buf[1024] = {0};

    const char* hello = "<h1>hello world</h1>";

    sprintf(buf,"<HTTP/1.0 200 OK \nContent-Length:%lu\n%s>",strlen(hello),hello);
    write(fd,buf,strlen(buf));
  }

  return 0;
}
