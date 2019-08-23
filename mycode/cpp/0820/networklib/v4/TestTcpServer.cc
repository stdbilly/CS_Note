 ///
 /// @file    TestAcceptor.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-07 15:42:14
 ///
 
#include "Threadpool.h"
#include "TcpServer.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using namespace wd;

Threadpool * gThreadpool = nullptr;

#if 1
class MyTask
{
public:
	MyTask(const string & msg,
		 const wd::TcpConnectionPtr & conn)
	: _msg(msg)
	, _conn(conn)
	{}

	//运行在线程池的某一个子线程中
	void process()
	{
		//decode
		//compute
		//encode
		cout << ">>" << current_thread::threadName << ": task process() " << endl;
		string response = _msg;//要返回给客户端的消息
		//_conn->send(response);//由线程池的线程(计算线程)完成数据的发送,在设计上来说，是不合理的
							  //数据发送的工作要交还给IO线程(Reactor所在的线程)完成
							  //将send的函数的执行延迟到IO线程去操作
		_conn->sendInLoop(response);
	}
private:
	string _msg;
	wd::TcpConnectionPtr _conn;
};
#endif
 
//回调函数体现了扩展性
void onConnection(const wd::TcpConnectionPtr & conn)
{
	cout << conn->toString() << " has connected!" << endl;
	conn->send("welcome to server.");
}

void onMessage(const wd::TcpConnectionPtr & conn)
{
	cout << "onMessage...." << endl;
	string msg = conn->receive();
	cout << ">> receive msg from client: " << msg << endl;
	//业务逻辑的处理要交给线程池处理
	//decode
	//compute
	//encode

	//::sleep(2);//碰到需要长时间的处理时，响应速度会降下来
	//conn->send(msg);
	MyTask task(msg, conn);

	//拿到线程池之后，就将该任务交给线程池去执行
	gThreadpool->addTask(std::bind(&MyTask::process, task));
}

void onClose(const wd::TcpConnectionPtr & conn)
{
	cout << "onClose...." << endl;
	cout << conn->toString() << " has closed!" << endl;
}



class TextQuery
{
public:
	void query(const string & msg);//处理业务逻辑

};


class EchoServer
{
public:

	void onConection(const TcpConnectionPtr & conn);
	void onMessage(const TcpConnectionPtr & conn)
	{
		//_threadpool.addTask(std::bind(&TextQuery::query, tq));
	}
	void onClose(const TcpConnectionPtr & conn);

	//void process();

private:
	Threadpool _threadpool;
	TcpServer _server;
};


int main(void)
{
	Threadpool threadpool(4, 10);
	threadpool.start();

	gThreadpool = &threadpool;

	TcpServer server("192.168.5.171", 2000);

	server.setConnectionCallback(onConnection);
	server.setMessageCallback(onMessage);
	server.setCloseCallback(onClose);

	server.start();

	return 0;
}
