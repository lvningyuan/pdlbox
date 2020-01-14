class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int len = typed.size();
        int j =0;
        for(int i =0; i < len; ++i)
        {
            if(typed[i] == name[j])
                ++j;
            else if(typed[i] != name[j] &&
                       typed[i] == typed[i-1])
                continue;
            else
                return false;
        }
        if(j != name.size() )
        return false;
        
     return true;
    }
};