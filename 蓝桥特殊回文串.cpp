#include <iostream>
#include <vector>

using namespace std;

bool isRight(int i,int data)
{
	vector <int>v1;
	
	while(i)
	{
	  v1.push_back(i%10);
		i = i/10;
	}
	
	int len = v1.size();
	for(int k =0; k<=len-k-2; ++k ) 
	{
	  if( v1[k] != v1[len-1-k])
			return false;
	}
	
	int ret=0;
	for(int k= 0;  k<len; ++k)
	{
			 ret +=v1[k];
	}
	
	if(ret != data)
		return false;
	
	return true;
}


int main()
{
	int data;
	cin>> data;
	for(int i =10000;i<1000000; ++i)
	{
		if( isRight(i,data) )
		{
				cout<<i<<endl;			
		}
	}
	
return 0;
}