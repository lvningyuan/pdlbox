给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


1  


class Solution {
public:
    int reverse(int x) {
        if(x == 0)
            return x;

        queue<int > s;

        long long x1 = x;
        int flag  =0;
        if(x1 < 0 )
        {
            flag = -1;
             x1 *=  -1;
        }
        else 
            flag = 1; 

        bool begin = false;
        while(x1)
        {
            if(x1 % 10 == 0 && begin == false)
            {
                x1 /= 10;
            }
            else
            {
                s.push(x1 % 10);
                x1 = x1 /10;
                begin = true;
            }
        }

        while(! s.empty())
        {
            if(flag ==1 && x1  > ((int)pow(2.0,31) - 1 - s.front()) / 10 )
                 return 0;
            else if(flag == -1 && x1 > ((int)pow(2.0,31) -s.front()) / 10 )
                 return 0;
            
            else
            x1 = x1 * 10 + s.front();
            s.pop(); 
        }

        if(flag == -1)
            return (int)x1 * (-1);
        
        return (int)x1;
    }
};



2

class Solution {
public:
    int reverse(int x) {
     long n = 0;
     bool begin = false;
     while(x)
     {
         if(x% 10 == 0 && begin == false)
            x /=10;
        else
        {
            n = n * 10 + x % 10;
            x /= 10;
            begin = true;
        } 
     }
        int x1 = n;
        return  n== (long)x1? x1 :0 ; 
    }
};