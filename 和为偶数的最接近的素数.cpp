#include <iostream>
#include <vector>

using namespace std;
bool odd(int x){
    for(int i=2; i*i<=x; ++i)
        if(x % i == 0 )
            return false;
    return true;
}

int main(){
    int n;
    while(cin>>n){
        int mid = n/2;
        int ret1 = -n;
        int ret2 = n;
        
        for(int i=mid; i>=1; --i)
            for(int j=mid; j+i <=n ; ++j)
                if(i+j == n && odd(i) && odd(j) && j-i < ret2 - ret1){
                    ret1 = i; 
                    ret2 = j;
                 }
         cout<<ret1<<endl<<ret2<<endl;
        }
    return 0;
}