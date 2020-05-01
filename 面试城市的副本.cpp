平方数之和。： 二分法

class Solution {
public:

    bool isPerfectSquare(int num) {
    int  low = 1;
    int high = num;
    
    while(low < high)
    {
       int mid = low + ((high -low)>>1);
       if(mid >= num /mid) //主要是防止溢出
            high = mid;
        else
            low = mid+1;
    } 
    return  (long long int)low * low ==num;
    }
};


class Solution {
public:

    bool isPerfectSquare(int num) {
        int n =1;
        while(num >= n)
        {
            num -= n;
            n += 2;
        }
        return num==0;
    }
};