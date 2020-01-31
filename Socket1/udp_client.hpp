#pragma  once 
#include "udp_socket.hpp"

class UdpClient
{
  public:
    UdpClient()
    {
      assert(sock_.Socket());
    }

    ~UdpClient()
    {
      sock_.Close();
    }

    bool RecvFrom(std::string &msg)
    {
     return  sock_.RECV(msg,&client_ip_,&client_port_);
    }

    bool SendTo(const std::string &msg)
    {
      return sock_.SendTo(msg,client_ip_,client_port_);
    }


  private:
    UdpSocket sock_;
    std::string client_ip_;
    uint16_t client_port_;
};

