 ///
 /// @file    WorkerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 15:58:37
 ///
 
#include "Thread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

class Threadpool;
class WorkerThread
: public Thread
{
public:
	WorkerThread(Threadpool & threadpool);
	~WorkerThread();
private:
	void run();

	Threadpool & _threadpool;
};

}//end of namespace wd
 
