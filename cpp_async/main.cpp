#include <iostream>
#include <vector>
#include <future>
#include <string>
#include <mutex>
#include <algorithm>
#include <numeric>

int foo(){
	std::cout << " 1 + 2 = " << 1 + 2 << std::endl;
	return 1 + 2;
}

int main(){
	auto a1 = std::async(&foo);
	std::cout << a1.get() << std::endl;


}
