class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int j=0;
	for(int star=0,i=0,last=0;  i<s.size(); ){
		if(j<p.size()  &&  (s[i]==p[j] || p[j]=='?')  ){
			++i;
			++j;}//匹配成功一起继续走

		else if(j<p.size() && p[j]=='*'){
			last = i;//记录上次走到s串的位置
			star = ++j;}//记录p串 * 的下一个位置
                        

//若已存在 * 
		else if(star != 0){
			i = ++last;// i从s串不匹配的位置开始匹配比较
			j = star;}//j也是*的下一个位置

//不存在 *  ？ 且不匹配
		else 
            return false;
		}

		for(; j<p.size() && p[j] == '*'; ++j)  
            ;  //将多余的*跳过
		return j==p.size();//判断是否走到p串结尾
  }
};