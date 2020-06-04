class Solution {
public:
    int distributeCandies(vector<int>& candies) {

        // 为了节省空间 我们 牺牲一旦时间
        //或者 节省时间 用哈希浪费点空间就行了
        sort(candies.begin(), candies.end());
        int len = candies.size();
        int tmp = candies[0];
        int count = 1;
        for(int i=1; i<len; ++i)
            if(candies[i] != tmp){
                ++count;
                tmp = candies[i];
            }

//统计种类 ： 再尽量将更多种类的分给妹子
        if (2 * count >= len) //种类多余🍬个数一半  
            return len/2;
        return count;//少于一半 ，妹妹啥样的都给一份
    }
};