#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

template<class T, int Size=10>
class Queue {
public:
    Queue()
         :_front(0)
         ,_rear(0)
         ,_data(new T[Size]()){}

    ~Queue() {
        if(_data){
            delete [] _data;
        }
    }

    bool empty() const {
        return _front == _rear;
    }

    bool full() const {
        return _front == (_rear+1)%Size;
    }

    void push(T t){
        if(!full()) {
            _data[_rear++] = t;
            _rear %= Size;
        }else {
            cout<<"queue is full"<<endl;
        }
    }

    void pop(){
        if(!empty()){
            ++_front;
            _front %= Size;
        }else{
            cout<<"queue is empty"<<endl;
        }
    }

    T& front() const{
        return _data[_front];
    }

    T& back() const{
        return _data[(_rear + Size - 1)%Size];
    }
private:
    int _front;
    int _rear;
    T* _data;
};

void test1() {
    Queue<int> queue;
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
}

void test2() {
    Queue<string> queue;
    cout << "此时队列中是否为空?" << queue.empty() << endl;
    queue.push("hello");
    cout << "此时队列中是否为空?" << queue.empty() << endl;

    for(int idx = 1; idx != 11; ++idx) {
        queue.push(string(3,'a'+idx));
    }   
    cout << "此时队列中是否已满?" << queue.full() << endl;

    cout << "此时队头的元素是: " << queue.front() << endl;
    cout << "此时队尾的元素是: " << queue.back() << endl;
    queue.pop();
    queue.push("world");
    cout << "元素先出队再入队之后:" << endl;
    cout << "此时队头的元素是: " << queue.front() << endl;
    cout << "此时队尾的元素是: " << queue.back() << endl;

    while(!queue.empty()) {
        cout << queue.front() << endl;
        queue.pop();

    }   
    cout << "此时队列中是否为空?" << queue.empty() << endl;

}

int main() {
    //test1();
    test2();
    return 0;
}

