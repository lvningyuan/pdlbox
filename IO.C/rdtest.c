#include  <stdio.h>
#include  <string.h>

int main()
{
  FILE * fp =fopen("myfile","w");
  if(!fp)
    perror("fopen");
  const char* msg= "hello world !\n";
  int count =5;
  while(count--)
  {
    fwrite(msg,strlen(msg),1,fp);
    printf("%s\n",msg);
  }
  fclose(fp);
  return 0;
}
