/*
    线程库,令Thread是一个具体类，其构造函数接受ThreadCallback对象。
    应用程序只需提供一个能转换为ThreadCallback的对象（可以是函数），即可创建以一份Thread实体，然后调用
    Thread::start()即可。
*/
#include <functional>
#include "Foo.hpp"
#include "Thread.hpp"
int main()
{
    Foo foo;
    Thread thread1(std::bind(&Foo::runInThread, &foo));
    Thread thread2(std::bind(&Foo::runInAnotherThread, &foo, 410));
    thread1.start();
    thread2.start();
}