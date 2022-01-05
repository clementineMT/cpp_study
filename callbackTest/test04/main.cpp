#include <functional>
#include <iostream>
using namespace std;
int main()
{
	auto f = [](const int a, const int b) {
	//	cout << a+b << endl;
		return a + b; };
	std::function<int(int, int)>func = f;

	
	cout << func(1, 2) << endl;      // 3
	while(1);
	return 0;
}
