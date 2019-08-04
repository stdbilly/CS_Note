## [单例模式](singleton.cc)

#### 应用场景:

1. 可以用单例模式替换掉全局变量
2. 配置文件中的存储都是程序的输入信息
3. 词典库， 网页库

#### 单例模式的自动释放（3种方式）

1. [嵌套类+静态对象](Singleton/autoRelease/singleton1.cc)
2. [静态成员函数+atexit](Singleton/autoRelease/singleton2.cc)
3. [pthread_once + atexit](Singleton/autoRelease/singleton3.cc)

## [PIMPL设计模式](PIMPL/)

##### 作用：

1. 实现信息隐藏
2. 降低编译依赖
3. 只要接口不变, 头文件不变，实现可以随便改造, 可以以一个最小代价完成库的平滑升级
   