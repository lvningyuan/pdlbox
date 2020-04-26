class Solution {
public:
    string reverseWords(string s1) {
        reverse(s1.begin(), s1.end());
        string s  = "";
        for(int i =0; i< s1.size(); ++i)
        {
            //消灭掉所有影响的空格
            if( (s1[i] ==' ' && s.size()==0) || (s1[i] ==' ' && i+1 < s1.size() && s1[i+1] == ' ') || (s1[i]==' ' && i==s1.size()-1))
            {
                continue;
            }
            s += s1[i];
        }

        //双指针
        int prev =0;
        for(int cur=0; cur<s.size(); ++cur)
        {
            if(s[cur] == ' ')
           {
                reverse(s.begin()+ prev, s.begin()+ cur);
                ++cur;
                prev=cur; 
           }
            if(cur + 1 == s.size())
           {
                reverse(s.begin()+ prev, s.begin()+ cur+1);
           }
        }
        return s;
    }
};