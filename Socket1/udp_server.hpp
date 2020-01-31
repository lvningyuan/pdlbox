#pragma  once 
#include "udp_socket.hpp"

#include <functional>

typedef void(*Handler)(const std:: string& req, std::string resp);

class UdpServer
{

  public:
    UdpServer()
    {
      assert(sock_.Socket());
    }

    ~UdpServer()
    {
    sock_.Close();
    }

bool Start(const std::string& ip, uint16_t port, Handler handler )
{
  bool ret = sock_.Bind(ip,port);
  if (!ret )
  {
    return false;
  }

  //进入主循环 
  while(1)
  {
    std::string req ;
    std::string remote_ip;//接收客户端的ip
    uint16_t remote_port;//接收客户端port

     ret = sock_.RECV(req,&remote_ip,&remote_port);
    if(!ret)
    {
      printf("出错一次，已主动跳过\n");
      continue; //服务器考虑容错
    }
    //否则 接收成功 
    //准备响应处理 
     

    std::string resp;
    handler(req,resp);//处理

  sock_.SendTo(resp,remote_ip,remote_port);
  printf("[%s  %d ]  req : %s resp: %s\n",remote_ip.c_str(),remote_port,req.c_str(),resp.c_str());
  }
  sock_.Close();
  return true;
}


  private:
    UdpSocket sock_; 
};
