
˼· ��1�� �����ո�
	2 ��������
	3 ת��

class Solution {
public:
    int myAtoi(string str) {
        int len =str.size();
        int i;
        for(i =0; i<len; ++i)
        {
            if(str[i] !=' ')
                break;
        }

        char type= '+';
        if(str[i] == '+')
        {
            type = '+';
            ++i;
        }
        else if(str[i] == '-')
        {
            type = '-';
            ++i;
        }

        int j;
        long ret =0; 
        for(j=i; j < len; ++j)
        {
            if( '0' <= str[j]  && '9' >= str[j])
            {
                 ret = (str[j] - '0') + ret * 10;
                 if(ret > 0x7fffffff)
                 {
                    if(type =='+')
                         ret = 0x7fffffff;
                    else
                         ret = 0x80000000;
                    break;
                 }
            }
            else
                break;
        }
        return type =='-' ? (-1) * ret:ret;
        }
};