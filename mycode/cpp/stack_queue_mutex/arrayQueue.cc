#include <iostream>
using std::cout;
using std::endl;

class Queue {
   public:
    Queue(int size = 10)
        : _size(size), _front(0), _rear(0), _data(new int[_size]()) {}

    ~Queue() {
        if (_data) {
            delete[] _data;
        }
    }

    bool empty() const { return _front == _rear; }

    bool full() const { return _front == (_rear + 1) % _size; }

    void push(int x) {
        if (!full()) {
            _data[_rear++] = x;
            _rear %= _size;
        } else {
            cout << "queue is full" << endl;
        }
    }

    void pop() {
        if (!empty()) {
            ++_front;
            _front %= _size;
        } else {
            cout << "queue is empty" << endl;
        }
    }

    int front() const { return _data[_front]; }

    int back() const { return _data[(_rear + _size - 1) % _size]; }

   private:
    int _size;
    int _front;
    int _rear;
    int* _data;
};

void test1() {
    Queue queue(10);
    cout << "此时队列中是否为空?" << queue.empty() << endl;
    queue.push(1);
    cout << "此时队列中是否为空?" << queue.empty() << endl;

    for (int idx = 2; idx != 12; ++idx) {
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

    while (!queue.empty()) {
        cout << queue.front() << endl;
        queue.pop();
    }
    cout << "此时队列中是否为空?" << queue.empty() << endl;
}

int main() {
    test1();
    return 0;
}
