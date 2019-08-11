## [实现一个队列的类模板](QueueTemplate.cc)

## [实现一个模板形式的单例类，要求对于任意类型的类经过Singleton的处理之后，都能获取一个单例对象，并且可以传递任意参数](SingletonTemplate)

## [实现log4cpp的封装，使其可以像printf一样使用](mylog)

## STL是由哪些组件构成的？它们各自具备什么样的特点？

1. ##### 容器（container）

   容器是可容纳一些数据的类模板，STL中有vector、list、deque、set/multiset、map/multimap等容器

2. ##### 迭代器（iterator）

   从实现的角度来看，迭代器是一种将operator*, operator->, operator++, operator--等指针相关操作进行重载的class template

3. ##### 适配器（Adapter）

   适配器就是Interface(接口)，对容器、迭代器和算法进行包装，但其实质还是容器、迭代器和算法，只是不依赖于具体的标准容器、迭代器和算法类型，容器适配器可以理解为容器的模板，迭代器适配器可理解为迭代器的模板，算法适配器可理解为算法的模板。

4. ##### 算法（algorithm）

   各种算法如sort, copy, erase... 从实现的角度来看，STL算法是一种function template

5. ##### 函数对象（functor）

   从实现的角度来看，函数对象是一种重载了operator()的class或class template

6. ##### 配置器（allocator）

   负责空间配置和管理，从实现的角度来看，配置器是一个实现了动态空间配置、空间管理、空间释放的class template

## 序列式容器都有哪些异同？

#### vector

vector采用线性连续空间存储，它以两个迭代器start和finish分别指向配置得来的连续空间中目前已被使用的范围，并以迭代器end_of_storage指向整块连续空间（含备用空间的尾端）。

没有在头部添加和删除元素的操作

提供的是Random Access Iterator，执行插入操作会改变迭代器的位置

清空元素后不会释放存储空间

#### deque

deque由一段一段的连续空间构成，一旦有必要在deque的前端或尾端增加新空间，便配置一段定量连续空间，串接在deque的头端或尾端。deque采用一块map（不是STL的map容器）作为主控，map是一小块连续空间，其中每个元素都是指针，指向另一段（较大的）连续线性空间，成为缓存区，缓冲区才是deque的存储空间主体。

提供的是Random Access Iterator，但不是普通指针

#### list

list是一个循环双向链表

因为list不是采用连续空间存储的，所以其迭代器不支持+ ，-操作，可以进行++，--，取值，成员存取等操作，list提供的是Bidirectional Iterator，不支持下标访问运算符

插入和splice都不会造成原有的迭代器失效

清空元素后会释放存储空间

对于任何位置元素的插入和删除都是O(1)的时间复杂度