 ///
 /// @file    replace_if.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-08 14:31:25
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::replace_if;
using std::ostream_iterator;

bool compare(int number)
{
	return number > 3;
}
 
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5, 6};

	std::less<int> lt;// 需要传递2个参数
	cout << lt(5, 4) << endl;
	std::greater<int> gt;
	//replace_if(numbers.begin(), numbers.end(), compare, 7);
	
	//std::bind1st std::bind2nd都是用来提前给函数绑定参数的
	//replace_if(numbers.begin(), numbers.end(), std::bind1st(lt, 3), 7);
	replace_if(numbers.begin(), numbers.end(), std::bind2nd(lt, 3), 7);
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
