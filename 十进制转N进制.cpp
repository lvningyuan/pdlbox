#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int M, N;
    cin>>M>>N;
    bool flag = false;
    if(M < 0 ) flag =true, M = -M;

    string ret;
    while(M){
        int t = M % N;
        if(t > 9 )  
            ret += ('A' + t-10);
        else 
            ret += '0' + t;
        M /= N ;
    }
    if(flag) ret += '-';
    reverse(ret.begin(), ret.end());
    cout<<ret<<endl;
    return 0;
}