#include <iostream>
#include <string>
using namespace std;

int main()
{
	std::string a[32];
	for(int i =0; i<32; ++i)
	{
		a[i].resize(5,'0');
	}
	
	for(int i =0; i<32; ++i)
	{
		int mod  =i;
		int rest =0;
		int j= 4;
		while(mod != 0)
		{
			rest= mod % 2;
			mod = mod / 2;
			a[i][j] = rest + '0';
			--j;	  	
		}	
	
    cout<< a[i] <<endl;		
	}	
return 0;
}
