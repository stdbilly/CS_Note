#include "TaskQueue.h"
#include "Producer.h"
#include "Consumer.h"
#include <iostream>
#include <memory>
using std::unique_ptr;
using std::cout;
using std::endl;
using namespace wd;

int main(){
   TaskQueue taskque(10);
   unique_ptr<Thread> producer(new Thread(std::bind(&Producer::produce, Producer(), std::ref(taskque))));
   unique_ptr<Thread> consumer(new Thread(std::bind(&Consumer::consume, Consumer(), std::ref(taskque))));
   producer->start();
   consumer->start();
   producer->join();
   consumer->join();
   return 0;
}
