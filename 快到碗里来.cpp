#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
     string n;
     string num1;
     while(cin>>n>>num1){
         string num2 = "628";
         int l1=num1.size(),l2=num2.size();
         string res(l1 + l2,'0');
         for(int i=l1-1; i >= 0; i--){
             int add=0;//进位
             for(int j=l2-1; j>=0; j--){
                 int mul = (num1[i] - '0') * (num2[j] - '0');//暂时乘积
                 int sum = res[i+j+1] + add + mul % 10 - '0';//该位暂时相加和
                 res[i+j+1] = '0' + sum % 10; //实际存储
                 add = mul / 10 + sum / 10; // 计算进位
             }
             res[i] + = add;//存储本轮最终进位
         }
    
//消除前边的‘0’
          for(int i=0;i<l1+l2;++i){
              if(res[i] != '0')
                  break;
              res = res.substr(i+1); 
          }
        if( res >= n)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0;
}