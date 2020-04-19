class Solution {
public:
    bool isPalindrome(string s) {
        string tmp ="";
        for(int i=0; i<s.size(); ++i)
        {
            if( (s[i] >= '0'&&s[i]<='9' ) || (s[i] >= 'A' && s[i] <='Z') ||(s[i] >='a' && s[i] <= 'z') )
            {
                if(s[i] >= 'a' && s[i] <= 'z' )
                  tmp +=s[i] -32;
                else
                    tmp += s[i];
            }
        }
       int l =0; int r = tmp.size()-1;
       while(l < r )
       {
           if(tmp[l] != tmp[r])
           {
               return false;
           }
           --r;
           ++l;
       }
       return true;

    }
};