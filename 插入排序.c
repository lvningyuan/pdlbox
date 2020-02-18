#include <stdio.h>

void insert(int* a, int n)//a 数组 ，数组 有 n个数据
{

  for(int i=0; i<n-1 ; ++i)//插入的元素一直为最后一个元素的，所以趟数为 n-1趟
  {
    //单趟
    int end = i;//每趟的最后一个位置  开始

    //tmp为要插入的数据
    int tmp = a[end+1];//要插入的数据  ===  该趟最后数据的下一个数据
    while(end >= 0)
    {
      if(a[end] > tmp)//新插入数据小，前边元素挨个向后移动一个位置
      {
        a[end+1] = a[end];
        --end;  
      }
      else //否则  退出 ，直接给最后边接着插
      {
        break;//tmp 大
      }
    }

    a[end + 1] = tmp;  //直接给后边插
    //单趟

  }

}
//插入排序的时间复杂度 O(n^2)  逆序最坏

void PrintInsert(int* a,int n)
{
  for (int i=0; i <n; ++i)
  {
    printf("%d\t",a[i]);
  }
  printf("\n");
}



int main()
{
  int a[9] ={8,0,2,1,9,4,43,54,5};
  int n =sizeof(a) /sizeof(int);
  insert(a,n);
  PrintInsert(a,n);

  return 0;
}
