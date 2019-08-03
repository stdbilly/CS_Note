#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

#define PI acos(-1)

class Circle {
public:
    Circle() 
        : _r(0) {
            cout << "Circle()" << endl;
        }

    Circle(double r) 
        : _r(r) {
            cout << "Circle(double r)" << endl;
        }

    double getArea() {
        return PI * _r * _r;
    }

    double getPerimeter() {
        return 2 * PI * _r;
    }

    void show() {
        cout << "r = " << _r << endl
            << "area = " << getArea() << endl
            << "Perimeter = " << getPerimeter() << endl;
    }

    ~Circle() { cout << "~Circle()" << endl; }
private:
    double _r;
};

class Cylinder : public Circle {
public:
    Cylinder (double r, double  h) 
        : Circle(r)
          , _hight(h) {
              cout << "Cylinder (double r, double  h)" << endl;
          }

    double getVolume() {
        return getArea() * _hight;
    }

    void  showVolume() {
        cout << "Volume =" << getVolume() << endl;
    }

    ~Cylinder() { cout << "~Cylinder()" << endl; }
private:
    double _hight;
};

void test1() {
    Circle circle(2.0);
    Cylinder cylinder(3.0,5.0);
    circle.show();
    cylinder.showVolume();
}

int main() {
    test1();
    return 0;
}

