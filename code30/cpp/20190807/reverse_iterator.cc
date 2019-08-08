 ///
 /// @file    reverse_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-07 11:55:43
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5};

	//迭代器适配器
	vector<int>::reverse_iterator rit = numbers.rbegin();
	for(; rit != numbers.rend(); ++rit) 
		cout << *rit << " ";
	cout << endl;

	return 0;
}
