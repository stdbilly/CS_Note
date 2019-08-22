#pragma once
#include <string>
#include "InetAddress.h"
#include "Nocopyble.h"
#include "Socket.h"
#include "SocketIO.h"
using std::string;

namespace wd {
class TCPConnection : public Nocopyble {
   public:
    TCPConnection(int fd);
    ~TCPConnection();

    string receive();
    void send(const string& msg);

    string toSring() const;
    void shutdown();

   private:
    InetAddress getLocalAddr();
    InetAddress getPeerAddr();

   private:
    Socket _sock;
    SocketIO _socketIO;
    InetAddress _localAddr;
    InetAddress _peerAddr;
    bool _isShutdownonWrite;
};

}  // namespace wd
