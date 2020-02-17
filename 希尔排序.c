#include  <stdio.h>

//希尔排序 ： 改进插入排序
//思想 ：    预排序   +  插入排序
//           (接近升序)     (有序)
//            预排序本质：将数据进行分组  ，分成 间距为 gap的 几组
//
//          但是预排序 也是需要付出代价的 ，所以 我们需要在预排序代价远小于  直接插入排序的代价时  选择 希尔排序。


void Shell(int* a,int n)
{
  int gap =n;//gap值视数组的大小而定 ，太小效果不明显。
  
  while(gap > 1)//预排序     确定gap实际值   并保证最后一次  gap=1
  {
    gap =gap/3 +1;//保证最后一次  gap = 1
  
    
    
    //下边这些只能使 n/gap 的这些分组 组内有序
    for(int i =0; i < n-gap; ++i)//对比插入排序 gap=1 时不就是插入排序吗？  //++i 是不是设计的很精妙？  类似于多线程的并发操作。
  { 
    int end = i; 
    int tmp = a[end + gap];

    while(end >= 0)
    {
      if(a[end] > tmp)
      {
        a[end + gap] = a[end];
        end -= gap;
      }
      else 
        break;
    }
    a[end + gap]=tmp;
  }
}
}

void Print(int*a ,int n)
{
  for(int i=0; i<n; ++i)
  {
    printf("%d\t",a[i]);
  }
  printf("\n");
}

//Shell  希尔排序的时间复杂度  O（n^1.3    ---n^2)
int main()
{

  int a[9] ={3,56,6,8,2,8,79,24,32};
  int n =sizeof(a)/sizeof(int); 
  Shell(a,n);
  Print(a,n);
  return 0;
}
