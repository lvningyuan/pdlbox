class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st;
        for(auto& x:s) if(x>='A'&&x<='Z'||x>='a'&&x<='z') 
          st.push(x);//���ַ����е��ַ��ó���
        for(auto& x:s) if(x>='A'&&x<='Z'||x>='a'&&x<='z')           {
            x=st.top(); //���ж��ַ�����Ԫ�أ����ַ������滻
            st.pop();
            }
        return s;
    }
};