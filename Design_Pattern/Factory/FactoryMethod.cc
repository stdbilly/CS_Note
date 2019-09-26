///
/// @file    Figure.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2019-08-02 14:31:16
///

#include <math.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

//遵循开闭原则: 对修改关闭(不需要修改原来的代码), 对扩展开放

class Figure {
   public:  //提供统一的接口
    virtual void display() const = 0;
    virtual double area() const = 0;

    virtual ~Figure() { cout << "~Figure()" << endl; }
};

void display(Figure* fig) {
    fig->display();
    cout << "的面积是:" << fig->area() << endl;
}

class Rectangle : public Figure {
   public:
    Rectangle(double length, double width) : _length(length), _width(width) {
        cout << "Rectangle()" << endl;
    }

    void display() const { cout << "rectangle"; }

    double area() const { return _length * _width; }

   private:
    double _length;
    double _width;
};

class Circle : public Figure {
   public:
    Circle(double radius) : _radius(radius) { cout << "Circle()" << endl; }

    void display() const { cout << "circle"; }

    double area() const { return 3.14159 * _radius * _radius; }

   private:
    double _radius;
};

class Triangle : public Figure {
   public:
    Triangle(double a, double b, double c) : _a(a), _b(b), _c(c) {
        cout << "Triangle()" << endl;
    }

    void display() const { cout << "triangle"; }

    double area() const {
        double p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }

   private:
    double _a;
    double _b;
    double _c;
};

//工厂方法
//前提条件:
//	 1. 针对于复杂对象
//	 2. 批量创建对象
//
//对于简单对象，不适合使用工厂模式
class Factory {
   public:
    virtual Figure* create() = 0;
    virtual ~Factory() { cout << "~Factory()" << endl; }
};

class RectangleFactory : public Factory {
   public:
    Figure* create() {
        // load xml
        //
        //....
        return new Rectangle(3, 4);
    }
};

class CircleFactory : public Factory {
   public:
    Figure* create() {
        // load xml
        //....
        //
        return new Circle(10);
    }
};

class TriangleFactory : public Factory {
   public:
    Figure* create() {
        // load xml
        //
        //....
        return new Triangle(3, 4, 5);
    }
};

int main(void) {
    unique_ptr<Factory> rectangleFactory(new RectangleFactory());
    unique_ptr<Figure> rectangle(rectangleFactory->create());

    unique_ptr<Factory> circleFactory(new CircleFactory());
    unique_ptr<Figure> circle(circleFactory->create());

    unique_ptr<Factory> triangleFactory(new TriangleFactory());
    unique_ptr<Figure> triangle(triangleFactory->create());

    display(rectangle.get());
    display(circle.get());
    display(triangle.get());

    // Point pt(1, 2);

    return 0;
}
