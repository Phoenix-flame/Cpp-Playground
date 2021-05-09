#include <iostream>
#include <cstdint>
#define print(x) std::cout << x << std::endl;
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))

struct test{
	int a;
	int a1;
	int a2;
	int a3;
	int a4;
};


int main(){
	print("alireza" << 5);
	test *t1 = new test();
	*((uint8_t*)t1 + OFFSETOF(test, a1)) = 5; 
	print(t1->a1);
	// print(OFFSETOF(test, a)); 
	// print(OFFSETOF(test, a1)); 
	// print(OFFSETOF(test, a2)); 
	// print(OFFSETOF(test, a3)); 
	// print(OFFSETOF(test, a4)); 
}