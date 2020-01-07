#pragma  once 
#include "socket.hpp"
#include <functional>

typedef std::function < void(const std::string& req , std::string& resp) > Handler;

class UdpServer
{
  public:
    UdpServer()
  {
    assert(sock_.Socket);//因为构造函数 不存在返回值 ，所以如果创建 socket 失败  我们通过断言 或者标准错误退出
  }

    ~UdpServer()
    {
      sock_.Close();
    }


    bool Socket()
    {
      return  sock_.Socket();
    }

    bool  Start(std::string& ip,uint16_t& port,Handler handler)
    {
      bool ret = sock_.Bind(ip,port);
      if(!ret)
        return false;
      std:: string req;
      req.clear();

      std::string client_ip;  
      uint16_t client_port;

      while(true)
      {
        bool ret = sock_.RecvFrom(req,ip,port);
        if(!ret)
        {
          continue;
        }

        std::string resp;
        handler(req,resp);//计算   处理请求

        sock_.Send(resp,client_ip,client_port);//udp 传输  不清楚发送成功与否
      }
      sock_.Close();
      return true;
    }

  private:
    UdpSocket sock_;
    std::string server_ip_;
    uint16_t server_port_;
};
