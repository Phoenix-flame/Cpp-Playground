#include <map>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;


class Test{
public:
	Test() = default;
	Test(int a, int b): a(a), b(b){}
	void Print(){
		std::cout << "[" << a << ", " << b << "]" << std::endl;
	}
private:
	int a;
	int b;
};

int main(){
	std::map<int , Test> tests;
	tests.insert({1, {5, 6}});
	tests[1].Print();
}