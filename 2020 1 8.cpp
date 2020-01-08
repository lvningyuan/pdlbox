1  结构体 struct    +(sturct name)A
（本身比较抽象，就像Java中的抽象类，它只定义，本身并不实现，在调用时实现）
	**结构体就像数组，属于聚合类型，只能在定义时进行初始化
	**eg:struct stu {
                              	      char name[20];
		      int age;
			}stu;
	**刚刚问结构体内部时 用 ' . '
	**对结构体内的数组进行修改时，不能直接赋值，通过strcpy进行赋值
	   typedef struct A{}a;       struct A被重命名为a
	**结构体内部继续该结构体类型自引用时，必须用指针类型，
                   否则结构体不能计算出自己到底有多大，进而崩溃；
	**结构体类型  链表
                   typedef  struct Node//相当于定义，编程时必须在最前边定义
                          {
 		int date;
		struct Node * next//此处的struct 必须写 ；因为C编译器从上而下执行，并不知Node为结构体
		}Node；//此处Node跟上边的含义不同；

		struct Node
		{
		 int data;
		 struct Point p;
		 struct Node* next;
		}n1 = {10, {4,5}, NULL}; //结构体嵌套初始化  
                               结构体中访问         变量用 .   访问   指针用 ->
	**
	**所有函数的返回值支持列式表达式
	   eg: int len =strlenI(strcpy(a,b));
                **assert(表达式)    它会确告诉程序员第一个遇到的错误在哪，但它不是函数
	  在debug情况下起作用，在release下会失效
	**运行错误        最好经常打断点
	**运算符的操作数为二进制；若输入的是十进制，在计算机内就已经以二进制存储，用时直接用
	   eg:  2 | 3 ;  234 >>2(对应二进制数右移）