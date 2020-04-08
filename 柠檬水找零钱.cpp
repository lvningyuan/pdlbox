在柠檬水摊上，每一杯柠檬水的售价为 5 美元。

顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

如果你能给每位顾客正确找零，返回 true ，否则返回 false 。



class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> W; W.resize(0);
        vector<int> S; S.resize(0);
        vector<int> ES; ES.resize(0);
        for(int i = 0; i < bills.size(); ++i)
        {
            if(bills[i] == 5)
                W.push_back(5);
            else if(bills[i] == 10)
            {
                if(W.size() == 0)
                    return false;
                W.resize(W.size()-1);
                S.push_back(10);
            }
            else 
            {
                if(W.size() == 0)
                    return false;
                if(S.size() ==0 && W.size() < 3 )
                    return false;
                if(S.size() ==0 && W.size() >=3 )
                    W.resize(W.size()-3);
                else 
                {
                    W.resize(W.size()-1);
                    S.resize(S.size()-1);
                } 
                ES.push_back(20);
            }
        }
            return true;
    }
};


贪心思想 ：找零15元时，有10元尽力别用5元
优化 ：
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int W = 0;
       int S = 0;
       int ES =0;
        for(int i = 0; i < bills.size(); ++i)
        {
            if(bills[i] == 5)
                W++;
            else if(bills[i] == 10)
            {
                if(W == 0)
                    return false;
                --W;
                S++;
            }
            else 
            {
                if(W == 0)
                    return false;
                if(S == 0 && W < 3 )
                    return false;
                if(S == 0 && W >=3 )
                    W -= 3;
                else 
                {
                    --W;
                    --S;
                } 
                ++ES;
            }
        }
            return true;
    }
};



