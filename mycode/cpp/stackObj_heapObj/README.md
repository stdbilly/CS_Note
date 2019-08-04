## [实现只能生成栈对象的代码](stackObj.cc)

##### 只需要将operator new放在私有区域

```C++
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
```

## [实现只能生成堆对象的代码](heapObj.cc)

##### 将析构函数放在私有区域

```C++
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
```

## vector底层是如何实现的？

vector称为动态数组， 可以动态扩容，，将数据存储在堆空间中，其内部有三个指针`start`、`finish`、`end_of_storage`。`start`指向堆空间数组的开始位置，`finish`最后一个元素的下一个位置，`end_of_storage`指向当前数组开辟空间大小的下一个位置。当`size()=capacity()`时，先申请2*`size()` 的空间，再将原来的元素全部复制到新空间，然后再回收原来的空间，最后再添加新元素。

## [统计一篇英文(The_Holy_Bible.txt)文章中出现的单词和词频](wordCount.cc)

输入：某篇文章的绝对路径
输出：词典（词典中的内容为每一行都是一个“单词 词频”）

```C++
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctime>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

struct Info{
    Info(const string& s,int i=1)
        :word(s)
         ,count(i){ }
    string word;
    int count;
};

bool isNum(string s){
    istringstream iss(s);
    int i;
    if(iss>>i){
        return true;
    }
    return false;
}

void test1() {
    auto start = std::chrono::system_clock::now();
    ifstream ifs("The_Holy_Bible.txt");
    if(!ifs){
        cout<<"ifstream open file error"<<endl;
    }
    string line;
    string word;
    bool hasSame=false;
    vector<Info> wordInfo;
    while(getline(ifs,line)){
        istringstream iss(line);
        while(!iss.eof()){
            hasSame=false;
            iss>>word;
            for(auto & info:wordInfo){
                if(info.word==word){
                    info.count++;
                    hasSame=true;
                    break;
                }
            }

            if(!hasSame && !isNum(word)){
                wordInfo.push_back(Info(word));
            }
        }
    }

    ofstream ofs("dict.txt");
    if(!ofs){
        cout<<"ofstream open file error"<<endl;
    }
    for(auto & info:wordInfo){
        //cout<<info.word<<" "<<info.count<<endl;
        ofs<<info.word<<" "<<info.count<<"\n";
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "use time: " << elapsed_seconds.count() << "s\n";
}

int main() {
    test1();
    return 0;
}
```
