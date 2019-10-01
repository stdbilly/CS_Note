 ///
 /// @file    Noncopyable.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 10:01:07
 ///
 

#pragma once

namespace wd
{

class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}

	Noncopyable(const Noncopyable &)=delete;
	Noncopyable & operator=(const Noncopyable &)=delete;
};

}//end of namesapce wd
