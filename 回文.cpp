class Solution {
public
    bool isPalindrome(string s) {
        int len = s.size();
        string a;
        for(int i =0; ilen; ++i)
        {
            if(s[i] ='a' && s[i] ='z' )
            {
                s[i]= s[i] - 32;
                a += s[i];
            }
            else if(s[i] ='0' && s[i]= '9')
            {
                a += s[i];
            }
            else if(s[i]='A' && s[i] = 'Z')
            {
                a +=s[i];
            }
        }
        int right= a.size()-1 ;
        for(int i=0; iright; ++i)
        {
            if(a[i] != a[right])
                return false;         
            --right;
        }
        return true;
    }
};