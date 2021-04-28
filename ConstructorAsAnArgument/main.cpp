#include <iostream>
#include <string>
#include <map>
class Test{
public:
	Test() = default;
	Test(std::string name, int grade){
		m_Name = name;
		m_Grade = grade;
	}
	Test& operator=(const Test& t){
		m_Grade = t.m_Grade;
		m_Name = t.m_Name;
		return *this;
	}
	void print(){
		std::cout << m_Name << ": " << m_Grade << std::endl;
	}
	std::string GetName() { return m_Name; }
	int GetGrade() { return m_Grade; }
private:
	std::string m_Name;
	int m_Grade;
};

class Container{
public:
	Container() =default;
	void AddTest(Test&& t){
		// t.print();
		if (con.find(t.GetName()) != con.end()){
			con[t.GetName()] = t;
		}
		else{
			con.insert(std::pair<std::string, Test>(t.GetName(), t));
		}
	}
	void print(){
		for (auto i: con){
			 i.second.print();
		}
	}

	std::map<std::string, Test> con;
};

int main(){
	Container con;
	con.AddTest({"Alireza", 85});
	con.AddTest({"Alireza", 95});
	con.AddTest({"Alireza", 100});
	con.AddTest({"Reza", 94});
	con.print();
}
