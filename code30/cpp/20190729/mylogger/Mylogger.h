 ///
 /// @file    Mylogger.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-29 09:39:27
 ///
 
#pragma once

#include <log4cpp/Category.hh>

using namespace log4cpp;

namespace wd
{

class Mylogger
{
public:
	static Mylogger * getInstance();
	static void destroy();

	void error(const char * msg);

	template <typename... Args>
	void error(Args... args)
	{
		_mycategory.error(args...);
	}

	void warn(const char * msg);
	template <typename... Args>
	void warn(Args... args)
	{
		_mycategory.warn(args...);
	}

	void info(const char * msg);
	template <typename... Args>
	void info(Args... args)
	{
		_mycategory.info(args...);
	}
	void debug(const char * msg);
	template <typename... Args>
	void debug(Args... args)
	{
		_mycategory.debug(args...);
	}
private: Mylogger();
	~Mylogger();

private:
	static Mylogger * _pInstance;
	Category & _mycategory;
};

#define prefix(msg)	string("[").append(__FILE__)\
		.append(":").append(__FUNCTION__)\
		.append(":").append(std::to_string(__LINE__))\
		.append("] ").append(msg)

#define LogError(msg, ...) wd::Mylogger::getInstance()->error(prefix(msg).c_str(), ##__VA_ARGS__)
#define LogWarn(msg, ...) wd::Mylogger::getInstance()->warn(prefix(msg).c_str(), ##__VA_ARGS__)
#define LogInfo(msg, ...) wd::Mylogger::getInstance()->info(prefix(msg).c_str(), ##__VA_ARGS__)
#define LogDebug(msg, ...) wd::Mylogger::getInstance()->debug(prefix(msg).c_str(), ##__VA_ARGS__)

}//end of namespace wd
