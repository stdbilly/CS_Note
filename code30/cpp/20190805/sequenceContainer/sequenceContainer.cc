 ///
 /// @file    sequenceContainer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-05 16:07:10
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

template <class  Container>
void display(const Container & c)
{
	typename Container::const_iterator cit = c.begin();
	for(; cit != c.end(); ++cit) {
		cout << *cit << " ";
	}
	cout << endl;
}

int array[5] = {1, 2, 3, 4, 5};

void test0()
{
	cout << "\n>>> test vector:" << endl;
	//vector<int> numbers(10);
	//vector<int> numbers(array, array + 5);//迭代器范围是一个左闭右开的区间[beg, end)
	
	cout << sizeof(vector<int>) << endl;
	vector<int> numbers = {1, 2, 3, 4, 5};
	display(numbers);
	numbers.push_back(6);// O(1)
	display(numbers);
	//vector没有在头部添加和删除元素的操作
	//如果vector提供push_front/pop_front
	//都会导致所有的元素移动一次, 其时间复杂度为O(N)
	
	cout << "numbers[2] = " << numbers[2] << endl;

	//添加元素.
	//
	//强调: 对于vector来说，执行写操作之后，
	//都需要重新更新迭代器的位置，有可能迭代器出现bug
	vector<int>::iterator it = numbers.begin();
	cout << "*it = " << *it << endl;
	auto it2 = numbers.insert(it, 11);//O(N)
	cout << "*it = " << *it << endl;
	it2 = numbers.insert(++it, 3, 10);
	cout << "*it2 = " << *it2 << endl;
	++it2;
	cout << "*it2 = " << *it2 << endl;
	display(numbers);
	numbers.erase(it2, it2 + 3);
	display(numbers);

	//numbers.clear();
	cout << "numbers'size = " << numbers.size() << endl;
	numbers.shrink_to_fit();
	cout << "numbers.capacity = " << numbers.capacity() << endl;
	
	display(numbers);

}
 
void test1()
{
	cout << "\n>>> test deque:" << endl;
	//deque<int> numbers(10, 1);
	//deque<int> numbers(array, array + 5);
	deque<int> numbers{1, 2, 3, 4, 5};
	display(numbers);
	numbers.push_back(6);//O(1)
	display(numbers);
	numbers.push_front(0);//O(1)
	display(numbers);
	//deque支持下标访问运算符 ==> 随机访问
	cout << "numbers[2] = " << numbers[2] << endl;
	//添加元素
	deque<int>::iterator it = numbers.begin();
	cout << "*it = " << *it << endl;
	auto it2 = numbers.insert(it, 11);//O(N)
	cout << "*it = " << *it << endl;
	cout << "*it2 = " << *it2 << endl;
	it2 = numbers.insert(++it, 3, 10);
	cout << "*it2 = " << *it2 << endl;
	++it2;
	cout << "*it2 = " << *it2 << endl;
	display(numbers);
	numbers.erase(it2, it2 + 3);
	display(numbers);

	numbers.clear();
	cout << "numbers'size = " << numbers.size() << endl;
	//deque没有capacity方法
	//cout << "numbers.capacity = " << numbers.capacity() << endl;
	display(numbers);
}

void test2()
{
	cout << "\n>>> test list:" << endl;
	//list<int> numbers(10, 1);
	//list<int> numbers(array, array + 5);
	list<int> numbers{1, 2, 3, 4, 5};
	display(numbers);
	numbers.push_back(6);//O(1)
	display(numbers);
	numbers.push_front(0);//O(1)
	display(numbers);
	//list不支持下标访问运算符
	//cout << "numbers[2] = " << numbers[2] << endl;
	
	//添加元素
	list<int>::iterator it = numbers.begin();
	cout << "*it = " << *it << endl;
	auto it2 = numbers.insert(it, 11);//O(1)
	cout << "*it = " << *it << endl;
	cout << "*it2 = " << *it2 << endl;
	it2 = numbers.insert(++it, 3, 10);
	cout << "*it2 = " << *it2 << endl;
	++it2;
	cout << "*it2 = " << *it2 << endl;
	display(numbers);
	auto it3 = it2;
	//list的迭代器不支持+ - 运算符
	//只支持的双向访问迭代器
	++it3; ++it3; ++it3;
	numbers.erase(it2, it3);
	display(numbers);

	numbers.clear();
	cout << "numbers'size = " << numbers.size() << endl;
	display(numbers);
}

int main(void)
{
	test0();
	test1();
	test2();
}
