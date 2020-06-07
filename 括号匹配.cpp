class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        if(n%2) return false;
        stack <char> s;
        vector<char> mp(128,' ');
        mp['<'] ='1';
        mp['('] ='1';
        mp['{'] ='1';
        mp['['] ='1';
        mp['>'] ='1';
        mp[')'] ='1';
        mp['}'] ='1';
        mp[']'] ='1';
        for(char e : A){
            if(mp[e] != '1' ) continue;
            if( e=='(' || e=='<'|| e=='{' || e=='[' )
                s.push(e);
            else {
                if(s.empty()) return false;
            else if( e== ')' && s.top() =='(')
                s.pop();
            else if( e== '>' && s.top() =='<')
                s.pop();
            else if(e == ']' && s.top() =='[')
                s.pop();
            else if(e == '}' && s.top() =='{')
                s.pop();
            else 
                return false;
            }
        }
        if(s.empty()) 
            return true;
        return false;
    }
};