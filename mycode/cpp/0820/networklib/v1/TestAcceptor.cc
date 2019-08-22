 ///
 /// @file    TestAcceptor.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-07 15:42:14
 ///
 
#include "Acceptor.h"
#include "TcpConnection.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	wd::Acceptor acceptor("192.168.5.171", 2000);
	acceptor.ready();
	
	wd::TcpConnection conn(acceptor.accept());
	cout << conn.toString() << " has connected!" << endl;
	conn.send("welcome to server.");
	printf("> pls client data:\n");
	cout << conn.receive() << endl;

	return 0;
}
