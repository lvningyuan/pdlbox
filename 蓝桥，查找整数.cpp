#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	cin>>n;
	while(n)
	{
	
		int data;
		cin>>data;
		v.push_back(data);
		--n;
	}
	int ret;
	cin>>ret;
	for(int i =0; i<v.size();++i)
	{
	if(v[i] == ret)
	{
		cout<<i+1<<endl;
		return 0;
	}
	}
	cout<<-1<<endl;
	
return 0;
}