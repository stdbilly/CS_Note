#include "TCPServer.h"
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
    TCPServer server("192.168.5.171", 2000);
    server.setConnectionCallback(onConnection);
    server.setMessageCallback(onMessage);
    server.setCloseCallback(onClose);
    server.start();
    return 0;
}