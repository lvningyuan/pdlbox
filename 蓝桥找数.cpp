#include  <iostream>

using namespace std;

int main()	
{
	int n;
	int max;
	int min;
	int sum=0;
	
	
	cin>>n;
	int data;
	cin>>data;
	max = min = sum =data;
	for(int i=1; i<n; ++i)
	{
		cin >> data;
			 if(max < data)
				 max = data;
			 if(min > data)
				 min = data;
			sum +=data;
	}
		
	cout<<max<<endl;
	cout<<min<<endl;
	cout<<sum<<endl;
	return 0;
}