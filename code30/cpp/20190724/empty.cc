 ///
 /// @file    empty.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-24 09:38:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//虽然空类没有声明任何数据成员，但是为了
//区分出不同的对象，还是会占据1个字节的空间
class Empty
{
};
 
int main(void)
{
	Empty e1;//调用默认(无参)构造函数
	Empty e2 = e1;//拷贝构造函数

	Empty e3;
	e3 = e2;//赋值函数

	cout << "sizeof(Empty) = " << sizeof(Empty) << endl;
	cout << "sizeof(e1) = " << sizeof(e1) << endl;
	printf("&e1 = %p\n", &e1);
	printf("&e2 = %p\n", &e2);
	printf("&e3 = %p\n", &e3);

	return 0;
}
