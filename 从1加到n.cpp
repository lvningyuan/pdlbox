

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。



1 ：时间复杂度 O（N）
class A
{
    public:
    A()
    {
        tmp++;
        sum += tmp;
    }
    
 static int sum;
 static int tmp;
};
int A::sum =0; 
int A::tmp =0;

class Solution {
public:
    int Sum_Solution(int n) {
        //每次进入测试前前清空上次数据
        A::sum =0;
        A::tmp =0;
        A* t = new A[n];
        //delete []t;
        return A::sum;
    }
};


class Solution {
public:
    Solution(){ tmp++;  sum += tmp; }
    
    int Sum_Solution(int n) {
        tmp =0; sum = 0; //每次测试前重置数据
        Solution* A = new Solution[n];
        delete []A; A = nullptr;//防止内存泄漏
        return sum;
    }
    
    static int sum;//静态成员类外初始化
    static int tmp;
};
int Solution::sum = 0;
int Solution::tmp = 0;
