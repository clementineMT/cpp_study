#ifndef __SPARROW_HPP__
#define __SPARROW_HPP__
#include <iostream>
class Sparrow//麻雀能飞也能跑
{

public:
    void fly()
    {std::cout << "Sparrow::fly()" << std::endl;}
    void run()
    {std::cout << "Sparrow::run()" << std::endl;}
    
};

#endif