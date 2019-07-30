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
	Complex(double dreal = 0, double dimag = 0)
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

	//运算符重载之成员函数
	//
	//不推荐使用
	Complex operator+(const Complex & rhs)
	{
		return Complex(_dreal + rhs._dreal,
					   _dimag + rhs._dimag);	
	}
	friend std::ostream & operator<<(std::ostream &os, const Complex & rhs);
private:
	double _dreal;
	double _dimag;
};

std::ostream & operator<<(std::ostream &os, const Complex & rhs)
{
	//os << rhs._dreal << " + " << rhs._dimag << "i";
	if(rhs._dimag == 0)
		os << rhs._dreal;
	else {
		if(rhs._dreal == 0) {
			if(rhs._dimag == 1)
				os << "i";
			else if(rhs._dimag == -1)
				os << "-i";
			else 
				os << rhs._dimag << "i";
		}
		else {
			os << rhs._dreal;
			if(rhs._dimag > 0) {
				os << " + " << rhs._dimag << "i";
			} else if(rhs._dimag < 0) {
				os << " - " << rhs._dimag * (-1) << "i";
			}
		}
	}
	return os;
}
 
int test0(void)
{
	int a = 3, b = 4;
	int c = a + b;

	Complex c1(1, 2), c2(3, 4);
	
	Complex c3 = c1 + c2;
	cout << "c3 = " << c3 << endl;
 
	return 0;
}

void test1()
{
	Complex c1(1, 2);
	cout << "c1 = " << c1 << endl;
	//Complex c2 = c1 + 5;
	Complex c2 = c1.operator+(5);//隐式转换
	cout << "c2 = " << c2 << endl;//


	//Complex c3 = 5 + c1;//error

}
