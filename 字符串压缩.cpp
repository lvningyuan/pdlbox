class Solution {
public:
    int compress(vector<char>& chars) {
     int len = chars.size();
     if(len <= 1)
     {
         return len;
     }
     chars.push_back(' ');//插入一个特殊字符，作为标记，因为走不到
     int count=1;
     int j=0;
     for(int i=0; i<len; ++i)
     {
         if(chars[i] == chars[i+1])
            count++;
        else
        {
            chars[j]= chars[i];
            ++j;
            if(count>1)
            {
            string a= to_string(count);
            int len = a.size();
            for(int i=0; i<len; ++i)
            {
                chars[j]=a[i];
                ++j;
            }
           count=1;
            }
        }
     }
     chars.resize(j);
     return j;
    }
};