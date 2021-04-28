#include <thread>
#include <future>
#include <iostream>


int main(){
	std::promise<int> promiseObj;
	std::future<int> futureObj = promiseObj.get_future();

	auto t_fun = [](std::promise<int>* promiseObj){
		promiseObj->set_value(128);
	};
	std::thread t(t_fun, &promiseObj);
	std::cout << "future value: " << futureObj.get() << std::endl;
	t.detach();	
}
