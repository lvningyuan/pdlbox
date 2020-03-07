编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
  int  getShortLen(vector<string>& strs)
  {
      int min = strs[0].size();
      for(int i = 1; i<strs.size(); ++i)
      {
          if(strs[i].size() < min)
            min = strs[i].size();
      }
      return min;
  }
 
    string longestCommonPrefix(vector<string>& strs) {
        
         string dst;
         int size = strs.size();//字符串个数
        if(size == 0)
            return dst;
            
         int i = 0;//第几个字符串
         int j = 0; //字符串第几个元素
         int len = getShortLen(strs);
        for(int j =0; j < len; ++j)
        {
        for(int i = 1; i < size; ++i )
        {
            if(strs[0][j] != strs[i][j])
            {
                return dst;
            }
        }
            dst += strs[0][j];
        }
        return dst;

    }
};