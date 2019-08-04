#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CowString {
    class CharProxy {
       public:
        CharProxy(size_t idx, CowString& self) : _idx(idx), _self(self) {}
        //执行写操作
        CharProxy& operator=(const char& ch);

        //执行读操作,类型转换函数
        operator char() { return _self._pstr[_idx]; }

       private:
        size_t _idx;
        CowString& _self;
    };

   public:
    CowString() : _pstr(new char[4 + 1]() + 4) {  //用一个int保存引用计数
        initRefCount();
        cout << "CowString()" << endl;
    }

    CowString(const char* pstr) : _pstr(new char[strlen(pstr) + 5] + 4) {
        initRefCount();
        strcpy(_pstr, pstr);
        cout << "CowString(const char* pstr)" << endl;
    }

    CowString(const CowString& rhs) : _pstr(rhs._pstr) {  //浅拷贝
        increaseRefCount();
        cout << "CowString(const CowString& rhs)" << endl;
    }

    CowString& operator=(const CowString& rhs) {
        release();
        _pstr = rhs._pstr;  //浅拷贝
        increaseRefCount();
        cout << "CowString& operator=(const CowString& rhs)" << endl;
        return *this;
    }

    const char* c_str() const { return _pstr; }

    size_t size() const { return strlen(_pstr); }

    ~CowString() { release(); }

    int getRefCount() { return *(int*)(_pstr - 4); }

    CharProxy operator[](size_t idx) { return CharProxy(idx, *this); }

    const char& operator[](size_t idx) const {
        cout << "const char & operator[](size_t) const " << endl;
        return _pstr[idx];
    }
#if 0
    char& operator[] (int idx) {
        if(idx >= 0 && idx < size()) {
            if(getRefCount() > 1) {
                decreaseRefCount();
                char* ptmp = new char[strlen(_pstr) + 5]() + 4;
                strcpy(ptmp, _pstr);
                _pstr = ptmp;
                initRefCount();
            }

            return _pstr[idx];
        } else {
            static char nullchar = '\0';
            return nullchar;
        }
    }
#endif
    friend std::ostream& operator<<(std::ostream& os, const CowString& rhs);

   private:
    void initRefCount() { *(int*)(_pstr - 4) = 1; }

    void increaseRefCount() { ++*(int*)(_pstr - 4); }

    void decreaseRefCount() { --*(int*)(_pstr - 4); }

    void release() {
        decreaseRefCount();
        if (getRefCount() == 0) {
            delete[](_pstr - 4);
            cout << "delete heap data" << endl;
        }
    }

   private:
    char* _pstr;
};

//执行写(修改)操作
CowString::CharProxy& CowString::CharProxy::operator=(const char& ch) {
    if (_idx < _self.size()) {
        if (_self.getRefCount() > 1) {
            _self.decreaseRefCount();
            char* tmp = new char[_self.size() + 5]() + 4;
            strcpy(tmp, _self._pstr);
            _self._pstr = tmp;
            _self.initRefCount();
        }
        _self._pstr[_idx] = ch;  //执行修改
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CowString& rhs) {
    os << rhs._pstr;
    return os;
}

void test1() {
    CowString s1 = "hello,world";
    CowString s2 = s1;
    CowString s3("wangdao");
    cout << "s3 = " << s3 << endl;
    s3 = s1;

    cout << "赋值之后" << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address = %p\n", s1.c_str());
    printf("s2's address = %p\n", s2.c_str());
    printf("s3's address = %p\n", s3.c_str());
    cout << "s1's refCount = " << s1.getRefCount() << endl;
    cout << "s2's refCount = " << s2.getRefCount() << endl;
    cout << "s3's refCount = " << s3.getRefCount() << endl;

    s3[0] = 'H';
    cout << "\n执行写操作之后" << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address = %p\n", s1.c_str());
    printf("s2's address = %p\n", s2.c_str());
    printf("s3's address = %p\n", s3.c_str());
    cout << "s1's refCount = " << s1.getRefCount() << endl;
    cout << "s2's refCount = " << s2.getRefCount() << endl;
    cout << "s3's refCount = " << s3.getRefCount() << endl;

    cout << "\n执行读操作之后" << endl;
    cout << "s3[0] = " << s3[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address = %p\n", s1.c_str());
    printf("s2's address = %p\n", s2.c_str());
    printf("s3's address = %p\n", s3.c_str());
    cout << "s1's refCount = " << s1.getRefCount() << endl;
    cout << "s2's refCount = " << s2.getRefCount() << endl;
    cout << "s3's refCount = " << s3.getRefCount() << endl;
}

int main() {
    test1();
    return 0;
}
