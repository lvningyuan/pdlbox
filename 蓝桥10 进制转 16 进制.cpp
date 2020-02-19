#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >>n;
	if(n == 0)
	{	
		cout<<0<<endl;
		return 0;
	}
	
	std::string ret;
	
	int mod=n;
	while(mod)
	{
		int rest =mod%16;
		  mod =mod/16;
			if(rest <10)
				ret.push_back(rest +'0');
			else
				ret.push_back(rest -10 +'A'); 
	}		
	
	reverse(ret.begin(), ret.end());
	cout<<ret<<endl;
	return 0;
}