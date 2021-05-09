#include <iostream>
#include <string.h>
#include <memory>
#include <thread>
#include <functional>

#define LOG(x) std::cout << x << std::endl

struct Event{
	int point;
	int val;
};

class Child{
public:
	Child() = default;
	void SetCallback(std::function<void(const Event& e)> callback){
		m_Callback = callback;
	}
	void Run(){
		m_Callback({5, 10});
	}
private:
	std::function<void(const Event& e)> m_Callback;
};

class Main{
public:
	Main(){
		m_Child = std::make_shared<Child>();
		m_Child->SetCallback(
			[this](const Event& e){
				LOG(e.point);
				LOG(e.val);
			}
		);

		std::thread t1([this](){
			for (unsigned int i = 0 ; i < 100 ; i ++) {
				this->m_Child->Run();
			}
		});
		t1.join();
	}

private:
	void childCallback(){
		
	}
	std::shared_ptr<Child> m_Child;
};


int main(){
	Main m;

}
