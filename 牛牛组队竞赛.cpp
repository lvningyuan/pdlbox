链接：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b
来源：牛客网

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
 
 
 
long helper(vector<int>& v,int n){
    long sum=0;
    sort(v.begin(),v.end());
    for(int i=n;i<3*n;i+=2){
        sum += v[i];
    }
    return sum;
}
 
 
 
 
int main(){
    int n,t;
    long sum=0;
    vector<int> v;
    cin>>n;
    for(int i=0;i<3*n;i++){
        cin>>t;
        v.push_back(t);
    }
    cout<<helper(v,n)<<endl;
    return 0;
}