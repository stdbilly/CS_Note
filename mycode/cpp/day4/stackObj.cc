#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student {
public:
    Student(const char* id,const char* name)
    :_id(new char[strlen(id)+1]())
     ,_name(new char[strlen(name)+1]()){
         cout<<"Student(const char* id,const char* name)"<<endl;
         strcpy(_id,id);
         strcpy(_name,name);
     }

    ~Student(){
        cout<<"~Student()"<<endl;
        if(_id){
            delete [] _id;
            _id=nullptr;
        }
        if(_name){
            delete [] _name;
            _name=nullptr;
        }
    }

    void print() const{
        cout<<"_id:"<<_id<<endl
            <<"_name:"<<_name<<endl;
    }
private:
    void* operator new(size_t sz);
    void operator delete(void* p);
private:
    char* _id;
    char* _name;
};

void test1() {
    Student stu("10001","Jack");
    stu.print();
}
int main() {
    test1();
    return 0;
}

