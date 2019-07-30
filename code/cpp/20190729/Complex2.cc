 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-29 11:20:57
 ///
 
#include <iostream>
#include <limits>
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

	//前置形式
	//
	//前置形式的自增自减运算符效率高于后置形式
	//
	Complex & operator++()
	{
		++_dreal;
		++_dimag;
		return *this;
	}

	//后置形式
	Complex operator++(int)  //后置形式在其参数中多加一个int，该int不是要传递参数，
	{					     //只是为了前置形式进行区分
		Complex tmp(*this);
		++_dreal;
		++_dimag;
		return tmp;
	}

	//表达式执行结束之后，对象本身发生变化
	//
	//复合赋值运算符都推荐以成员函数形式重载
	// -= *= /=  %=
	Complex & operator+=(const Complex & rhs)
	{
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
	
		return *this;
	}

	//运算符重载之友元(普通)函数
	friend Complex operator+(const Complex & lhs, const Complex & rhs );
	friend bool operator==(const Complex & lhs, const Complex & rhs);

	//输出流运算符的要求是:左操作数为流对象，右操作数为输出的内容
	//
	//因此输出流运算符不能作为成员函数形式存在
	//
	//std::ostream & operator<<(std::ostream & os);
	
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream & operator>>(std::istream & is,  Complex & rhs);
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

void readDobuleValue(std::istream & is, double & number)
{
	cout << ">> pls input a valid double value:" << endl;
	while(is >> number, !is.eof()) {
		if(is.bad()) {
			cout << "istream has corrupted!" << endl;
			return;
		} else if(is.fail()) {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ">> pls input a valid double value:" << endl;
			continue;
		}
		break;
	}
}

//强调: 对于输入流要考虑特殊情况
std::istream & operator>>(std::istream & is,  Complex & rhs)
{
	readDobuleValue(is, rhs._dreal);
	readDobuleValue(is, rhs._dimag);
	return is;
}

Complex operator+(const Complex & lhs, const Complex & rhs )
{
	return Complex(lhs._dreal + rhs._dreal, 
				   lhs._dimag + rhs._dimag);
}

bool operator==(const Complex & lhs, const Complex & rhs)
{
	return (lhs._dreal == rhs._dreal) && 
		   (lhs._dimag == rhs._dimag);
}

bool operator!=(const Complex & lhs, const Complex & rhs)
{
	return !(lhs == rhs);
}

 
int test0(void)
{
	int a = 3, b = 4;
	int c = a + b;

	Complex c1(1, 2), c2(3, 4);
	
	Complex c3 = c1 + c2;
	cout << "c3 = ";
	c3.display();
 
	return 0;
}

void test1()
{
	int a = 1;
	//以后为了效率考虑，可以优先使用前置形式,
	//即使是内置形式的变量
	cout << "(++a) = " << (++a) << endl;//前置++
	cout << "a = " << a << endl;

	cout << "(a++) = " << (a++) << endl ;//后置++
	cout << "a = " << a << endl;

	Complex c1(1, 2), c2(3, 4);
	cout << "c1 = ";
	c1.display();

	//cout << "(++c1) = " << (++c1) << endl;//前置++
	//cout << "c1 = " << c1 << endl;
	cout << "(++c1) = ";
	(++c1).display();
	cout << "c1 = ";
	c1.display();

	//cout << "(c1++) = " << (c1++) << endl ;//后置++
	//cout << "c1 = " << c1 << endl;
	cout << "(c1++) = ";
	(c1++).display();
	cout << "c1 = ";
	c1.display();
	
}

int test2(void)
{
	int a = 3, b = 4;
	int c = a + b;

	a += b;// a = a + b

	Complex c1(1, 2), c2(3, 4);
	
	cout << "执行c1 +=  c2之后:" << endl;
	c1 += c2;
	cout << "c1 = ";
	c1.display();
 
	return 0;
}

int test3(void)
{
	int a = 3, b = 4;
	int c = a + b;

	a += b;// a = a + b

	Complex c1(1, 2), c2(3, 4);
	
	cout << "执行c1 +=  c2之后:" << endl;
	c1 += c2;
	cout << "c1 = " << c1 << endl;
	//operator<<(operator<<(cout, "c1 = "), c1);
	
	Complex c3(0, -1);//  -i
	cout << "c3 = " << c3 << endl;
	Complex c4(0, 0);//    0
	cout << "c4 = " << c4 << endl;
	Complex c5(-1, -2);// -1 - 2i
	cout << "c5 = " << c5 << endl;
	Complex c6(-2, 0);//  -2
	cout << "c6 = " << c6 << endl;
	Complex c7(3, 0);//    3
	cout << "c7 = " << c7 << endl;
	Complex c8(0, -2);//  -2i 
	cout << "c8 = " << c8 << endl;
 
	return 0;
}

void test4()
{
	Complex c1;
	std::cin >> c1;

	cout << "c1 = " << c1 << endl;
}

void test5()
{
	Complex c1(1, 2);
	cout << "c1 = " << c1 << endl;
	//Complex c2 = c1 + 5;


	Complex c2 = 5 + c1;//隐式转换
	//Complex c2 = operator+(5, c1);
	cout << "c2 = " << c2 << endl;

}

int main(void)
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}
