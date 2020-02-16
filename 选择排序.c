#include <stdio.h>

void Swap(int* a ,int *b)
{
  int tmp =*a;
  *a= *b;
  *b =tmp;
}


void Select(int* a, int n)
{
   int begin =0;
   int end = n-1;
   int max = begin;
   int min = begin;
   
   while(begin < end)
   {
   
     for(int i=begin; i<=end;  ++i)
   {
     if( a[max] < a[i] )
     {
       max =i;
     }
     if( a[min] >a[i])
     {
        min =i;
     }
   }
     Swap(&a[begin], &a[min]);
      if(  begin == max )//假如 开始就是最大的，就注意下标变化
          max = min;
     Swap(&a[end], &a[max]);
     
     ++begin;
     --end;
   }
}

void Print(int*a , int n)
{
  for(int i = 0; i<n ;++i)
  {
    printf("%d\t",a[i]);
  }
  printf("\n");
}

int main()
{
   int a[9]= {21,34,5,6,7,77,43,343,3};
   int n =sizeof(a)/sizeof(int);
   Select(a,n);
   Print(a,n);
  return 0;
}
