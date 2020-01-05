#pragma  once 
#include <functional>
#include "tcp_socket.hpp"
#define HANG(exp){  if(!exp)\
  return false;}

typedef std:: function  < void (const std::string& req,std::string&resp)> Handler;

class TcpServer
{
  public:

    TcpServer(const std::string ip,uint16_t port):ip_(ip) , port_(port)
  {}

    ~TcpServer()
    {
      tsock_.Close();
    }

    bool Start(Handler handler)

    {
      HANG (tsock_.Socket());

      HANG(tsock_.Bind(ip_,&port_));

      HANG(tsock_.Listen(5));

      //进入主循环
      //拉去请求
      //
      //计算
      //
      //响应

      TcpSocket client_sock;
      std::string client_ip;
      uint16_t client_port = 0;
      while(1)
      {
        if(! tsock_.Aceept(client_sock) )
          continue;
      }

      while(1)
      {
        std::string req;
        bool  ret  =tsock_.Recv(req,client_ip,&client_port);
        if(!ret )
        {
          tsock_.Close();
          perror("Recv");
          break;
        }
        std::string resp; 

        handler(req,resp);

        tsock_.Send(resp);
      }
      return true;
    }
  private:
    TcpSocket tsock_;
    std::string ip_;
    uint16_t port_;

};
