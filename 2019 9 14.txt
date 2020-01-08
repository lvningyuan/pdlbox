#define  _CRT_SECURE_N0_WARNINGS 1
#include"windows.h"
#include"stdio.h"/*
int Mychar(char *str)//字符串存首地址
{
	if(str=='\0')
		return 0;
	else 
		return 1+ Mychar(str+1);
}
int main()
{
	char *str = "hello";//字符串一次\0结束
	int len=Mychar(str);
	return 0;
}
#end if */

#if0
int Fabonaci1(int n)//递归采用递归调用思想
{}



int Fabonaci2(int n)//非递归思想采用循环思想 f1  f2  f3    
{
	int f1=1;
	int f2=1;
	int f3=0;
	int i=0;
	for(i=3;i<n;i++)
	{
		f3=f1+f2;
	    f1=f2;
	    f2=f3;
		printf("%d\n",f3);
	}
		return f3;
}
#endif

//
//int Hanio(int n, char pos1 ,char pos2,char pos3)//移动次数为2的盘子数次方再减1；//递归思想
//{
//
//return 0;
//}
//
//int Move (char pos1,char pos3)//将在最后一个从pos1直接放到pos3
//{
//	
//}





2

数组 
int a1[10]={0];//全是0
int a2[10]={0,1,2,3};//后边全是0
int a3[10];//默认存随机值
char a3[5]="hello"//将会报错 因为 “”默认存字符串，默认后边存一个'\0’字符'\0'占一个位置
 

%s用来打印字符串  以'\0'结尾，如果找不到'\0'，将会输出   烫烫烫烫，，没意义

求数组长度 

int len= sizeof(arr)/sizeof(arr[0]); //注意    ：数组名传参会退化成指针，占4字节
   *** arr 数组名代表  ==>   数组首元素   的地址   
   *** []  自带解引用  
  *** a[i]  ==>  *(arr+1) //解引用 ： 相当于  指针+1  地址相当于加了   同类型（arr类型)的字节 一次
        同理  a[i+n]      ==>  *(arr+2 ,+3,+...)  

 sizeof(arr)代表数组占多大字节   
  sizeof(arr[0]) 代表0号字符大小//字节=类型字节*数组长度
sizeof在两种情况下代表数组大小

数组越界不能进行写操作，读时会出现随机值 

1 数组 或局部数组 存放于栈中 栈一般1M,或者2M；
2 数组在编译时 确定大小
3 数组再运行时 分配内存
4 数组最大为1M，或者2M
5 数组内存从低地址 向高地址 走

二维数组 
int a[2][3];
int a3[3][3]={{1，2}，{3，4，5}，{9，8}} 打印结果为 1，2，0      3，4，5      9，8，0

二维数组是特殊的一维数组  C语言 再数组下标越界时 默认为下一个    
因为在C语言二维数组分配内存时是连续的



数组作为函数参数



调试  
debug     和     release 

局部变量存在栈中，栈底地址高于栈顶

vs  机制存在哨兵位占两格  12位    ，访问就出错  

数组越界不是立马就报错崩溃 ，而是执行完才结束

#define  _CRT_SECURE_N0_WARNINGS 1
#include"windows.h"
#include"stdio.h"/*
int Mychar(char *str)//字符串存首地址
{
	if(str=='\0')
		return 0;
	else 
		return 1+ Mychar(str+1);
}
int main()
{
	char *str = "hello";//字符串一次\0结束
	int len=Mychar(str);
	return 0;
}
#end if */

#if0
int Fabonaci1(int n)//递归采用递归调用思想
{}



int Fabonaci2(int n)//非递归思想采用循环思想 f1  f2  f3    
{
	int f1=1;
	int f2=1;
	int f3=0;
	int i=0;
	for(i=3;i<n;i++)
	{
		f3=f1+f2;
	    f1=f2;
	    f2=f3;
		printf("%d\n",f3);
	}
		return f3;
}
#endif

//
//int Hanio(int n, char pos1 ,char pos2,char pos3)//移动次数为2的盘子数次方再减1；//递归思想
//{
//   if(n==1)
 //    Move(pos1,pos3);
//	 else
//   Hanio(n-1;pos1,pos2,pos3); 
//return 0;
//}
//
//int Move (char pos1,char pos3)//将在最后一个从pos1直接放到pos3
//{
//	printf("pos1->pos3%d%d ");
//}

