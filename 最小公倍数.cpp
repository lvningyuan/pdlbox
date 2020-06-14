#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >>a>>b;
    int ret; 
    int Min = min(a,b);
    int sub=1;
    for(int i=2; i<=Min; ++i){
        if(a%i == b%i && a%i==0)
            sub = i;
    }
    ret = a * b / sub;
    cout<<ret<<endl;
    return 0;
}