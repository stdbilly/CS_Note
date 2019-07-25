#include <iostream>
using std::cout;
using std::endl;

class Stack{
public:
    Stack(int maxSize=10)
    :_maxSize(maxSize),
    _data(new int[_maxSize]()),
    _top(-1){ cout<<"Stack()"<<endl; }

    ~Stack(){
        if(_data){
            delete [] _data;
        }
        cout<<"~Stack()"<<endl; 
    }

    bool empty(){
        return _top==-1 ? true:false;
    }

    bool full(){
        return _top>=_maxSize ? true:false;
    }

    void push(int x){
        if(full()){
            return ;
        }else{
            _data[++_top]=x;
        }
    }

    void pop(){
        if(empty()){
            return;
        }else{
            _top--;
        }
    }

    int top(){
        if(empty()){
            return -1;
        }else{
            return _data[_top];
        }
        
    }
private:
    int _maxSize;
    int *_data;
    int _top;
};

void test1(){
    Stack stack;
    stack.push(10);
    stack.push(12);
    stack.push(14);
    cout<<stack.top()<<endl;
    stack.pop();
    cout<<stack.top()<<endl;
}
int main()
{   test1();
    return 0;
}

