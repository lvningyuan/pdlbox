#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int  g_val=0;
int main()
{
  pid_t t1 =fork();

  if(t1 < 0)
  {
    perror("fork");
    return 0;
  }
  if(t1 == 0)
  {
    printf("i'm child   %d  %d  %p\n",getpid(),g_val,&g_val);
  }
  else 
  {
    printf("i'm father  %d  %d  %p\n",getpid(),g_val,&g_val);
  }
//我们发现 结果的地址值都一样 ，但是对应的值却不一样  ，这说明 改地址绝对不是真实地址 这就是页表  虚拟地址空间

  return 0;
}
