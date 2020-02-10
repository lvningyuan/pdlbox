#include	 <iostream>

using namespace std;

int main()
{
	int n;
	unsigned long long ret=0;
	
	cin >> n;
	
	ret =(unsigned long long ) (n + 1) * n / 2.0;//注意类型转换
	cout<<ret<<endl;
return 0;
}