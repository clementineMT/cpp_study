#ifndef __THREAD_HPP__
#define __THREAD_HPP__
#include <functional>
#include <iostream>
class Thread
{
public:
    typedef std::function<void()> ThreadCallback;
    Thread(ThreadCallback cb)
    :cb_(cb)
    {

    }
    void start()
    {
        std::cout << "Thread::start()" << std::endl;
        cb_();
    }
private:
    ThreadCallback cb_;
};
#endif