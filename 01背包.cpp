//A :商品空间大小      V：商品价值大小
int backPack(int m, vector<int>&A, vector<int> & V)
{
  int n =A.size();//n：商品个数      m：背包大小
  //初始化F(i,0) = F(0,j) = 0
  vector<vector<int>> maxValue(n+1,vector<int>(m+1,0));
  for(int i=1; i<=n; ++i)//第i 个商品品
  {
    for(int j=1; j<=m; ++j)//有j个空间
    {
     //因为我们下标从1开始，所以实际下表应该从i-1开始
    
      if(A[i-1] > j)//当前商品空间大于背包空间了  返回上一个商品进入的最大价值
        maxValue[i][j] = maxValue[i-1][j];
      else//否则，该商品加入：  1 剩余空间够   2  剩余空间不够，需要取出商品再放入当前商品 
        maxValue[i][j] = max(maxValue[i-1][j],  maxValue[i-1][j-A[i-1]] + V[i-1]);
    }
  }
  return maxValue[n][m];
}





优化：


```cpp
//A :商品空间大小      V：商品价值大小
int backPack(int m, vector<int>&A, vector<int> & V)
{
  int n =A.size();//n：商品个数      m：背包大小
  //初始化F(i,0) = F(0,j) = 0
  vector<int> maxValue(m+1,0));
  for(int i=1; i<=n; ++i)//第i 个商品品
  {
  //一维数组时：这里存在更新问题 ：  当前商品的选择与否，受到上一行商品对应数据的影响，而我们只有一行，那么怎么体现上一行呢？
  //上一 行的数据其实就是没有更新之前的数据，我们正向走的话，ke neng会导致将本行数据当作上一行了， 
  //解决策略： 反向走，前边的数据肯定没被更新
  
    for(int j=m; j>=1; --j)//有j个空间
    {
     //因为我们下标从1开始，所以实际下表应该从i-1开始
//因为只有一维数组，那么行的概念不存在了
		//当当前商品空间 <= 背包空间，更新，否则，不用更新
      if(A[i-1] <= j)//当前商品空间大于背包空间了  返回上一个商品进入的最大价值
        maxValue[j] = max(maxValue[j], maxValue[j-A[i-1]] + V[i-1]);
    }
  }
  return maxValue[m];返回最大空间时的value
  //m不是说m个空间全装满了，只是说明计算到了m这个地方的最大value
}
```
