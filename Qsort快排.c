#include <stdio.h>

void Swap(int* a, int* b)
{
  int tmp =*a;
  *a = *b;
  *b = tmp;
}

int GetMid(int* a, int begin, int end)
{
  int mid = begin +( (end - begin) >> 1);
  if(a[begin] > a[mid])
  {
    if(a[mid] > a[end])
      return mid;
    if(a[begin] > a[end])
      return a[end];
    else 
      return begin;
  }
  else // a[begin] < a[mid] 
  {
    if(a[begin] >a[end])
      return begin;
    if(a[mid] < a[end])
      return mid;
    else 
      return end;
  }
}


//内部一趟  end  做关键字
int PartQsort(int* a,int begin, int end)//partsort 返回 key 的位置
{

  //end  作关键字 
  int mid =GetMid(a,begin,end);//三数取中法 ，防止 最坏时间复杂度，即 防止数据有序 ：思想：将有序数组先打乱，拿到中位数 做key 再排序
  Swap(&a[end], &a[mid]);

  int key = end;//注意： 选关键字的位置 决定了 先从哪边开始，选关键字为end,先从  左开始， 选关键为begin， 先从 右开始

  //为什么 ？ 开始的方向  决定了 相遇点的数据 跟key的交换   ，而key   又决定了 开始走的方向 
  while(begin < end)
  {
    //end  做key 
    //左边 先走
    while(begin < end  && a[begin] <= a[key])   //begin 找大
    {
      ++begin;
    }

    //右边后走
    while(begin < end  && a[end] >= a[key])  //end找小
    {
      --end;
    }
    Swap(&a[begin], &a[end]);
  }
  Swap(&a[key] , &a[end]);//begin ==  end时  将a[begin]   和 a[key]  交换

  return begin;
  //return end;一样
}




//begin 做关键字
int PartQSort(int* a, int begin, int end)
{
  int key = begin;
  int mid =GetMid(a, begin, end);
  Swap(&a[key], &a[mid]);

  while(begin < end)
  {
    while(begin < end && a[end] >= a[key])//begin  做关键字 右边先走, 右边找小于a[key]的
    {
      --end;
    }

    while(begin < end  && a[begin] <= a[key] )  // 左边后走，找大于a[key]的
    {
      ++begin;
    }

    Swap(&a[begin], &a[end]);
  }
  Swap(&a[key], &a[begin]);
  return begin;//返回交换后关键字的位置//或者相遇点的位置
}
//单趟复杂度， O(n);


//外部大循环
void Qsort(int* a, int left, int right)  //递归  重复进行PartQSort
{
  if(left >= right)//因为 right = keyIndex-1 ;所以 left 也可能大于 right
    return;

  //int  keyIndex = PartQsort(a,left, right);
  int  keyIndex = PartQSort(a,left, right);

  PartQSort(a, left, keyIndex -1);
  PartQSort(a,keyIndex + 1, right);

  //  PartQsort(a, left, keyIndex -1);
  // PartQsort(a,keyIndex + 1, right);
}

//看了外部大循环 类似于二叉树的递归 ，所以时间复杂度为O（log N）
//最坏情况 有序 ，还要排，这样就会一直找，所以最坏 0(n*n)  即 ，每次都取了最末端
//最好情况  每次 keyIndex 都选中了中位数 O(n*logN)
//有序排序 最坏 ，那么快排怎么避免 最坏情况?   三数取中法 ，即 关键字取中间的那个数
int main()
{
  int a[] ={49, 38, 65, 97, 76, 13, 27, 49};
  int n = sizeof(a) / sizeof(int);
  Qsort(a,0,n-1);
  for(int i=0; i<n; ++i)
  {
    printf("%d\t",a[i]);
  }
  printf("\n");
  return 0;
}

