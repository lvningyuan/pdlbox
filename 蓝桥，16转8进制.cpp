#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int main()	
{
	std::string a[10];
	int b[10] = {0};
	//std::string c[10];
	int n;
	cin >>n;
	
	for(int i =0; i<n; ++i)
	{
     std:: string tmp; 
		 cin >> tmp;
     a[i] = tmp;
	}

//16  to   10	
	int time1 =clock();
  for(int i =0; i< n; ++i)
	{ 
		int len = a[i].size();
		int ret = 0;
			for(int j =0; j < len; ++j)
		{
			reverse(a[i].begin(),  a[i].end() );
			 if (a[i][j]  > '9')
			 {
				  ret +=(int) (a[i][j] - 'A' + 10) * pow(16.0 , j);
			 }
				else
				{
					ret +=(int)  (a[i][j] - '0') * pow(16.0, j);
				}
		}
		b[i] = ret;
	}
	
	//10  to  8  ณýม๔ำเ
	for(int i = 0; i < n; ++i)
	{
			int rest = 0;
			int mod = 0;
			string tmp;
      tmp.resize(20);
		  int j =0;
		
		do
		{	
		  mod = b[i] /8;
			rest = b[i] %8;
		  
      tmp[j] = rest + '0';

			b[i] = mod;
			j++;
	  }	while( mod != 0 );
      
      if(b[j-1] == '0' )
        tmp.resize(j-1);
    tmp.resize(j);
    
      reverse(tmp.begin(), tmp.end() );
      cout<<tmp<<"  ";
  }
  cout<<clock() - time1<<endl;
		return 0;
}
