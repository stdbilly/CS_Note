#include <func.h>

int main(int argc,char* argv[])
{
    pthread_mutex_t mutex ;
    pthread_mutexattr_t mattr;
    int ret=pthread_mutexattr_init(&mattr);
    pthread_mutexattr_settype(&mattr,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex,&mattr);
    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);
    printf("you can see me\n");
    return 0;
}

