class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int j=0;
	for(int star=0,i=0,last=0;  i<s.size(); ){
		if(j<p.size()  &&  (s[i]==p[j] || p[j]=='?')  ){
			++i;
			++j;}//ƥ��ɹ�һ�������

		else if(j<p.size() && p[j]=='*'){
			last = i;//��¼�ϴ��ߵ�s����λ��
			star = ++j;}//��¼p�� * ����һ��λ��
                        

//���Ѵ��� * 
		else if(star != 0){
			i = ++last;// i��s����ƥ���λ�ÿ�ʼƥ��Ƚ�
			j = star;}//jҲ��*����һ��λ��

//������ *  �� �Ҳ�ƥ��
		else 
            return false;
		}

		for(; j<p.size() && p[j] == '*'; ++j)  
            ;  //�������*����
		return j==p.size();//�ж��Ƿ��ߵ�p����β
  }
};