#include <cstdio>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <sys/socket.h>

//TCP  要建立连接   连接五元组  源ip  源端口   目的ip  目的端口  协议


class TcpSocket
{
  public:
  TcpSocket():fd_(-1)
  {}

  bool Socket()
  {
    fd_ = socket(AF_INET,SOCK_STREAM,0);
    if(fd_ <  0)
    {
      perror("sockect");
      return false;
    }

    return true;
  }


  bool Bind(std:: string& ip,uint16_t *port)
  {
    sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr(ip.c_str());
    addr.sin_port=htons(*port);
    int  n = bind (fd_ ,(sockaddr*)&addr, sizeof(addr) );
    if(n < 0)
    {
      perror("bind");
      return false;
    }

    //  否则 绑定成功  
    return true;
  }


  bool Listen(int num )    //每个调用了listen的 对象 都拥有一个  队列，长度为backlog
  {
    int n =listen(fd_ , num);
    if(  n < 0 )
    {
      perror("listen");
      return false;
    }
    return true ;
  }




  // 等待队列建立完成 准备 拉取请求 服务器 即将启动   随时准备做出响应

  bool Aceept(TcpSocket& new_sock)const //从连接队列中取一个连接 五元组   到用户代码中，没有 连接 就会发生阻塞（默认行为） 
  {

    sockaddr_in peer;
    socklen_t len =sizeof(peer);
      int  client_sock =accept(fd_,(sockaddr*)&peer,&len); 
      if(client_sock < 0)
      {
        perror("accept");
        return false; //服务器 需要具备容错能力
      }

      new_sock.fd_= client_sock;
    return  true; //返回值也是一个  socket
  }


  //与客户端建立连接
  bool Connect(std::string& ip,uint16_t port)
  {
    sockaddr_in peer;
    peer.sin_family=AF_INET;
    peer.sin_addr.s_addr=inet_addr(ip.c_str());
    peer.sin_port=htons(port);
    socklen_t len =sizeof(peer);
    int n  = connect(fd_ ,(sockaddr*)&peer ,len);
    if(n  < 0)
    {
      perror("connect");
      return false;
    }
    return true;
  }

  //接收请求 


  bool  Close()
  {
    if(fd_ <0)
    close(fd_);

    return  true;
  }

  //作出响应
  bool Send(std::string&resp)
  {
    char tmp[1024 * 10]={0};
    ssize_t n = send(fd_,tmp,sizeof(tmp)-1,0);
    if(n < 0)
    {
      perror("send");
      return false;
    }
    resp.assign(tmp);
    return true;
  }



  bool  Recv(std::string& resp,std::string& ip,uint16_t* port)
  {
    char tmp[1024]={0};
    sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=ntohs(*port);
    addr.sin_addr.s_addr=inet_addr(ip.c_str());
    int  n = recv(fd_,tmp,sizeof(tmp)-1,0);
    {
      if (n < 0)
      {
        perror("recv");
        return false;
      }
      return true;
    }
    tmp[n]='\0';
    resp=tmp;
    if(! ip.empty())
      ip=inet_addr(ip.c_str());
    if(port)
      *port=ntohs(addr.sin_port);
    return true;
  }

  bool Getfd()
  {
    if(fd_ != -1)
    {
    printf("fd : %d\n",fd_);
    return true;
    }
    else
    {
      printf("不存在\n");
    return false;
    }
  }

  private:

  int fd_;
};

