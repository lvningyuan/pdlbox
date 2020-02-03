#pragma once 
#include "tcp_client.hpp"
#include <iostream>

int main(int argc ,char* argv[])
{
  if(argc != 3)
  {
    printf("客户端命令行参数的格式设置有误，格式为./client  + client_ip  + client_port\n");
    return 1;
  }

  TcpClient client(argv[1],  atoi(argv[2])   );//创建客户端对象
  bool  ret  = client.Connect();
  if(!ret )
  {
    printf("客户端connect 失败\n");
    return 1;
  }


  //否则 连接服务器成功  进入主循环
  while(1)
  {
    std::cout<<"请输入要查询的单词"<<std::endl;
    std::string word;
    std::cin>>word;
    if(!std::cin)
    {
      break;
    }
    client.Send(word);
    std::string result;
    client.Recv(result);
    std::cout<<result<<std::endl;
  }


  return 0;
}

