
// write your code here cpp
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
       string s; 
       char ch[10240] ={0};
    //使用gets函数来避开 输入时空格带来的干扰  但前提是我们得先开好足够大的空间
      while( gets(ch) ) 
      {
        string ret = "";
           s = ch;
        for(auto e: s)
        {
            if(e == ' ') ret +=' ';
            else if(e > 'E') ret += e-5;
            else  ret += 'V' + e -'A';
        }
         cout<<ret<<endl;
    }
    return 0;
}