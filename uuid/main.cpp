#include <iostream>
#include <chrono>
#include <thread>
#include "uuid.h"

int main(){
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << uuid::generate_uuid_v4() << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
	return 0;
}