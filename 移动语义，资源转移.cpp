#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

namespace N
{
	class String
	{
	public:
		String(const char* str = "" )
		{
			if (str == nullptr)
				str = "";
			str_ = new char[strlen(str) + 1];
			strcpy(str_, str);
		}

		String(const String& s)
			:str_ (new char[strlen(s.str_) + 1])
		{		
			strcpy(str_, s.str_);
		}

		//��ֵ���� : 1 ����ֵ  2  ��ֵ  
		//�ƶ����� ���ѽ���ֵ����Դ�ƶ�����
		String(String&& a)
			:str_(a.str_)
		{
			a.str_ = nullptr;//��ȻҲ����swap
		}
		//�ƶ�����||��Դת��

		//��ϸ���������������ʲô
		//s3 = s2 + s1;    �ڲ�������һ��ret�� ��ֵֵ���أ��ұ���Ҫһ��temp����s1 + s2ֵ, 
		//��  s2 + s1 --->temp����;   s3 = temp;  temp ����  �����ܹ�������3�Σ�����������
		String operator + (const String& a)
		{
			int len1 = strlen(str_);
			char* tmp = new char[len1 + strlen(a.str_) + 1];
			strcpy(tmp, str_);
			strcpy(tmp + len1, a.str_);
			
			String ret(tmp);//����һ�ݾֲ�����
			delete[] tmp;//��ֹ�ڴ�й©
			return ret;//���ؾֲ�����󣬱㱻���� ���ڷ���ֵ���� �ִ���һ��Temp��ʱ������շ���ֵ��
		}

		String& operator = (const String& s)
		{
			//������ռ䣬��������ռ�ʧ���ˣ��ְ�ԭ��������ɾ����
			char* tmp = new char[strlen(s.str_) + 1];
			strcpy(tmp, s.str_);
			delete[] str_;
			str_ = tmp;
			return *this;
		}
		~String()
		{
			if (str_)
				delete[] str_;
			str_ = nullptr;
		}




	private:
		char* str_;
	};
}
	int main()
	{
		N::String a("HELLO");
		N::String b(" world");
		N::String c = a + b;

		//std::cout << c << std::endl;
		return 0;
	};
