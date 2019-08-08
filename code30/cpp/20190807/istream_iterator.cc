 ///
 /// @file    istream_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-07 11:24:31
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::ostream_iterator;
using std::istream_iterator;
 
int main(void)
{
	vector<int> numbers;
	istream_iterator<int> isi(cin);
	//begin end 是用来遍历元素的
	//copy(isi, istream_iterator<int>(), numbers.begin());
	//这里需要使用插入迭代器
	
	//int number;
	//cin >> number;

	//numbers.push_back(number);

	//适配器模式
	copy(isi, istream_iterator<int>(), std::back_inserter(numbers));

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
