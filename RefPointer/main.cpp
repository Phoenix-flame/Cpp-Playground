#include <memory>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;
template<typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args){
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}


class Variable{
public:
	Variable() {
		LOG(&m_Message);
	}
	std::string m_Message = "empty";
private:
	
};


class Test{
public:
	Test() = default;

	void Print(){
		LOG(s_Variable.m_Message);
	}

	Variable& Get(){
		return s_Variable;
	}

private:
	static Variable s_Variable;
};
Variable Test::s_Variable;


int main(){
	Test t;
	t.Print();
	auto& m = t.Get().m_Message;
	LOG(&m);
	m = "Alireza";
	t.Print();
}