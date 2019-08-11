## [单例模式](singleton.cc)(Singleton Pattern)

#### 应用场景:

1. 可以用单例模式替换掉全局变量
2. 配置文件中的存储都是程序的输入信息
3. 词典库， 网页库

#### 单例模式的自动释放（3种方式）

1. [嵌套类+静态对象](Singleton/autoRelease/singleton1.cc)
2. [静态成员函数+atexit](Singleton/autoRelease/singleton2.cc)
3. [pthread_once + atexit](Singleton/autoRelease/singleton3.cc)

#### 模板单例类

1. [嵌套类+静态对象](Singleton/SingletonTemplate/SingletonTemplate1.cc)
2. [pthread_once + atexit](Singleton/SingletonTemplate/SingletonTemplate2.cc)

## [PIMPL设计模式](PIMPL/)(Pointer to Implementation)

##### 作用：

1. 实现信息隐藏
2. 降低编译依赖
3. 只要接口不变, 头文件不变，实现可以随便改造, 可以以一个最小代价完成库的平滑升级
   

## 代理模式(Proxy Pattern)

在代理模式中，一个类代表另一个类的功能。创建具有现有对象的对象，以便向外界提供功能接口。这种类型的设计模式属于结构型模式。

[实现CowString, 让其operator[]能够区分出读写操作](Proxy_Pattern/cow_string.cc)

## 适配器模式(Adapter Pattern) 

将一个接口转换成客户希望的另一个接口，适配器模式使接口不兼容的那些类可以一起工作，其别名为包装器(Wrapper)。适配器模式既可以作为类结构型模式，也可以作为对象结构型模式。