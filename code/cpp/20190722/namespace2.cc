 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-22 14:49:47
 ///
 
#include <iostream>
using std::cout;// using声明机制
using std::endl;


namespace wd
{

//命名空间中的实体
int number = 10;

void display()
{
	cout << "display() " << endl;
}


}//end of namespace wd

 
int main(void)
{
	cout << "wd::number = " << wd::number << endl;
	wd::display();//作用域限定符
 
	return 0;
}
