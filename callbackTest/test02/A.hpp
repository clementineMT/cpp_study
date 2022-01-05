
#ifndef __A_HPP__
#define __A_HPP__

#include<iostream>
#include "B.hpp"
class A
{
public:
	A()
	{
		
	}
	//必须是静态成员函数
	static void doFunc(int a, int b)
	{
		std::cout << "static func" << std::endl;
		
	}
 
	void func()
	{
		B b;
		b.setCallBack(doFunc);
	}
 
	void add(int *a)
	{
		*a += 2;
	}
 
};
#endif