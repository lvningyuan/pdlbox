#pragma once 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <cassert>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string>


#define CHECK_RET(exp) if(!exp){\
  return false;\
}

class TcpSocket
{

  public:
    TcpSocket():fd_(-1){}

    bool Socket()
    {
      fd_ = socket(AF_INET,SOCK_STREAM,0);

      if(fd_ < 0 )
      {
        perror("socket");
        return false;
      }
      return true;
    }




    bool Bind(const std::string& ip ,uint16_t& port)
    {
      sockaddr_in addr ;
      addr.sin_family = AF_INET;
      addr.sin_addr.s_addr = inet_addr(ip.c_str());
      addr.sin_port = htons(port);
      socklen_t len =sizeof(addr);
      int ret = bind(fd_,(sockaddr*)&addr,len);
      if (ret < 0)
      {
        perror("bind");
        return false;
      }
      return true;
    }



    bool Close()
    {
      if(fd_ > 0)
        close(fd_);

      return true;
    }


    bool Listen(int num)//监听队列长度
    {
      int ret =listen(fd_,num);
      if(ret < 0)
      {
        perror("listen");//监听失败
        return false;
      }

      return true; //监听成功
    }



    bool Accept(TcpSocket* peer ,std::string* ip = NULL,uint16_t* port = NULL )//传出对端的 sockfd  ip  和  port
    {
      sockaddr_in peer_addr;
      peer_addr.sin_family=AF_INET;
      peer_addr.sin_addr.s_addr=inet_addr((*ip).c_str());
      peer_addr.sin_port = htons(*port);
      socklen_t len =sizeof(peer_addr);
      int client_fd = accept(fd_,(sockaddr*)&peer_addr,&len);//accept 输入输出型参数 addr  传出客户端的地址和端口号 ，len传出客户端的长度 ，因为addr具有多种结构体类型,  另外 返回值传出客户端的套接字sockfd;
      if(client_fd < 0)
      {
        perror("accept");
        return false;
      }

      printf("accept fd = %d\n",client_fd);//接收到客户端的网络套接字sockfd
      peer->fd_  = client_fd;
      if(ip != NULL )
      {
        *ip = inet_ntoa(peer_addr.sin_addr);
      }

      if(port != NULL)
      {
        *port = ntohs(peer_addr.sin_port);
      }
      return true;
    }



    bool Recv( std::string& buff)
    {
      buff.clear();
      char tmp[1024 *1024] = {0};//缓冲区要足够大，防止数据溢出
      ssize_t n = recv(fd_,tmp,sizeof(tmp),0);
      if(n < 0)
      {
        perror("recv");
        return false;
      }
      buff.assign(tmp);
      return 0;
    } 
   
    
    bool Send(const std::string& msg)
    {
      ssize_t n =send(fd_,msg.data(),msg.size(),0);  
      if(n < 0 )
      {
        perror("send");
        return false;
      }
      return true;

    }


    //connect 给客户端使用
    //客户端主动链接服务器
    bool Connect(const std::string& ip ,const uint16_t& port)//  服务器与客户端建立连接
    {
      sockaddr_in peer;
      peer.sin_family = AF_INET;
      peer.sin_addr.s_addr = inet_addr(ip.c_str());
      peer.sin_port = htons(port);
      socklen_t len = sizeof(peer);
      int ret  = connect(fd_,(sockaddr*)&peer,len);
      if(ret < 0)
      {
        perror("connect");
        return false;
      }
      return true;
    }

    
    int GetFd()
    {
      return fd_;
    }

  private:
    int fd_;
};


