#include <stdio.h>
#include <stack>

void Swap(int*a ,int*b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int  Partsort(int* a, int left, int right)
{

  int key = right;//右边作为key，左边开始先走
  while(left < right)
  {
    //左边先走，找大
    while(left < right  && a[left] <= a[key])
    {
      ++left;
    }

    //右边后走 ，找小
    while(left < right && a[right] >= a[key])
    {
      --right;
    }

    Swap(&a[left], &a[right]);
  }
  Swap(&a[key], &a[left]);//此时 left = right
  return left;
}

//非递归 ，其实还是利用 递归的想法
void Qsort(int* a, int begin ,int end)
{
  std::stack<int> b;
  b.push(begin);
  b.push(end);


  while(!b.empty())
  {
    int end1 = b.top();
    b.pop();
    int begin1 = b.top();
    b.pop();

    int keyIndex = Partsort(a,begin1,end1);

    if(begin1 < keyIndex - 1) //keyIndex 判断左右元素数量，需不需要再push
    {
    b.push(begin1);
    b.push(keyIndex - 1);
    }
    
    if(keyIndex + 1 < end1)
    {
    b.push(keyIndex + 1);
    b.push(end1);
    }
  }
}

void Print(int* a, int n)
{
  for(int i=0; i<n; ++i)
    printf("%d\t",a[i]);
  
  printf("\n");
}


int main()
{
  int a[] = {4,5,6,8,7,3,8};
  int n = sizeof(a) / sizeof(int);
  Qsort(a , 0, n-1);
  printf("hello\n");

  Print(a, n);
  return 0;
}
