#include "comm.hpp"
#include <unistd.h>
int main()
{
  int shmid = createShm(4096);//出错就会在 函数内部报错

  char* addr =(char*) shmat(shmid,NULL,0);//将 shm  连接到 进程地址空间

  int  i =0;
  while(i++ <26)
  {
    if(addr)
    printf("client addr: %s\n",addr); // 依次读取addr 开始的共享内存的数据
    sleep(1);
  }

  shmdt(addr);
  sleep(2);

  destroy(shmid);
  return 0;
}

