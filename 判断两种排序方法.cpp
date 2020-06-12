#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> v;
    while(n){
        string tmp;
        cin>>tmp;
        v.push_back(tmp);
        --n;
    }
    string ret_1 = "lexicographically";
    bool ret_11 = true;
    string ret_2 = "lengths";
    bool ret_22 = true;
    
    for(int i=1; i<v.size(); ++i){
        if(v[i-1] > v[i]){
            ret_11 = false;
            break;
        }
    }
     for(int i=1; i<v.size(); ++i){
        if(v[i-1].size() > v[i].size()){
            ret_22 = false;
            break;
        }
    }
    
    if(ret_11 && ret_22)
        cout<<"both"<<endl;
    else if(ret_11)
        cout<<ret_1<<endl;
    else if(ret_22)
        cout<<ret_2<<endl;
    else 
        cout<<"none"<<endl;
    return 0;
}