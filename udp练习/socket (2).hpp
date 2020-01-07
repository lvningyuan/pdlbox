#pragma once
#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

class UdpSocket
{
  public:
    UdpSocket():fd_(-1){}
    bool Socket()
    {
      fd_ =socket(AF_INET,SOCK_DGRAM,0);
      if(fd_ < 0)
      {
        perror("socket");
        return true;
      }
      return false;
    } 


    bool  Bind(std::string& ip,uint16_t& port)
    {
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      addr.sin_port=htons(port);
      socklen_t len =sizeof(addr);
      int ret =bind(fd_,(sockaddr*)&addr,len);
      if(ret < 0)
      {
        perror("bind");
        return false;
      }

      return true;
    }

    bool RecvFrom(std::string& buf, std::string&ip, uint16_t& port)
    {
      char tmp[1024]={0};
      sockaddr_in peer;
      socklen_t len =sizeof(peer);

      ssize_t n = recvfrom(fd_ , tmp , sizeof(tmp)-1 , 0 ,(sockaddr*)&peer , &len);
      if(n<0)
      {
        perror("recvfrom");
        return false;
      }
      tmp[n] = '\0';//上保险
      buf.assign(tmp);

      if(!ip.empty() )  //ip  不为空
      {
        ip = inet_ntoa(peer.sin_addr);
      }
      if(port)
      {
        port = htons(peer.sin_port); 
      }

      return true;
    }

    bool Send(std::string& buf ,const std::string& ip, uint16_t& port )
    {

      sockaddr_in  peer ;
      peer.sin_family = AF_INET;
      peer.sin_addr.s_addr = inet_addr(ip.c_str());
      peer.sin_port = htons(port);

      int  n = sendto(fd_ ,buf.data() , buf.size(),0, (sockaddr*)&peer, sizeof(peer));
      if(n < 0)
      {
        perror("sendto");
        return false;
      }
      return true;
    }
    bool Close()
    {
      if(fd_ < 0)
        close(fd_);

      return true;
    }

   int  GetFd()
   {
       return fd_;
   }


  private:
    int fd_;
};
