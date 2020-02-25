#pragma once
#include "tcp_client.hpp"
#include <functional>

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    cout<<"启动客户时格式不对"<<endl;
    return 1;
  }

  TcpClient t(argv[1], atoi(argv[2]));
  int ret = t.Connect(); 
  if(ret < 0)
  {
    perror("connect");
    return 1;
  }

  while(true)
  {
    std::string sentence; 
    cout<<"请输入上句"<<endl;
    cin>>sentence; 
    if(!cin)
    {
      break;
    }
    t.Send(sentence);

    std::string resp;
    t.Recv(resp);
    cout<<sentence<<"的下一句:"<<resp<<endl;
  }
  return 0;
}
