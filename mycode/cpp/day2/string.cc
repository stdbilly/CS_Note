#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String() : _pstr(nullptr) { cout<<"String()"<<endl; }

    String(const char *pstr)
        : _pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
        cout << "String(const char *pstr)" << endl;
    }

    String(const String & rhs)
        :_pstr ( new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout<<"String(const String & rhs)"<<endl;
    }

    String & operator=(const String & rhs)
    {
        if(this != &rhs)
        {
            if(_pstr){
                delete [] _pstr;
            }
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
            cout << "String & operator=(const String & rhs)" << endl;
        }
        return *this;
    }

    ~String()
    {
        if(_pstr)
        {
            delete [] _pstr;
        }
        cout << "~String()" << endl;
    }

    void print()
    {
        if(_pstr){
            cout << _pstr << endl;
        }
    }
private:
    char *_pstr;
};

void test1(void)
{
    String str1;
    cout << "str1:";
    str1.print();
    String str2 = "Hello,world";
    String str3("wangdao");

    cout << "str2:";
    str2.print();       
    cout << "str3:";
    str3.print();   

    String str4 = str3;
    cout << "str4:";
    str4.print();

    str4 = str2;
    cout << "str4:";
    str4.print();
}

int main()
{
    test1();
    return 0;
}
