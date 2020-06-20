#include <iostream>
#include <vector>
 
using namespace std;

//垃圾牛客 ；还必须循环输入才对 ，垃圾 害的爸爸想来想去哪里错了
int main(){
    int m, n;
    while(cin >> m >> n){
        vector<vector<int>> F(m + 1, vector<int>(n + 1, 1));
        for(int i = 1; i < m + 1; ++i)
            for(int j = 1; j < n + 1; ++j)
                F[i][j] = F[i - 1][j] + F[i][j - 1];
       
        cout << F[m][n] << endl;
    }
    return 0;
}