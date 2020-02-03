#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void* Func1(void* arg)
{
  sockaddr_in* id =  (sockaddr_in*) arg;
  while(1)
  {
    char* ptr = inet_ntoa(id->sin_addr);
    printf("addr1 : %s : \n",ptr);
    sleep(1);
  }

  return NULL;
}


void* Func2(void* arg)
{
  sockaddr_in* id =  (sockaddr_in*) arg;
  while(1)
  {
    char* ptr = inet_ntoa(id->sin_addr);
    printf("addr2 : %s : \n",ptr);
    sleep(1);
  }

  return NULL;
}

int main()
{
  pthread_t t1,t2;

  sockaddr_in addr1;
  sockaddr_in addr2;
  addr1.sin_addr.s_addr = 0;
  addr2.sin_addr.s_addr = 0xffffffff;

  pthread_create(&t1,NULL,Func1,&addr1);
  pthread_create(&t2,NULL,Func2,&addr2);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  return 0;
}
