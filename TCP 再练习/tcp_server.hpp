#pragma once 
#include "tcp_socket.hpp"
#include <functional>
#define CHECK_RET(exp) if(!(exp)) {\
  return false;\
}

typedef  function<void(std::string&, std::string&)> Handler;

class TcpServer
{
  public:
    TcpServer(const std::string& ip, uint16_t port)
      :listen_ip_(ip)
       ,listen_port_(port)
  {}

    ~TcpServer()
    {
      listen_.Close();
    }



    bool Start(Handler handler)
    { 
      CHECK_RET(listen_.Socket()   && listen_.Bind(listen_ip_,listen_port_) && listen_.Listen(5) );
      while(true)
      {
        TcpSocket client; //新的socket  复制了一份 客户端socket 的内容， 含有客户端ip + port 服务器 ip + port
        std::string client_ip;
        uint16_t client_port;
        int ret = listen_.Accept(client, client_ip, client_port); //获取客户端文件描述符 + IP + Port client为返回连接成功客户端使用的fd
        if(ret < 0)
        {
          continue;//获取客户端信息失败 ，
        }

        cout<<"connect succeed !"<<endl;
        cout<<"client ip"<<client_ip<<endl<<"client port"<<client_port<<endl;
      
        //循环读写
        while(true)
        {

          std::string req;
          bool ret = client.Recv(req);
          if(!ret)
          {
            perror("客户端断开连接");
            client.Close();
            break;
          }

          std::string resp;
          handler(req,resp);

          client.Send(resp);
        }
      }
      return true;
    }
    bool Close()
    {
      return listen_.Close();
    }
  private:
    TcpSocket listen_;
    std::string listen_ip_;
    uint16_t listen_port_;
};
