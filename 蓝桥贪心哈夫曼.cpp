#include <iostream>
#include <queue>
#include <vector>

template<class T>
class Less
{
	public:
	bool operator ()(T a, T b)
	{
		return a > b;
	}
};

using namespace std;

int main()
{
	priority_queue<int,vector<int>, greater<int> > q;//这里也可以自己改比较器
	int n;
	cin>>n;
	int x;
	vector<int> v;
	while(n)
	{
		cin >>x;
	  q.push(x);
		--n;
	}
	
	while(q.size() > 1)
	{
		
	  int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		int sum = a + b;
		v.push_back(sum);
		q.push(sum);
	}	
		int ret =0;	
	for(int i=0; i<v.size(); ++i)
	{
		ret += v[i]; 
	}
		cout<<ret<<endl;		

	
	return 0;
}
	