����һ��

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        string ret;
        if(len1 > len2 )//ǰ�߲�0
            {
                string tmp;
                tmp.resize(len1-len2,'0');
                b=tmp.append(b);
                //reverse(b.begin(),b.end());
            }
         else//ǰ�߲�0
         {
             string tmp;
             tmp.resize(len2-len1,'0');
             a=tmp.append(a);
         }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int flag =0;
        int len = len1>len2 ? len1 :len2;
        ret.resize(len);

        for(int i = 0; i<len; ++i)
        { 
             ret[i] = a[i] + b[i]- '0' + flag;
             cout<<ret[i]<<endl;
             if(ret[i]> '1')
             {
                 flag=1;
                 ret[i] -= 2;
             }
             else 
             {
                 flag=0;
             }
        }
        if(flag ==1 )
        {
            ret += '1';
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};



��������




class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        string ret;
        if(len1 > len2 )//ǰ�߲�0
            {
                
                reverse(b.begin(),b.end());
                b.append(len1-len2,'0');
                reverse(a.begin(), a.end());
            }
         else//ǰ�߲�0
         {
          reverse(a.begin(), a.end());
          a.append(len2-len1, '0');
          reverse(b.begin(), b.end());
         }

        int flag =0;
        int len = len1>len2 ? len1 :len2;
        ret.resize(len);

        for(int i = 0; i<len; ++i)
        { 
             ret[i] = a[i] + b[i]- '0' + flag;
      
             if(ret[i]> '1')
             {
                 flag=1;
                 ret[i] -= 2;
             }
             else 
             {
                 flag=0;
             }
        }
        if(flag ==1 )
        {
            ret += '1';
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};