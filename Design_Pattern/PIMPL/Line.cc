#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;

class Line::LineImpl {
    class Point {
        public:
            Point(int ix = 0, int iy = 0) 
            :_ix(ix)
            ,_iy(iy) {
                cout << "Point(int, int)" << endl;
            }

            ~Point() {
                cout << "~Point()" << endl;
            }

            void print() const {
                cout << "(" << _ix << "," << _iy << ")" << endl;
            }
        private:
            int _ix;
            int _iy;
    };

public:
    LineImpl(int ix1, int iy1, int ix2, int iy2) 
    :_pt1(ix1, iy1)
    ,_pt2(ix2, iy2) {
        cout << "LineImpl(int, int, int, int)" << endl;
     }

    ~LineImpl() { cout << "~LineImpl()" << endl; }

    void printLine() const; 
private:
    Point _pt1, _pt2;
};

Line::Line(int ix1, int iy1, int ix2, int iy2) 
    :_pImpl(new LineImpl(ix1, iy1, ix2, iy2)) {
    cout << "Line(int, int, int, int)" << endl;
}

Line::~Line() {
    if(_pImpl) {
        delete _pImpl;
    }
    cout << "~Line()" << endl;
}

void Line::printLine() const {
    _pImpl -> printLine();
}

void Line::LineImpl::printLine() const {
    _pt1.print();
    cout << "--->";
    _pt2.print();
    cout << endl;
}

