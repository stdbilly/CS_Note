 ///
 /// @file    tls.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-16 11:27:30
 ///
 
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;

int g_number = 1;

//线程局部存储
__thread int tls = 1;

//在每一个线程里，errno的地址都是不一样的
void * threadfunc1(void * arg)
{
	printf("&g_number = %p\n", &g_number);
	printf("g_number = %d\n", g_number);
	printf("&errno = %p\n", &errno);
	printf("errno = %d\n", errno);
	tls = 10;
	printf("&tls = %p\n", &tls);
	printf("tls = %d\n", tls);

	return nullptr;
}
 
void * threadfunc2(void * arg)
{
	printf("&g_number = %p\n", &g_number);
	printf("g_number = %d\n", g_number);
	printf("&errno = %p\n", &errno);
	printf("errno = %d\n", errno);

	tls = 20;
	printf("&tls = %p\n", &tls);
	printf("tls = %d\n", tls);
	return nullptr;
}

int main(void)
{
	printf("&g_number = %p\n", &g_number);
	printf("g_number = %d\n", g_number);
 
	printf("&errno = %p\n", &errno);
	printf("errno = %d\n", errno);

	tls = 30;
	printf("&tls = %p\n", &tls);
	printf("tls = %d\n", tls);

	pthread_t pthid1, pthid2;
	pthread_create(&pthid1, nullptr, threadfunc1, nullptr);
	pthread_create(&pthid2, nullptr, threadfunc2, nullptr);

	pthread_join(pthid1, nullptr);
	pthread_join(pthid2, nullptr);

	return 0;
}
