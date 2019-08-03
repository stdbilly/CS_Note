 ///
 /// @file    namespace3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-22 15:03:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;



namespace wd
{
int show();//函数的声明

//命名空间的嵌套使用
namespace lwh
{
int display()
{
	cout << "lwh::dispay()" << endl;
	return 0;
}
}//end of namespace lwh

}//end of namespace wd



namespace tls
{
int print()
{
	cout << "tls::print()" << endl;
	wd::show();
}

}//end of namespace tls

namespace wd
{
int display()
{
	cout << "wd::display()_" << endl;

	tls::print();

}

int show()
{
	cout << "wd::show()"  << endl;
}

}//end of namespace wd



 
int main(void)
{
	wd::display();
	wd::lwh::display();

	return 0;
 
}
