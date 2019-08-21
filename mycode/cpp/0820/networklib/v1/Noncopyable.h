 ///
 /// @file    Noncopyable.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-13 11:42:52
 ///
 
#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd
{

class Noncopyable
{
protected:
	Noncopyable() {}
	~Noncopyable(){}

	Noncopyable(const Noncopyable &)=delete;
	Noncopyable& operator=(const Noncopyable &) = delete;
};

}//end of namspace wd


#endif
