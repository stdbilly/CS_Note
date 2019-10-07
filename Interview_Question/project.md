## 搜索引擎

Reactor: IO线程

线程池:   计算线程 

计算线程要通知IO线程发送数据



网络编程过程中涉及到三个半事件

- 当新连接到来时,  onConnection 
- 当消息到达时,    onMessage
- 当连接关闭时,    onClose



