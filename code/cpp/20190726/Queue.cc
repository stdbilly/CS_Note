 ///
 /// @file    Queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-26 10:11:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(int size = 10)
	: _size(size)
	, _front(0)
	, _rear(0)
	, _data(new int[_size]())
	{} 

	~Queue()
	{
		if(_data)
			delete [] _data;
	}

	bool empty() const
	{
		return _front == _rear;
	}

	bool full() const
	{
		return _front == (_rear + 1) % _size;
	}

	void push(int number)
	{
		if(!full()) {
			_data[_rear++] = number;
			_rear %= _size;
		} else {
			cout << "queue is full, cannot push any more data!" << endl;
		}
	}

	void pop()
	{
		if(!empty()) {
			++_front;
			_front %= _size;
		} else {
			cout << "queue is empty, no more data!" << endl;
		}
	}	

	int front() const
	{	return _data[_front];}

	int back() const
	{	
		cout << "_rear: " << _rear << endl;
		return _data[(_rear - 1 + _size) % _size];	}

private:
	int _size;
	int _front;
	int _rear;
	int * _data;
};
 
int main(void)
{ 
	Queue queue(10);
	cout << "此时队列中是否为空?" << queue.empty() << endl;
	queue.push(1);
	cout << "此时队列中是否为空?" << queue.empty() << endl;

	for(int idx = 2; idx != 12; ++idx) {
		queue.push(idx);
	}
	cout << "此时队列中是否已满?" << queue.full() << endl;

	cout << "此时队头的元素是: " << queue.front() << endl;
	cout << "此时队尾的元素是: " << queue.back() << endl;
	queue.pop();
	queue.push(10);
	cout << "元素先出队再入队之后:" << endl;
	cout << "此时队头的元素是: " << queue.front() << endl;
	cout << "此时队尾的元素是: " << queue.back() << endl;

	while(!queue.empty()) {
		cout << queue.front() << endl;
		queue.pop();
	}
	cout << "此时队列中是否为空?" << queue.empty() << endl;

	return 0;
}
