#pragma  once 
#include "tcp_socket.hpp"
#include <functional>

typedef std::function<void(const std::string& req,std::string& resp)> Handler;

class TcpServer
{
  public:
    TcpServer(const std::string ip,uint16_t port )
      :ip_(ip)
       ,port_(port)
  {}


    bool Start(Handler handler)
    {
      CHECK_RET(sock_.Socket() && sock_.Bind(ip_,port_) &&  sock_.Listen(5));//创建  绑定  监听 成功进入主循环，启动服务器
      while(1)//进入主循环
      {
        TcpSocket client;
        std::string client_ip;
        uint16_t client_port;

        bool ret =  sock_.Accept(&client,&client_ip,&client_port);// 接收客户端信息  ip  port  以及sockfd
        if(!ret)
          continue;

        printf("获取客户端信息成功客户端ip: %s  客户端端口号 %d\n",client_ip.c_str(),client_port);



        //获取信息结束 ，准备处理
        while(1)
        {
          std::string req;
          bool ret = sock_.Recv(req);//接收客户端请求
          if(!ret)//接受失败
          {
            printf("%s  %d  连接失败！\n",client_ip.c_str(),client_port);
            sock_.Close();//关闭文件描述符 
            break;
          }
          //否则连接成功 ，那么进行相应的处理
          std::string resp;
          handler(req,resp);

          //发送响应
          ret  =  sock_.Send(resp);
          if(!ret )
          {
            printf("服务器发送响应失败+1\n");
            continue;//服务器应具有容错性
          }
          printf("响应成功：响应内容 %s,客户端ip: %s客户端port :%d\n",resp.c_str(),client_ip.c_str(),client_port);
        }
      }
      return true;
    }

  private:
    TcpSocket sock_;
    std::string ip_;
    uint16_t port_;
};
