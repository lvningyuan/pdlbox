#pragma  once 
#include <stdlib.h>
#include "udp_server.hpp"
#include <unordered_map>
#include "iostream"

std::unordered_map<std::string,std::string>g_dict;  //创建键值对容器 

void Translate(const std::string& req,std::string* resp)
{
  auto it = g_dict.find(req);//迭代器对象 从键值对的 req 参数 开始逐个寻找
  if(it == g_dict.end())
  {
    *resp ="未找到";
    return;
  }

  //输入输出型参数
  *resp = it->second;// 找到就输出 当前迭代对象 的 第二个参数 
}

int main(int argc ,char* argv[])
{
  if(argc != 3)
  {
    printf("format： ./dict_server  ip    port \n");
    return 1;
  }

  //初始化键值对数据
  g_dict.insert(std::make_pair("hello","你好"));
  g_dict.insert(std::make_pair("Come on  WuHan","加油，武汉"));
  g_dict.insert(std::make_pair("Great China","伟大的中国"));
  g_dict.insert(std::make_pair("forbid eating wield animals","拒绝 野味！"));
  g_dict.insert(std::make_pair("doctor is great","医生很伟大"));


  //启动服务器 

  UdpServer server;//创建服务器对象

  //argv[0] 是 ./dict_server   argv[1] 是  char*类型的 ip  ，argv【2】 是char*类型的 port
  server.Start(argv[1],atoi(argv[2]),Translate); //Translate  就是handler  函数 ，负责处理请求

  return 0;
}
