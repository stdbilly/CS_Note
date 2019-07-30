 ///
 /// @file    arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-29 16:25:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	Data(int data = 0)
	: _data(data)
	{	cout << "Data()" << endl;	} 

	int getData() const {	return _data;	}

	~Data() {	cout << "~Data()" << endl;	}

	int _data;
};

class MiddleLayer
{
public:
	MiddleLayer(Data * pdata = nullptr)
	: _pdata(pdata)
	{	cout << "MiddleLayer(Data*)" << endl;	}

	Data * operator->()
	{
		return _pdata;
	}

	Data & operator*()
	{
		return *_pdata;
	}

	~MiddleLayer() 
	{	
		if(_pdata)
			delete _pdata;

		cout << "~MiddleLayer()" << endl;
	}

private:
	Data * _pdata;
};

class ThirdLayer
{
public:
	ThirdLayer(MiddleLayer * ml)
	: _ml(ml)
	{	cout << "ThirdLayer(MiddleLayer *)" << endl;	}

	MiddleLayer & operator->()
	{
		return *_ml;
	}

	~ThirdLayer()
	{
		if(_ml)
			delete _ml;
		cout << "~ThirdLayer()" << endl;
	}

private:
	MiddleLayer * _ml;
};

 
int main(void)
{
	//ml虽然是一个对象，但用法类似于一个指针
	//
	//可以将其看成是一个智能指针的雏形
	//
	MiddleLayer ml(new Data(10));
	cout << ml->getData() << endl;
	cout << (*ml).getData() << endl;

	//cout << (ml.operator->())->getData() << endl;
	cout << endl;
 
#if 0
	ThirdLayer tl(new MiddleLayer(new Data(11)));
	cout << tl->getData() << endl;
	cout << ((tl.operator->()).operator->())->getData() << endl;
#endif

	return 0;
}
