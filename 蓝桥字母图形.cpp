#include <iostream>
#include <string>

using namespace std;

int main()	
{
		std::string a;
		int n,m;
		cin>>n;
		cin>>m;
		a.resize(26,'\0');
		
	for(int i=0; i<26;++i)
	{
		a[i]='A'+i;		
	}
	
	std::string s[n];
	s[0] =a;
	s[0].resize(m);
	cout<<s[0]<<endl;
	string tmp =a;

  for(int i=1; i<n; ++i)
	{
      		s[i].resize(m);
		tmp.resize(m-1);
      		tmp = a[i] + tmp;
      		s[i] = tmp; 
		cout<<s[i]<<endl;
	}
	
	return 0;
}
