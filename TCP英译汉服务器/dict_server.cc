#pragma  once 
#include <unordered_map>
#include "tcp_server.hpp"

std::unordered_map<std::string,std::string> g_dict;

void Translate(const std::string& req, std::string& resp)
{
  auto it = g_dict.find(req);
  if(it == g_dict.end())// 没找到
  {
    resp = "未找到";
    return ;
  }

  resp =it->second;
}

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    printf("命令行参数格式错误，正确格式 argv[0]:./server argv[1]: ip,argv[2]:port");
    return 1;
  }

  //初始化数据
  g_dict.insert(std::make_pair("hello","你好") );
  g_dict.insert(std::make_pair("ayang","最帅") );
  g_dict.insert(std::make_pair("ayuan","最好") );
  g_dict.insert(std::make_pair("xiaolv","最棒") );
  g_dict.insert(std::make_pair("Augest","big offer") );

  //启动服务器
  TcpServer server(argv[1],  atoi(argv[2]) ) ;//创建服务器 的同时个 设置服务器的ip  和端口号
  server.Start(Translate);//启动服务器

  return 0;
}
