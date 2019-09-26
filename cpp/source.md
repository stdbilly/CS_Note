## STL之空间配置器
```C++
std::allocator     //接口层
    > allocate
    > deallocate

    > construct
    > destroy
```
空间分配的实现层
```C++
# ifdef __USE_MALLOC

typedef malloc_alloc alloc;
typedef malloc_alloc single_client_alloc;

# else

typedef __default_alloc_template<__NODE_ALLOCATOR_THREADS, 0> alloc;

#endif 
```
`class __malloc_alloc_template`; //一级配置器

##### 内存碎片  ==>  造成内存不够，从而导致程序崩溃

- 内部碎片

  页式管理  512B 1KB 4KB
  段式管理

  段页式管理

- 外部碎片
  malloc
  可以重新进行利用
  杜绝外部碎片的产生
  小于等于128字节
  对于二级配置器来说，最少申请的空间也是320(`8*20*2`)字节

```C++
		class __default_alloc_template;//二级配置器
    //16个自由空闲链表
        enum {_ALIGN = 8};
        enum {_MAX_BYTES = 128};
        enum {_NFREELISTS = 16}; 

        union _Obj {
            union _Obj* _M_free_list_link;
            char _M_client_data[1];    /* The client sees this.        */
        };

        static _Obj* _S_free_list[_NFREELISTS]; 
    //内存池
        static char* _S_start_free;
        static char* _S_end_free;
        static size_t _S_heap_size;
```
#####  分配策略：

- 当申请128字节以上的空间时，直接采用一级配置器malloc/free
- 当申请128字节以下的空间时，就采用自由空闲链表+内存池的方式