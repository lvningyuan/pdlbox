#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PATHNAME "."
#define PROJ_ID 0x6666

int createShm(int size);//create 
int destroyShm(int shmid);//destroy
int getShm(int size);//get

//创建一段共享内存，并获取其 标识码
static int commShm(int size ,int flags)
{
  key_t key = ftok(".",0x1);
  if(key < 0)
  {
    perror("ftok");
    return -1;
  }
  int shmid ;
  if((shmid = shmget(key, size, flags)) < 0)
  {
    perror("shmid");
    return -2;
  }
  return shmid;
}


int destroy(int shmid)
{

if(shmctl(shmid,IPC_RMID,NULL) < 0) //IPC_RMID 标记要销毁的内存段
{
  perror("shmctl");
  return -3;
}

return 0;
}
//调用创建函数  创建共享内存
int createShm(int size)
{
  return commShm(size,IPC_CREAT |IPC_EXCL |0666);//size  +  flag //excl  保证shmid标识的内存段 存在的情况下 创建失败
}

//存在共享内存 就获取 shmid 
int  getShm(int size)
{
  return commShm(size,IPC_CREAT);
}
