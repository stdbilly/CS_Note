#include <iostream>
using std::cout;
using std::endl;

class Queue {
   public:
    Queue(int maxSize = 10)
        : _pHead(nullptr), _pRear(nullptr), _maxSize(maxSize), _size(0) {
        cout << "Queue(int)" << endl;
    }

    bool empty() { return _pHead == nullptr; }

    bool full() { return _size >= _maxSize; }

    void push(int x) {
        if (full()) {
            cout << "queue is full" << endl;
            return;
        }
        Node* temp = new Node();
        temp->data = x;
        if (empty()) {
            _pHead = _pRear = temp;
        } else {
            _pRear->pNext = temp;
            _pRear = temp;
        }
        _size++;
    }

    void pop() {
        if (empty()) {
            return;
        }
        Node* temp = _pHead;
        _pHead = _pHead->pNext;
        delete temp;
        _size--;
    }

    int front() {
        if (empty()) {
            return -1;
        }
        return _pHead->data;
    }

    int back() {
        if (empty()) {
            return -1;
        }
        return _pRear->data;
    }

    ~Queue() {
        while (_pHead) {
            Node* temp = _pHead;
            _pHead = _pHead->pNext;
            delete temp;
        }
        cout << "~Queue()" << endl;
    }

   private:
    struct Node {
        int data;
        Node* pNext;
    };
    Node *_pHead, *_pRear;
    int _maxSize;
    int _size;
};

void test1() {
    Queue que;
    que.push(5);
    que.push(34);
    que.push(23);
    que.pop();
    cout << "front=" << que.front() << endl << "rear=" << que.back() << endl;
}

int main() {
    test1();
    return 0;
}
