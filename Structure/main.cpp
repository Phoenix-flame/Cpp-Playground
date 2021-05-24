#include <iostream>
#include <cstdint>
#define print(x) std::cout << x << std::endl;
#define get(x) ((x==10)?t1->a:(x==11)?t1->a1:(x==12)?t1->a2:(x==13)?t1->a3:(x==14)?t1->a4:0.0)

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
	t1->a = 5;
	t1->a1 = 6;
	t1->a2 = 10;
	t1->a3 = 12;
	t1->a4 = 20;
	for (unsigned int i = 0 ; i < 5 ; i++){
		print(get(i + 10));
	}
	// print(OFFSETOF(test, a)); 
	// print(OFFSETOF(test, a1)); 
	// print(OFFSETOF(test, a2)); 
	// print(OFFSETOF(test, a3)); 
	// print(OFFSETOF(test, a4)); 
}
