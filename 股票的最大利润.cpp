class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() ==0 )
            return 0;
    
    //获取最低成本
    int buy  = 0;
    int sell = 0;
    int tmpEarn= 0;//暂时利润
    int maxEarn =0;//最大利润

    for(int i=0; i < prices.size(); ++i )
    {
        if(prices[i] < prices[buy]) //降价中
            buy = i; //换今天买入
        
        //否则 （+不加else都行，）
        tmpEarn = prices[i] - prices[buy];//计算当前利润
        //判断是否大于之前的利润，大于就更新
        maxEarn = maxEarn  > tmpEarn ? maxEarn : tmpEarn;
    }
        return maxEarn;  
    }
};