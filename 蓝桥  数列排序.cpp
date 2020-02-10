问题描述
　　给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
输入格式
　　第一行为一个整数n。
　　第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
输出格式
　　输出一行，按从小到大的顺序输出排序后的数列。

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