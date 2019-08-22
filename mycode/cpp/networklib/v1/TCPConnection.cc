#include "TCPConnection.h"
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sstream>

namespace wd {
TCPConnection::TCPConnection(int fd)
    : _sock(fd),
      _socketIO(fd),
      _localAddr(getLocalAddr()),
      _peerAddr(getPeerAddr()),
      _isShutdownonWrite(false) {}

TCPConnection::~TCPConnection() {
    if (!_isShutdownonWrite) {
        shutdown();
    }
}

string TCPConnection::receive() {
    char buf[65536] = {0};
    _socketIO.readLine(buf, sizeof(buf));
    return string(buf);
}

void TCPConnection::send(const string& msg) {
    _socketIO.writen(msg.c_str(), msg.size());
}

void TCPConnection::shutdown() {
    if (!_isShutdownonWrite) {
        _isShutdownonWrite = true;
        _sock.shutdownonWrite();
    }
}

string TCPConnection::toSring() const {
    std::ostringstream oss;
    oss << _localAddr.ip() << ":" << _localAddr.port() << " --> "
        << _peerAddr.ip() << ":" << _peerAddr.port();
    return oss.str();
}

InetAddress TCPConnection::getLocalAddr() {
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    if (getsockname(_sock.fd(), (struct sockaddr*)&addr, &len) == -1) {
        perror("getsockname");
    }
    return InetAddress(addr);
}

InetAddress TCPConnection::getPeerAddr() {
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    if (getsockname(_sock.fd(), (struct sockaddr*)&addr, &len) == -1) {
        perror("getsockname");
    }
    return InetAddress(addr);
}

}  // namespace wd
