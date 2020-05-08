#include <iostream>
#include <string>
#include <vector> 
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int len = s.size();
    vector<int> cnt(len);
    vector<vector<int>> ishw(len,vector<int>(len));
    //DP思想
    for (int i = 1; i < len; ++i) {
        cnt[i] = cnt[i-1] + 1;//先得到当前最坏情况
        for (int j = i; j >= 0; --j) {
            //i-j<2即i==j || i =j+1    否则；只需看外部最大串是不是回文串
            if (s[i] == s[j] && (i - j < 2 || ishw[j+1][i-1])) {
                ishw[j][i] = 1;
                
                //无论当前子串是不是回文串，都需要计算切割次数
                //当j为0是说明在边界，不用切割。
                //当j不为0时，说明是串内部的，所以需要在之前切割的基础上，再切割一次
                cnt[i] = min(j == 0 ? 0 : cnt[j-1] + 1, cnt[i]);//动态衡量
            }
        }
    }
    cout << cnt[len-1] << endl;
    return 0;
}
