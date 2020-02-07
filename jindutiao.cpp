#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
  char a[101]={0};
  char b[] ="-\\|/";
  int i=0;

  for(; i<100; i+=2)
  {
    a[i] = '#';
    a[i+1]= '#';
    printf("[%d]%% [%c] \e[1;33m %s\r",i,b[i%4],a);
    fflush(stdout);
    usleep(234* 1000);
  }
  return 0;
}
