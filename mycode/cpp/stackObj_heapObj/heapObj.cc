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


    void print() const{
        cout<<"_id:"<<_id<<endl
            <<"_name:"<<_name<<endl;
    }

    void destroy(){
        if(this){
            delete this;
        }
    }
private:
    //将析构函数放在private区域
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
private:
    char* _id;
    char* _name;
};

void test1() {
    Student* pstu=new Student("10001","Jack");
    pstu->print();
    pstu->destroy();
}
int main() {
    test1();
    return 0;
}

