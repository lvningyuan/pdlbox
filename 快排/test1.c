#include <stdio.h>

void Swap(int* a, int* b)
{
  int tmp =*a;
  *a = *b;
  *b =tmp;
}


int PartQsort(int* a, int begin, int end)
{
  int cur =begin; 
  int prev = begin -1;
  int key =end;

  while(cur < end)
  {
    if(a[cur] < a[key] && ++prev != cur)
      Swap(&a[prev], &a[cur]);

    ++cur;
  }

  Swap(&a[key], &a[++prev]);//prev 是当前的下一个
  return prev;
}
void Qsort(int*a, int begin, int end)
{
  if(begin >= end)
    return;

  int keyIndex =PartQsort(a,begin,end);
      Qsort(a,begin,keyIndex - 1);
      Qsort(a,keyIndex + 1, end);
}

int main()
{

  int a[7] = {4,56,7,5,8,98,9};
  Qsort(a,0,sizeof(a) / sizeof(int) - 1); 
  for(unsigned int i=0; i < sizeof(a) / sizeof(int); ++i)
    printf("%d\t",a[i]);
  printf("\n");
  return 0;
}
