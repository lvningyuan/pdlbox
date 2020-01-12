class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st;
        for(auto& x:s) if(x>='A'&&x<='Z'||x>='a'&&x<='z') 
          st.push(x);//½«×Ö·û´®ÖÐµÄ×Ö·ûÄÃ³öÀ´
        for(auto& x:s) if(x>='A'&&x<='Z'||x>='a'&&x<='z')           {
            x=st.top(); //ÔÙÅÐ¶Ï×Ö·û´®µÄÔªËØ£¬ÊÇ×Ö·û£¬¾ÍÌæ»»
            st.pop();
            }
        return s;
    }
};