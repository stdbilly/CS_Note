#include <iostream>
using std::cout;
using std::endl;

class Stack {
   public:
    Stack(int maxSize = 10)
        : _maxSize(maxSize), _data(new int[_maxSize]()), _top(-1) {}

    ~Stack() {
        if (_data) {
            delete[] _data;
        }
    }

    bool empty() { return _top == -1; }

    bool full() { return _top == _maxSize - 1; }

    void push(int x) {
        if (full()) {
            cout << "stack is full" << endl;
        } else {
            _data[++_top] = x;
        }
    }

    void pop() {
        if (empty()) {
            cout << "stack is empty" << endl;
        } else {
            --_top;
        }
    }

    int top() { return _data[_top]; }

   private:
    int _maxSize;
    int *_data;
    int _top;
};

void test1() {
    Stack stack(10);
    cout << "此时栈中是否为空?" << stack.empty() << endl;
    stack.push(1);
    cout << "此时栈中是否为空?" << stack.empty() << endl;

    for (int idx = 2; idx != 12; ++idx) {
        stack.push(idx);
    }
    cout << "此时栈中是否已满?" << stack.full() << endl;

    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
    cout << "此时栈中是否为空?" << stack.empty() << endl;
}
int main() {
    test1();
    return 0;
}
