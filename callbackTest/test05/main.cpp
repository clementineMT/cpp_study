//以std::function 和std::bind取代虚函数
//基本用途
#include <iostream>
#include <functional>
using namespace std;
class Foo
{
public:
    void methodA();
    void methodInt(int a);
    void methodString(const string& str);
};
void Foo::methodA()
{
    cout << "Foo::methodA()" <<endl;
}
void Foo::methodInt(int a)
{
    cout << "Foo::methodInt(int)" << a << endl; 
}

void Foo::methodString(const string& str)
{
    cout << "Foo::methodString(const string&)" << str << endl;
}

class Bar
{
public:
    void methodB();
};

void Bar::methodB()
{
    cout << "Bar::methodB()"<<endl;
}

int main()
{
    std::function<void()> f1;//无参数，无返回值
    Foo foo;
    f1 = std::bind(&Foo::methodA, &foo);
    f1();

    Bar bar;
    f1 = std::bind(&Bar::methodB, &bar);
    f1();

    f1 = std::bind(&Foo::methodInt, &foo, 209);
    f1();

    f1 = std::bind(&Foo::methodString, &foo, "hello f1");
    f1();

    std::function<void(int)>f2;
    f2 = std::bind(&Foo::methodInt, &foo, placeholders::_1);
    f2(410);

    std::function<void(const string&)> f3;
    f3 = std::bind(&Foo::methodString, foo, placeholders::_1);
    f3("hello f3");

    return 0;
}

