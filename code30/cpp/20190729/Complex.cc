 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-29 11:20:57
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex(double,double)" << endl;
	}

	// -1 = i^2    欧拉公式
	
	void display() const
	{
		cout << _dreal << " + " << _dimag << "i" << endl;
	}

	//get函数
	double getReal() const {	return _dreal;	}
	double getImag() const {	return _dimag;	}
	//set函数
	void setReal(double real) {	_dreal = real;	} 

private:
	double _dreal;
	double _dimag;
};

//不能对内置类型的数据重载运算符
#if 0
int operator+(int x, int y)
{
	return x - y;
}
#endif


//运算符重载之普通函数(数据成员是public)
Complex operator+(const Complex & lhs, const Complex & rhs )
{
	return Complex(lhs.getReal() + rhs.getReal(), 
				   lhs.getImag() + rhs.getImag());
}

 
int main(void)
{
	int a = 3, b = 4;
	int c = a + b;

	Complex c1(1, 2), c2(3, 4);
	
	Complex c3 = c1 + c2;
	cout << "c3 = ";
	c3.display();
 
	return 0;
}
