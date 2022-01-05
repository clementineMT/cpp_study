#ifndef __BAR_HPP__
#define __BAR_HPP__
#include "callback.h"
//一个既能用到run，也能用到swim的函数
class Bar
{
public:
    Bar(SwimCallback swimCb, RunCallback runCb)
    : swimCallback_(swimCb), runCallback_(runCb)
    {
        
    }
    void barSwim()
    {
        swimCallback_();
    }

    void barRun()
    {
        runCallback_();
    }
private:
    SwimCallback swimCallback_;
    RunCallback runCallback_;
};

#endif