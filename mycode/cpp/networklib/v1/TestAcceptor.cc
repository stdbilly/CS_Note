#include "Acceptor.h"
#include "TCPConnection.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    wd::Acceptor acceptor("192.168.5.171", 2000);
    acceptor.ready();
    wd::TCPConnection conn(acceptor.accept());
    cout << conn.toSring() << " connected" << endl;
    conn.send("welcome to server");
    cout << "client data:" << endl;
    cout << conn.receive() << endl;
    return 0;
}