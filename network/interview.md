#### TCP/IP协议栈层次结构

#### connect()怎么实现的?(TCP三次握手), TCP三次握手需要知道的细节点

序列号

#### TCP四次挥手需要知道的细节点(CLOSE_WAIT、TIME_WAIT、MSL)

#### TCP与UDP的区别与适用场景

TCP通信建立在有连接的基础上; TCP协议栈保证可靠性，不会丢包，不会乱序，失败会重发。

UDP需要应用层做协议来保证可靠性。视频直播可以用UDP。

必须使用udp的场景：广播。

#### linux常见网络模型详解(select、poll与epoll)

1. epoll_event结构中的epoll_data_t的fd与ptr的使用场景

   

2. 异步的connect函数如何编写

#### select函数可以检测网络异常吗？

不能, 当对端关闭连接, select会返回,这时socket是可读的, 调用read()或recv()会返回0

#### 如何将socket设置成非阻塞的(创建时设置与创建完成后设置)，非阻塞socket与阻塞的socket在收发数据上的区别

阻塞socket: 如果TCP窗口太小, send()会阻塞

非阻塞socket: 如果TCP窗口太小, send()会立刻返回, 返回值是-1, 错误码是EAGAIN or EWOULDBLOCK, 表示当前socket是阻塞的, 数据发不出去

#### send/recv(read/write)返回值大于0、等于0、小于0的区别

|           | <0                                                           | ==0                                           | >0               |
| --------- | ------------------------------------------------------------ | --------------------------------------------- | ---------------- |
| send/recv | 可能出错了(看错误码, 如果错误码是EAGAIN or EWOULDBLOCK, 并没有真正出错; 如果错误码是EINTR表示被信号中断) | 对端已经关闭连接, 对端先发起了4次挥手的前两步 | 实际收发的字节数 |
|           |                                                              |                                               |                  |
|           |                                                              |                                               |                  |

send()返回100表明这100个字节已经发送给对端了吗?

不是, send()并不是真正的把数据发送出去, 而是放到本地的发送缓冲区, 应用层把数据放到了本地协议栈里, 什么时候发数据发出去,是操作系统自己的行为

15.如何编写正确的收数据代码与发数据代码

16.发送数据缓冲区与接收数据缓冲区如何设计

17.socket选项SO_SNDTIMEO和SO_RCVTIMEO

#### socket选项TCP_NODELAY

默认情况下,发送数据采用Negale算法.这样虽然提高了网络吞吐量,但是实时性却降低了,在一些交互性很强的应用程序来说是不允许的,使用TCP_NODELAY选项可以禁止Negale 算法.此时，应用程序向内核递交的每个数据包都会立即发送出去.需要注意的是,虽然禁止了Negale 算法,但网络的传输仍然受到TCP确认延迟机制的影响
#### socket选项SO_REUSEADDR和SO_REUSEPORT

IP和端口可重用, 方便调试, 不用等待2MSL

#### socket选项SO_LINGER

#### shutdown与优雅关闭

23.socket选项SO_KEEPALIVE

24.关于错误码EINTR

25.如何解决tcp粘包问题

26.信号SIGPIPE与EPIPE错误码

27.gethostbyname阻塞与错误码获取问题

28.心跳包的设计技巧（保活心跳包与业务心跳包）

29.断线重连机制如何设计

30.如何检测对端已经关闭

31.如何清除无效的死链（端与端之间的线路故障）

32.定时器的不同实现及优缺点

33.你问我答环节三

34.http协议的具体格式

35.http head、get与post方法的细节

36.http代理、socks4代理与socks5代理如何编码实现

37.ping

38.telnet