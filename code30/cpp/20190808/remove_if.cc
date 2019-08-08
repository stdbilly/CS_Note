 ///
 /// @file    remove_if.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-08 11:23:27
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::remove;
using std::ostream_iterator;
 
void test0(void)
{
	vector<int> numbers{5, 3, 1, 2, 66, 7, 1, 66, 8, 9, 66};
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	//执行remove的过程中， 没有直接删除元素的
	//
	//remove的实现不是针对某一种容器，直接删除元素有可能会导致迭代器范围出现问题
	//
	
	//erase-remove惯用法
	auto it = remove(numbers.begin(), numbers.end(), 66);
	numbers.erase(it, numbers.end());

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void test1()
{
	vector<int> numbers;
	cout << "numbers' s size = " << numbers.size() << endl;
	cout << "numbers' s capacity = " << numbers.capacity() << endl;
	numbers.push_back(1);
	cout << "numbers' s size = " << numbers.size() << endl;
	cout << "numbers' s capacity = " << numbers.capacity() << endl;
	bool flag = true;

	//在遍历元素的过程中，做了添加元素的操作，该操作导致底层
	//数据存放的位置发生了变化，从而导致了迭代器失效的问题
	//
	//注意: 一般情况下，在遍历容器元素的过程中，不要轻易
	//做添加或者删除元素的操作，除非很确定不会造成迭代器失效
	auto it = numbers.begin();
	for(; it != numbers.end(); ++it) {
		cout << *it << " ";
		if(flag) {
			numbers.push_back(2);
			cout << "numbers' s size = " << numbers.size() << endl;
			cout << "numbers' s capacity = " << numbers.capacity() << endl;
			flag = false;
		}
	}

}

int main(void)
{
	test1();
	return 0;
}
