 ///
 /// @file    TestAcceptor.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-07 15:42:14
 ///
 
#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoop.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
//回调函数体现了扩展性
void onConnection(const wd::TcpConnectionPtr & conn)
{
	cout << conn->toString() << " has connected!" << endl;
	conn->send("welcome to server.");
}

void onMessage(const wd::TcpConnectionPtr & conn)
{	//该回调函数的执行时间不宜过长 10ms
	string msg = conn->receive();
	cout << ">> receive msg from client: " << msg << endl;
	//业务逻辑的处理交给
	//decode
	//compute
	//encode
	conn->send(msg);
}

void onClose(const wd::TcpConnectionPtr & conn)
{
	cout << ">> " << conn->toString() << " has closed!" << endl;
}


int main(void)
{
	wd::Acceptor acceptor("192.168.30.128", 8888);
	acceptor.ready();

	wd::EventLoop loop(acceptor);
	loop.setConnectionCallback(onConnection);
	loop.setMessageCallback(onMessage);
	loop.setCloseCallback(onClose);

	loop.loop();

	return 0;
}
