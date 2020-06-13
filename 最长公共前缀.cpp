class Solution {
public:
  int  getShortLen(vector<string>& strs){
      int min = strs[0].size();
      for(int i = 1; i<strs.size(); ++i){
          if(strs[i].size() < min)
            min = strs[i].size();
      }
      return min;
  }
 
    string longestCommonPrefix(vector<string>& strs) {  
         string dst = "";
         int size = strs.size();//字符串个数
         if(size == 0)
            return dst;

         int i = 0;//第几个字符串
         int j = 0; //字符串第几个元素
         int len = getShortLen(strs);
         
         for(int j =0; j < len; ++j){
            for(int i = 1; i < size; ++i ){
                if(strs[0][j] != strs[i][j]) 
                    return dst;//一旦不同立马结束
            }
            //否则大家这一位都相同
                dst += strs[0][j];
         }
        return dst;
    }
};