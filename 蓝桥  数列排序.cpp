��������
��������һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
�����ʽ
������һ��Ϊһ������n��
�����ڶ��а���n��������Ϊ�����������ÿ�������ľ���ֵС��10000��
�����ʽ
�������һ�У�����С�����˳��������������С�

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;
int main()
{
	vector<int>v;
	v.resize(200,0);
	
	int n;
	cin>>n;
	
	int data;
	for(int i =0; i<n; ++i)
	{
		cin>>data;
		v[i] = data; 
	}
	
	if(n == 1)
	{
			cout<<data<<endl;
			return 0;
	}
	
	sort(v.begin(), v.begin()+n);
	for(int j =0; j<n; ++j)
	{
		printf("%d\t",v[j]);
	}
	
	cout<<endl;
return 0;
}