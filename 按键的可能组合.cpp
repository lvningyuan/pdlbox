class Solution {

public:

    string multiply(string num1, string num2) {

     if(num1 == "0" || num2 =="0")

        return "0";



     int l1 = num1.size();

     int l2 = num2.size();



    //a 位数 * b位数 可能是 a+b位数 也可能是 a+b -1 位数

     string ret(l1+l2, '0');

    //int add =0;

    for(int i =l1-1; i >=0; --i)

    {

        int add =0;

        for(int j=l2-1; j>=0; --j)

        {

            //暂时成乘积

            int mul = (num1[i] - '0') * (num2[j] - '0');

            //当前位暂时和

            int sum = mul + add + ret[i+j+1] -'0'; 

            add = sum / 10;//进位

            ret[i+j+1] = sum % 10 + '0';//最终存储

        }

        ret[i] += add;// 最后一位可能会进位

    }

    //结果为a+b -1 位数的情况

    if(ret[0] == '0')

        return ret.substr(1);

    

    return ret;



    }

};