#include<iostream>
using namespace std;
void print1()
{
	cout << "1" << endl;
}
 
void print2()
{
	cout << "2" << endl;
}
 
void callback(void(*printNum)())
{
	printNum();
}