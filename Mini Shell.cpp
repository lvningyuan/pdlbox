#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>//进程退出
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
//#include <fcntl.h>
#define  MAX_CMD  20//设置命令的长度



char command[MAX_CMD];//设置全局变量 command 接收命令字符串

int do_face()
{
  memset(command,0,MAX_CMD);//初始化为0
  printf("minishell :\n");  //开始
  fflush(stdout);
  if(scanf("%[^\n] %*c",command) ==0)//从command 杜若一行字符串 ，遇见\n结束，*表示不赋予任何变量
  {
    getchar();
    return -1;//没读到
  }
  return 0;//读取成功
}


char** do_parse(char* buff)
{
  int  argc =0;
  static  char* argv[32];//字符串类型数组 //指针数组   //static 是为了防止返回  argv地址后 出了函数，出现野指针了
  char* ptr =buff;

  while(*ptr != '\0')
  {
    if(!isspace(*ptr))
    {
      argv[argc] = ptr;
      argc++;

      while(!isspace(*ptr) && *ptr !='\0')
        ptr++;
    }
    else 
    {
      while(isspace(*ptr))//遇见 空格，加'\0'
      {
        *ptr = '\0';
        ptr++;
      }
    }
  }
  argv[argc] = NULL;//尾部以NULL结尾
  return argv;
}



  int do_exec(char* command)//读取命令成功就进行   程序替换
  {

    char** argv = {NULL};//准备一个 参数列表，作被替换后的 目的函数 
    int pid =fork();
    if(pid == 0 )//child
    {

      argv = do_parse(command);//   计算处理command 请求
      if(argv[0] == NULL)//没有 可以替换当前参数的 替换函数
      {
        exit(-1);//异常退出
      }

      execvp(argv[0],argv);//否则进行 程序替换
    }

    else 
    {
      waitpid(-1,NULL,0);
    }

    return 0;
  }


  int main(int argc ,char* argv[])
  {

    while(1)
    {
      if(do_face() < 0)
        continue;

      do_exec(command);
    }

    return 0;
  }
