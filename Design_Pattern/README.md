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

## [简单工厂(Simple Factory)](Factory/SimpleFactory.cc)

又称为静态工厂方法(Static Factory Method)

简单工厂把实例化的操作单独放到一个类中，这个类就成为简单工厂类，让简单工厂类来决定应该用哪个具体子类来实例化,被创建的实例通常都具有共同的父类.

缺点：1. 不满足单一职责原则      2. 不满足开闭原则

## 工厂方法模式(Factory method)

定义一个用于创建对象的接口, 让子类决定实例化哪一个类. Factory Method使一个类的实例化延迟到其子类.

## [抽象工厂(Abstract Factory)](Factory/AbstractFactory.cc)

提供一个创建一系列相关或相互依赖对象的借口,而无需指定他们具体的类.

##### 优点

- 抽象工厂模式隔离了具体类的生成，使得客户并不需要知道什么被创建。由于这种隔离，更换一个具体工厂就变得相对容易。所有的具体工厂都实现了抽象工厂中定义的那些公共接口，因此只需改变具体工厂的实例，就可以在某种程度上改变整个软件系统的行为。另外，应用抽象工厂模式可以实现高内聚低耦合的设计目的，因此抽象工厂模式得到了广泛的应用。
- 当一个产品族中的多个对象被设计成一起工作时，它能够保证客户端始终只使用同一个产品族中的对象。这对一些需要根据当前环境来决定其行为的软件系统来说，是一种非常实用的设计模式。
- 增加新的具体工厂和产品族很方便，无须修改已有系统，符合“开闭原则”。

##### 适用情况

- 一个系统要独立于它的产品的创建,组合和表示时
- 一个系统要由多个产品系列中的一个来配置时

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