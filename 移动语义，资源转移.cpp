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

		//右值引用 : 1 将亡值  2  右值  
		//移动构造 ：把将亡值的资源移动出来
		String(String&& a)
			:str_(a.str_)
		{
			a.str_ = nullptr;//当然也可以swap
		}
		//移动语义||资源转移

		//仔细分析这个函数做了什么
		//s3 = s2 + s1;    内部创建了一个ret； 传值值返回，右边需要一个temp接收s1 + s2值, 
		//即  s2 + s1 --->temp生成;   s3 = temp;  temp 销毁  所以总共创建了3次，销毁了两次
		String operator + (const String& a)
		{
			int len1 = strlen(str_);
			char* tmp = new char[len1 + strlen(a.str_) + 1];
			strcpy(tmp, str_);
			strcpy(tmp + len1, a.str_);
			
			String ret(tmp);//创建一份局部对象
			delete[] tmp;//防止内存泄漏
			return ret;//返回局部对象后，便被销毁 ，在返回值那里 又创建一个Temp临时对象接收返回值，
		}

		String& operator = (const String& s)
		{
			//先申请空间，避免申请空间失败了，又把原来的内容删除了
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
