#pragma once 
#include "tcp_socket.hpp"

class TcpClient
{
  public:
    TcpClient(const std::string& ip, uint16_t port )
      :ip_(ip)
       ,port_(port)
    {
      assert(sock_.Socket());
    }
    
    ~TcpClient()
    {
      sock_.Close();
    }
    
    bool Socket()
    {
      return sock_.Socket();
    }

    bool Connect()
    {
      return sock_.Connect(ip_, port_);
    }
    
    bool Send(std::string req)
    {
      return sock_.Send(req);
    }
    
    bool Recv(std::string& resp)
    {
        return sock_.Recv(resp);
    }

    bool Close()
    {
      return sock_.Close();
    }
  
  
  private:
    TcpSocket sock_;
    std::string ip_;
    uint16_t port_;
};
