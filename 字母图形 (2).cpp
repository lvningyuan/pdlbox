#include <iostream>
#include <string>

using namespace std;

int main()	
{
		std::string a;
		int n,m;
		cin>>n;
		cin>>m;
		a.resize(m,'0');
		
	for(int i=0; i<m;++i)
	{
			a[i]='A'+i;		
	}
	
	std::string s[n];
	s[0] =a;
	cout<<s[0]<<endl;
	for(int i=1; i<n; ++i)
	{
      s[i].resize(m);
			string tmp =a;
			tmp.resize(m-1);
      tmp = a[i] + tmp;
      s[i] = tmp; 
			cout<<s[i]<<endl;
	}
	
	return 0;
}
