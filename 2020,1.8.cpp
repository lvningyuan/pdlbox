#define  _CRT_SECURE_N0_WARNINGS 1
#include"windows.h"
#include"stdio.h"/*
int Mychar(char *str)//�ַ������׵�ַ
{
	if(str=='\0')
		return 0;
	else 
		return 1+ Mychar(str+1);
}
int main()
{
	char *str = "hello";//�ַ���һ��\0����
	int len=Mychar(str);
	return 0;
}
#end if */

#if0
int Fabonaci1(int n)//�ݹ���õݹ����˼��
{}



int Fabonaci2(int n)//�ǵݹ�˼�����ѭ��˼�� f1  f2  f3    
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
//int Hanio(int n, char pos1 ,char pos2,char pos3)//�ƶ�����Ϊ2���������η��ټ�1��//�ݹ�˼��
//{
//
//return 0;
//}
//
//int Move (char pos1,char pos3)//�������һ����pos1ֱ�ӷŵ�pos3
//{
//	
//}





2

���� 
int a1[10]={0];//ȫ��0
int a2[10]={0,1,2,3};//���ȫ��0
int a3[10];//Ĭ�ϴ����ֵ
char a3[5]="hello"//���ᱨ�� ��Ϊ ����Ĭ�ϴ��ַ�����Ĭ�Ϻ�ߴ�һ��'\0���ַ�'\0'ռһ��λ��
 

%s������ӡ�ַ���  ��'\0'��β������Ҳ���'\0'���������   �������̣���û����

�����鳤�� 

int len= sizeof(arr)/sizeof(arr[0]); //ע��    �����������λ��˻���ָ�룬ռ4�ֽ�
   *** arr ����������  ==>   ������Ԫ��   �ĵ�ַ   
   *** []  �Դ�������  
  *** a[i]  ==>  *(arr+1) //������ �� �൱��  ָ��+1  ��ַ�൱�ڼ���   ͬ���ͣ�arr����)���ֽ� һ��
        ͬ��  a[i+n]      ==>  *(arr+2 ,+3,+...)  

 sizeof(arr)��������ռ����ֽ�   
  sizeof(arr[0]) ����0���ַ���С//�ֽ�=�����ֽ�*���鳤��
sizeof����������´��������С

����Խ�粻�ܽ���д��������ʱ��������ֵ 

1 ���� ��ֲ����� �����ջ�� ջһ��1M,����2M��
2 �����ڱ���ʱ ȷ����С
3 ����������ʱ �����ڴ�
4 �������Ϊ1M������2M
5 �����ڴ�ӵ͵�ַ ��ߵ�ַ ��

��ά���� 
int a[2][3];
int a3[3][3]={{1��2}��{3��4��5}��{9��8}} ��ӡ���Ϊ 1��2��0      3��4��5      9��8��0

��ά�����������һά����  C���� �������±�Խ��ʱ Ĭ��Ϊ��һ��    
��Ϊ��C���Զ�ά��������ڴ�ʱ��������



������Ϊ��������



����  
debug     ��     release 

�ֲ���������ջ�У�ջ�׵�ַ����ջ��

vs  ���ƴ����ڱ�λռ����  12λ    �����ʾͳ���  

����Խ�粻������ͱ������ ������ִ����Ž���

#define  _CRT_SECURE_N0_WARNINGS 1
#include"windows.h"
#include"stdio.h"/*
int Mychar(char *str)//�ַ������׵�ַ
{
	if(str=='\0')
		return 0;
	else 
		return 1+ Mychar(str+1);
}
int main()
{
	char *str = "hello";//�ַ���һ��\0����
	int len=Mychar(str);
	return 0;
}
#end if */

#if0
int Fabonaci1(int n)//�ݹ���õݹ����˼��
{}



int Fabonaci2(int n)//�ǵݹ�˼�����ѭ��˼�� f1  f2  f3    
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
//int Hanio(int n, char pos1 ,char pos2,char pos3)//�ƶ�����Ϊ2���������η��ټ�1��//�ݹ�˼��
//{
//   if(n==1)
 //    Move(pos1,pos3);
//	 else
//   Hanio(n-1;pos1,pos2,pos3); 
//return 0;
//}
//
//int Move (char pos1,char pos3)//�������һ����pos1ֱ�ӷŵ�pos3
//{
//	printf("pos1->pos3%d%d ");
//}

