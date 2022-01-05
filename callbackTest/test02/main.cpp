#include"A.hpp"
int main()
{

    B b;
    //因为doFunc是静态成员函数，所以可以这样绑定，但是静态成员函数有很多局限性
    b.setCallBack(A::doFunc);
 
    A a;
    a.func();
    
    return 0;
}