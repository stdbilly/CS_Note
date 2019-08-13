#include <math.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

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

class Factory {
   public:
    virtual Figure* create() = 0;
    virtual ~Factory() { cout << "~Factory()" << endl; }
};

class RectangleFactory : public Factory {
   public:
    Figure* create() { return new Rectangle(2, 3); }
};

class CircleFactory : public Factory {
   public:
    Figure* create() { return new Circle(3); }
};

class TriangleFactory : public Factory {
   public:
    Figure* create() { return new Triangle(3, 4, 5); }
};

int main() {
    unique_ptr<Factory> rectangleFactory(new RectangleFactory());
    unique_ptr<Figure> rectangle(rectangleFactory->create());
    unique_ptr<Factory> circleFactory(new CircleFactory());
    unique_ptr<Figure> circle(circleFactory->create());
    unique_ptr<Factory> triangleFactory(new TriangleFactory());
    unique_ptr<Figure> triangle(triangleFactory->create());

    display(rectangle.get());
    display(circle.get());
    display(triangle.get());
    return 0;
}
