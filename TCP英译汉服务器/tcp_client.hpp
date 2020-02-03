#pragma  once 
#include "tcp_socket.hpp"

class TcpClient
{
  public:
   TcpClient(const std::string ip,uint16_t port )
     :server_ip_(ip)
      ,server_port_(port)
  {
    assert(sock_.Socket());
  }
   ~TcpClient()
   {
     sock_.Close();
   }

   bool Connect()
   {
       return  sock_.Connect(server_ip_,server_port_);
   }

   bool Recv(std::string& buff)
   {
     return sock_.Recv(buff);
   }

   bool Send(const std::string& msg)
   {
     return sock_.Send(msg);
   }


  private:
    TcpSocket sock_;
    std::string server_ip_;
    uint16_t server_port_;
};
