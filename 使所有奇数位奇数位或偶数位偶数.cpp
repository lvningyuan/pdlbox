//调整数组。使所有奇数位奇数位或偶数位偶数


题目要求 ： 时间O(n). 空间 O(1)

class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        len =len -1;
        int i =0;//偶数
        int j =1;//奇数
        while (i<=len && j<=len)
        {
            if(arr[len] %2 == 0)
            {
                std::swap(arr[i], arr[len]);//当前最后一位是偶数
                i += 2;
            }
            else 
            {
                std::swap(arr[j], arr[len]);//当前最后一位是奇数
                j += 2;
            }
        }
    }
};


