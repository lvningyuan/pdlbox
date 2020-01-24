class Solution {
public:
    vector<vector <int> > subsets(vector<int>& nums) {
        vector<vector<int>> res(1);//二维数组设1个空的数组
        for(int i =0; i< nums.size(); ++i)//遍历目标数组
        {
            int size =  res.size();//记录现有的res数组大小
            for(int j=0; j<size; ++j)//在现有的数组上进行追加，形成新的组合，放入res数组
            {
                vector<int> tmp = res[j];//每趟进来，从res数组的第一个直到末尾进行追加
                tmp.push_back(nums[i]);//吧目标?新元素逐个追加，形成新组合
                res.push_back(tmp);//新组合放入res数组
            }
        }
        return res;
    }
};