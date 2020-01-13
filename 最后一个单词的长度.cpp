class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int ret = 0;
        int flag = 0;//记录有木有开始  进入计数
        for(int i =len - 1; i >= 0; --i)
        {
            if(s[i] != ' ' )
            {
               ++ret;
               flag = 1;
            }
            if( s[i] == ' ' && flag == 1)
            break;
        }
        return ret;
    }
};