二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。




//就是每四行四列为一个周期pattern相同如下的图案：
＊＊    ＊＊   ＊＊
＊＊    ＊＊   ＊＊
    ＊＊   ＊＊   ＊＊
    ＊＊   ＊＊   ＊＊
＊＊    ＊＊   ＊＊
＊＊    ＊＊   ＊＊




#include<iostream>
using namespace std;
int a[1000][1000] = {0};
int main()
{
    int w,h,res = 0;
    cin >> w >> h;

    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(a[i][j]==0)
            {
                res++;
                if((i+2)<w) a[i+2][j] = -1;
                if((j+2)<h) a[i][j+2] = -1;
            }
        }
    }
    cout << res;
    return 0;
}