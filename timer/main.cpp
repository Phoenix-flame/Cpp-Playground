#include <iostream>

#include "timer.h"

int main(){

    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto test = 	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << test << std::endl;

    return 0;
}
