#include "Acceptor.h"
#include "TCPConnection.h"
#include "EventLoop.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using namespace wd;

void onConnection(const TCPConnectionPtr& conn) {
    cout << conn->toSring() << " connected" << endl;
    conn->send("welcome to server");
}

void onMessage(const TCPConnectionPtr& conn) {
    string msg = conn->receive();
    cout << ">> client data: " << msg << endl;
    conn->send(msg);
}

void onClose(const TCPConnectionPtr& conn) {
    cout << ">> " << conn->toSring() << " disconnected" << endl; 
}

int main() {
    Acceptor acceptor("192.168.5.171", 2000);
    acceptor.ready();
    EventLoop loop(acceptor);
    loop.setConnectionCallback(onConnection);
    loop.setMessageCallback(onMessage);
    loop.setCloseCallback(onClose);
    loop.loop();
    return 0;
}