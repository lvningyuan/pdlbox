这个题不可理喻，我明明对这呢， 不给我过

class Solution {

public:

    char firstUniqChar(string s) {

    int a[256] ={0};

    for(int i = 0; i<s.size(); ++i)

    {

        a[s[i]]++;

    }

    

   // int flag = -1;

    for(int i =0; i <s.size(); ++i)

    {

        if(a[s[i]] == 1)

        {

            //flag =0;

            cout<<s[i]<<endl;

            return s[i];

        }

    }

        return ' ';

    }

};