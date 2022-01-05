#ifndef __PENGUIN_HPP__
#define __PENGUIN_HPP__
#include <iostream>
class Penguin//企鹅能游泳，也能跑
{
public:
    void run()
    {std::cout << "Penguin::run()" <<std::endl;}
    void swim()
    {std::cout << "Penguin::swim()" << std::endl;}
};

#endif