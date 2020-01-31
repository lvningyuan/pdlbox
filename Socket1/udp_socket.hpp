#pragma  once
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>
#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

class UdpSocket
{
  public:
    UdpSocket()
      :fd_(-1)
    {}

    bool Socket()
    {
      fd_  = socket(AF_INET,SOCK_DGRAM,0);
      if(fd_< 0)
      {
        perror("socket");
        return false;
      }
      return true;
    }


    bool Close()
    {
      close(fd_);
      return true;
    }

    bool Bind(const std::string& ip, uint16_t port)
    {
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.s_addr =inet_addr(ip.c_str());
      addr.sin_port = htons(port);
      int ret = bind(fd_,(sockaddr*)&addr, sizeof(addr));
      if (ret < 0)
      {
        perror("bind");
        return false;
      }
      return true;
    }

    bool RECV(std::string& msg, std::string *ip = NULL ,uint16_t* port = NULL )//目标IP， 目标端 口  //默认从哪接收
    {
      char buff[1024];//缓冲区
      sockaddr_in peer;
      socklen_t len =sizeof(peer);

      int rdsize = recvfrom(fd_, buff,sizeof(buff)-1,0,(sockaddr*)&peer,&len);
      if (rdsize < 0)
      {
        perror("recvfrom");
        return false;
      }



      buff[rdsize] = 0;
      msg.assign(buff);
      if(ip != NULL)
      {
        *ip = inet_ntoa(peer.sin_addr);
      }

      if( port != NULL )
      {
        *port = ntohs(peer.sin_port);
      }
      return true;

    }



    bool SendTo(const std::string&buff,const std::string& ip, uint16_t& port)
    {
      sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_addr.s_addr = inet_addr(ip.c_str());
      addr.sin_port = htons(port);

      int sdsize = sendto(fd_, buff.data(),buff.size(),0,(sockaddr*)&addr,sizeof(addr));//buff 是 string 对象，所以应该传 .data() ,和 .size
      if(sdsize  < 0)
      {
        perror("sendto");
        return false;
      }


      return true;
    }
  private:
    int fd_;
};
