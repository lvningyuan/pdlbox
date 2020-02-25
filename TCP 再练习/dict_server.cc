#pragma  once
#include <iostream>
#include "tcp_server.hpp"
#include <functional>
#include <unordered_map>

using namespace std;


std::unordered_map<std::string,std::string> g_append;


void Deal(const std::string& req, std::string& resp)
{
  auto it = g_append.find(req);
  
  if(it == g_append.end())
  {
    resp == "未找到";
    return;
  }
  resp = it->second;
}


int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    cout<<"server启动格式错误"<<endl;
    return 1;
  }

  g_append.insert(make_pair("尔来四万八千岁","不与秦塞通人烟"));
  g_append.insert(make_pair("春江花朝秋月夜","往往取酒还独倾"));
  g_append.insert(make_pair("前不见古人","后不见来者"));
  g_append.insert(make_pair("仰天长啸出门去","我辈岂是蓬蒿人"));
  g_append.insert(make_pair("天姥连天向天横","势拔五岳掩赤城"));

  TcpServer s(argv[1], atoi(argv[2]));

  s.Start(Deal);
  return 0;
}
