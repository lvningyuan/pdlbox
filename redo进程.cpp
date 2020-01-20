#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main ()
{
 pid_t t1 = fork();//fork()函数 创建 1个子进程    //父子进程抢占式执行
  if(t1 < 0)
  {
    perror("fork");
    return -1;
  }
  pid_t t;
  if(t1 == 0)
  {
   // sleep(10);//造成孤儿进程  ，被 1 号进程回收, 
    printf("i'm child  %d\t %d\n",getpid(),getppid());
    printf("%d\n",t1);
    t=t1;
  }
else 
{
  printf("i'am father ,%d\t %d\n",getpid(),getppid());
  printf("%d\n",t1);
// waitpid(-1,NULL,0);//-1 表示等待任意一个子进程， NULL，表示不关心子进程退出状态 ， 0表示 阻塞式等待，WNOHANG表示非阻塞式等待 
  // wait(NULL);//处理僵尸进程的方案一 ：进程等待 ，方案二：杀死父进程 ，形成孤儿进程
   while (1) 
   {
    pid_t n= waitpid(-1,NULL,WNOHANG);//轮询式等待
    if(n !=0)
      break;
   }
     while(1)   sleep(10);//父进程未结束 ，子进程先结束，父进程没有回收子进程的资源（返回状态） ，造成僵尸进程
}
  return 0;
}
