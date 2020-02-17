#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int main()
{
	std::string input;
	
	cin>>input;
	
	unsigned long long ret =0;
	int len = input.size();
	for(int i= len-1; i >= 0; --i)
	{
		int w;
		if( input[i] > '9')
			w = input[i] - 'A' +10;
		else
			w = input[i] - '0';
		
			ret += (unsigned long long) (pow(16.0,len-i-1) * w);
	}
	cout<<ret<<endl;
	
return 0;
}