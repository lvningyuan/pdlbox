

1 C++


class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;

        int len  = needle.size();
        int len1 = haystack.size();
        for(int i =0; i <= len1 - len ; ++i)
        {
            if(haystack.substr(i,len) == needle)//substr(从哪开始,查找长度 string库维护
                return i;
        }
        return -1;
    }
};

2. C
int strStr(char * haystack, char * needle){

    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if(len2 == 0)   return 0;
    if(len1 < len2 ) return -1;

    char* dst = needle;
    char* src = haystack;

    int j =0;
    while(*src != '\0')
    {
        char* tmp =src;
        while(*dst == *src && *dst != '\0')
        {
            ++dst;
            ++src;
        }

        if(*dst == '\0')
        {
            return j;
        }
        else 
        {
            dst = needle;
            src = tmp;
            ++src; 
            ++j;
        }
    }
    return -1;
}