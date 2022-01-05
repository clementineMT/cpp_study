#ifndef __FOO_HPP__
#define __FOO_HPP__
#include <iostream>
class Foo
{
public:
    void runInThread();
    void runInAnotherThread(int);
};
void Foo::runInThread()
{
    std::cout << "Foo::runInThread()"<<std::endl;
}
void Foo::runInAnotherThread(int a)
{
    std::cout << "runInAnotherThread(int) " << "a = " << a << std::endl;
}
#endif