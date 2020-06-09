class Solution {
public:
    int StrToInt(string str) {
        int len = str.size();
        int i=0; 
        int flag = 1;
        for(; i<len; ++i)
            if(str[i] != ' ') break;
        if(str[i]=='-')
            ++i,flag = -1;
        
        if(str[i]=='+') ++i;
        
        long long  ret =0;
        for( ; i<len; ++i){
            if(str[i]<'0' || str[i] >'9') return 0;
            
            ret = ret*10 + str[i]-'0';
            if(flag == 1 && ret >= 0x7fffffff){
               ret = 0x7fffffff;
               return ret;
            }
            if(flag == -1 && ret >= 0x80000000){
                ret = 0x80000000;
                return ret;
            }
        }
       return ret * flag;
    }
};