#ifndef __FOO_HPP__
#define __FOO_HPP__
#include "callback.h"
//一个既能用到fly又能用到run的客户class
class Foo
{
public:
    Foo(FlyCallback flyCb, RunCallback runCb)
    : flyCallback_(flyCb), runCallback_(runCb)
    {
       
    }
    void fooFly()
    {
        flyCallback_();
    }
    void fooRun()
    {
        runCallback_();
    }
private:
    FlyCallback flyCallback_;
    RunCallback runCallback_;
};
#endif