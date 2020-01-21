#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  FILE *fp =fopen("myfile","r");//打开文件流指针
  if(!fp)
  {
    perror("fopen");
  }
  char buff[1024];
  const char* msg ="hello world !\n";

  while(1)
  {
    ssize_t s =fread(buff,1,strlen(msg),fp);//从文件中读 strlen(msg)长度的数据
    if(s > 0)
    {
      buff[s] = 0;
      printf("%s",buff);
    }

    if(feof(fp))//fp指针走到文件尾了
      break;
  }

  fclose(fp);//关闭流
  return 0;
}
