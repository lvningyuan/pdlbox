#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <stdio.h>
using namespace std;

class TcpSocket{

  public:
    TcpSocket()
    {}
    
    TcpSocket(int fd)
      :fd_(fd)
    {}

    bool Socket()
    {

      fd_ = socket(AF_INET, SOCK_STREAM,0);
      if(fd_ < 0)
      {
        perror("socket");
        return false;
      }
      return true;
    }

    bool Bind(std::string& ip ,uint16_t port)
    {
      sockaddr_in addr; 
      addr.sin_family =AF_INET;
      addr.sin_addr.s_addr = inet_addr(ip.c_str());
      addr.sin_port = htons(port);

      int ret = bind(fd_,(sockaddr*)&addr, sizeof(addr));
      if(ret < 0)
      {
        perror("bind");
        return false;
      }
      return true;
    }

    bool Listen(int num)//监听队列中监听的数量
    {
      int ret = listen(fd_, num);
      if (ret < 0)
      {
        perror("listen");
        return false;
      }
      return true;
    }


    bool Accept(TcpSocket& peer, std::string& ip, uint16_t& port)//从监听队列中 获取 任务
    {
      sockaddr_in peer_addr;
      socklen_t len = sizeof(peer_addr);//结构体大小是一定的
      int newsocket = accept(fd_, (sockaddr*)&peer_addr, &len);
      if(newsocket < 0)
      {
        perror("accept");
        return false;
      }

      cout<<"accept new socket"<<newsocket<<endl;
      peer.fd_ = newsocket;
      ip =   inet_ntoa(peer_addr.sin_addr);
      port = ntohs(peer_addr.sin_port);
      return true;
    }
    bool Connect(std::string& ip, uint16_t port)
    {
      sockaddr_in addr;
      addr.sin_family =AF_INET;
      addr.sin_addr.s_addr = inet_addr(ip.c_str());
      addr.sin_port = ntohs(port);
      int ret  =connect(fd_, (sockaddr*)&addr, sizeof(addr));
      if(ret < 0)
      {
        perror("connect");
        return false;
      }
      return true;
    }

    bool Recv(std::string& msg)//TCP 是连接建立好的情况下进行传输数据 ，所以没必要知道对方ip  和 port 了
    {
      msg.clear();  
      char tmp[1024 * 10];
      int rdsize = recv(fd_, tmp, sizeof(tmp) - 1,0);
      if(rdsize < 0)   //小于 0  接收失败
      {
        perror("recv");
        return false;
      }
      else if(rdsize == 0)//对端关闭
      {
        cout<<"对端关闭"<<endl;
        return false;
      }

      tmp[rdsize] =0;
      msg.assign(tmp,rdsize) ;
      return  true; 
    }

    bool Send(const std::string msg)//在建立好链接的基础上发送数据 ，不需要知道对方 ip + port
    {
      int wtsize = send(fd_,msg.data(),msg.size(),0);
      if(wtsize < 0)
      {
        perror("send");
        return false;
      }
      return true;
    }
      
    bool Close()
    {
        close (fd_);
      return true;
    }
    int Getfd()
    {
      return fd_;
    }


  private:
    int fd_; 
};
