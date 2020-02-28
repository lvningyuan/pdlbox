#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(int *a, int begin, int end ,int* tmp)
{
  if(begin >= end)
    return;
  int mid = begin + ((end - begin)>>1);


  Merge(a, begin, mid, tmp);
  Merge(a, mid+1, end, tmp);
  
  int begin1 = begin; 
  int begin2 = mid + 1;
  int end1 = mid ;
  int end2 = end;
  int index = begin;

  while(begin1 <= end1 && begin2 <= end2)
  {
    if(a[begin1] < a[begin2])
    {
      tmp[index++] = a[begin1++];
    }
    else 
    {
      tmp[index++] = a[begin2++];
    }
  }
    while(begin1 <= end1)
    {
      tmp[index++] = a[begin1++];
    }
    while(begin2 <= end2)
    {
      tmp[index++] = a[begin2++];
    }
    memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin +1));//注意 每层递归只交换自己处理的数据
  }

  void Print(int*a, int n)
{
  int i =0;
  for( ; i<n; ++i )
  {
    printf("%d\t",a[i]);
  }
  printf("\n");
}


void  Test()
  {
    int a[] = {45,6,7,8,0,9,7,65};
    int n =sizeof(a) / sizeof(int);
    int tmp[n];
    Merge(a, 0, n-1,tmp);
    Print(a, n - 1);  
  }

int main()
{
  Test();
  return 0;
}
