#pragma once
#include <string>
#include <memory>
#include <functional>
#include "InetAddress.h"
#include "Nocopyble.h"
#include "Socket.h"
#include "SocketIO.h"
using std::string;
using std::function;

namespace wd {
    class TCPConnection;
    using TCPConnectionPtr = std::shared_ptr<TCPConnection>;
    using TCPConnectionCallback = function<void(const TCPConnectionPtr&)>;

class TCPConnection 
: Nocopyble
, public std::enable_shared_from_this<TCPConnection> {
   public:
    TCPConnection(int fd);
    ~TCPConnection();

    string receive();
    void send(const string& msg);

    string toSring() const;
    void shutdown();

    void setConnectionCallback(const TCPConnectionCallback& cb);
    void setMessageCallback(const TCPConnectionCallback& cb);
    void setCloseCallback(const TCPConnectionCallback& cb);

    void handleConnectionCallback();
    void handleMessageCallback();
    void handleCloseCallback();

   private:
    InetAddress getLocalAddr();
    InetAddress getPeerAddr();

   private:
    Socket _sock;
    SocketIO _socketIO;
    InetAddress _localAddr;
    InetAddress _peerAddr;
    bool _isShutdownonWrite;

    TCPConnectionCallback _onConnection;
    TCPConnectionCallback _onMessage;
    TCPConnectionCallback _onClose;
};

}  // namespace wd
