#include <iostream>
#include <functional>
#include "Penguin.hpp"
#include "Sparrow.hpp"
#include "callback.h"
#include "Bar.hpp"
#include "Foo.hpp"
using namespace std;
//基于接口的设计
//客户class Foo和Bar并不知道Sparrow和Penguin的存在，但在main函数中可以把他们装配到一起
int main()
{
    Sparrow s;
    Penguin p;
    //装配起来，Foo要麻雀，Bar要企鹅
    Foo foo(bind(&Sparrow::fly, &s), bind(&Sparrow::run, &s));
    Bar bar(bind(&Penguin::swim,&p), bind(&Penguin::run, &p));
    foo.fooFly();
    return 0;
}