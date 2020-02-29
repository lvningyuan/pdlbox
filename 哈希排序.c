#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  Haxi(int*a ,int n)
{
  int min = a[0];
  int max = a[0];

  for(int i=0; i<n; ++i)
  {
    if(a[i] > max)
      max = a[i];
    if(a[i] < min)
      min = a[i];
  }

  int range = max - min + 1;
  int* countA = (int*) malloc(sizeof(int) *range );//calloc
  memset(countA, 0, sizeof(int) * range);

  for(int i =0; i<n; ++i)
  {
    countA[a[i] - min]++;//countA 存出现的次数， 但数据是相对位置 
  }

  int j = 0;
  for (int i=0; i < range; ++i)//range是相对范围 ，所以i 也是相对
  {
    while(countA[i]-- )
      a[j++] = i + min;
  }
  free(countA);

}


void Print(int* a, int n)
{
  for(int i=0; i<n; ++i)
  {
    printf("%d\t", a[i]);
  }
  printf("\n");
}

int main()
{
  int a[] = {6,7,5,4,4,5,6,7,6,5,4,3};
  int n =sizeof(a) / sizeof(int);
  Haxi(a, n);
  Print(a,n);
  return 0;
}
