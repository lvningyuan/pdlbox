class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int ret = 0;
        int flag = 0;//��¼��ľ�п�ʼ  �������
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