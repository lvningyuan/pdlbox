#include <stdio.h>


void Swap(int* a, int* b)
{
  int tmp =*a;
  *a = *b;
  *b =tmp;
}

void AdjustDown(int* a,int n ,int root)
{
  int parent = root;
  int child = parent * 2 + 1;

  while(child <n)
  {

    if( child + 1< n    &&    a[child] < a[child+1] )//child + 1  防止越界
    {
      ++child;
    }
    if(  a[child] > a[parent] )//孩子大于父亲   则进行 交换

    {
      Swap(&a[child], &a[parent]);
      parent =child;
      child = parent * 2 + 1;
    }

    else  //  大孩子小于父亲 ，结束
    {
      break;
    }
  }
}
void Heap(int* a,int n)
{

  //建堆
  for(int i= (n-1-1) /2; i >= 0; --i)// (n-1)/2  为 最后一个非叶子节点的公式
  {
    AdjustDown(a,n,i);
  }
  //现在  我们建好了一个大根堆

  //排序  升序
  int end = n-1;
  while(end >= 0)
  {
    Swap(&a[0], &a[end]);
    AdjustDown(a,end,0);
    --end;
  }
}



void Print(int* a,int n)
{
  for(int i =0; i<n; ++i)
  {
    printf("%d\t",a[i]);
  }
  printf("\n");
}


//大堆
int main()
{
  int a[9] ={2,3,76,3,45,3,6,65,676};
  int n =sizeof(a) / sizeof(int);
  Heap(a,n);
  Print(a,n);

  return 0;
}
