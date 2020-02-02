#pragma  once 

#include "udp_client.hpp"
#include "iostream"

int main(int argc, char* argv[])
{
  if(argc != 3 )
  {
    printf("format: ./client.cc ,ip ,port\n ");
    return 1;
  }

  UdpClient client(argv[1], atoi(argv[2]));
  while(1)
  {
    std::string word;
    std::cout<<"请输入您要查的句子 单词 或短语："<<std::endl; 
    std::cin>>word;
    if(!std::cin)
    {
      std::cout<<" Good bye"<<std::endl;
      break;
    }
    client.SendTo(word);
    std::string result;
    client.RecvFrom(result);
    std::cout<<word<<"意思是"<<result<<std::endl;
  }
  return 0;
}
