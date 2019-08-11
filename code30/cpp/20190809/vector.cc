 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-09 11:01:53
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
 
int main(void)
{
	vector<int> numbers;
	numbers.reserve(100);//空间的分配与对象的创建是分离的

	Point * pint = new Point(10, 12);//空间的分配与对象的构造是绑定在一起的
 
}
