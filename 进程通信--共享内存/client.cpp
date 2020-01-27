#include "comm.hpp"
#include <unistd.h>

int main()
{
  int shmid = getShm(4096);//获取共享内存的 标识码   同样出错 在函数内部就会报错出来

  sleep(1); //模拟 获取过程

  char* addr = (char*) shmat(shmid,NULL,0);//将共享内存连接到进程地址空间 
  sleep(2);

  int  i = 0;
  while(i < 26)
  {
    addr[i] = 'A' + i;//我们测试26个大写字母
    i++;
    addr[i] = 0;
    sleep(1);
  }

  shmdt(addr);
  sleep(2);
  return 0;
}
