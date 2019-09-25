#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class SmartPointer {
public:
    SmartPointer(T* p) : _p(p) {}

    T* operator->() {
        return _p;
    }

    T& operator*() {
        return *_p;
    }

    T* get() {
        return _p;
    }

    void reset(T* p) {
        delete _p;
        _p = p;
    } 

    ~SmartPointer() {
        if(_p) {
            delete _p;
        }
    }

private: 
    T* _p;
};

class Point
{
public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix)
          , _iy(iy)
    {
        cout << "Point(int,int)" << endl;
    }

    friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    ~Point(){   cout << "~Point()" << endl; }
private:
    int _ix;
    int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
    os << "(" << rhs._ix
        << "," << rhs._iy
        << ")";
    return os;
}


int main() {
    SmartPointer<Point> pointer(new Point(1, 2));
    cout << *pointer << endl;
    return 0;
}

