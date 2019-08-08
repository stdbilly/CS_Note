 ///
 /// @file    TemplateSingleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-08 09:49:34
 ///
 

#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;

template <class T>
class Singleton
{
public:
	static T * getInstance()
	{
		pthread_once(&_once,init);
		return _pInstance;
	}

	static void init()
	{
		_pInstance = new T();
		atexit(destroy);
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}


private:
	Singleton() {	cout << "Singleton()" << endl;	}
	~Singleton() {	cout << "~Singleton()" << endl;	}

private:
	static T * _pInstance;
	static pthread_once_t _once;
};

template <class T>
T * Singleton<T>::_pInstance = nullptr;

template <class T>
pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	void init(int ix, int iy)
	{
		_ix = ix;
		_iy = iy;
	}


	~Point(){	cout << "~Point()" << endl;	}

private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	Point * pt = Singleton<Point>::getInstance();
	Point * pt2 = Singleton<Point>::getInstance();

	pt->init(1, 2);

	cout << "pt= " << pt << endl;
	cout << "pt2= " << pt2 << endl;

	return 0;
}
