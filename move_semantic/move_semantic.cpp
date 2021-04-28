#include <iostream>
#include <string.h>

#define LOG(x) std::cout << x << std::endl

class String{
public:
	String(const char* data){
		LOG("Created!");
		m_Size = strlen(data);
		m_Data = new char[m_Size];
		memcpy(m_Data, data, m_Size);
	}

	String(const String& other){
		LOG("Copied!");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept{
		LOG("Moved!");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	String& operator=(const String& other){
		LOG("Copied!");


		if(this != &other){
			delete[] m_Data;
			m_Size = other.m_Size;
			m_Data = new char[m_Size];
			memcpy(m_Data, other.m_Data, m_Size);
		}
		return *this;
	}

	String& operator=(String&& other){
		LOG("Moved!");

		if (this != &other){
			delete[] m_Data;

			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Size = 0;
			other.m_Data = nullptr;	
		}
		return *this;
	}

	~String(){
		LOG("Destroyed!");
		delete m_Data;
	}

	void Print(){
		for (unsigned int i = 0 ; i < m_Size ; i++){
			std::cout << m_Data[i];
		}
		std::cout << std::endl;
	}

private:
	char* m_Data;
	unsigned int m_Size;
};


class Entity{
public:
	Entity(const String& name) : m_Name(name) {}

	Entity(String&& name) : m_Name(std::move(name)) {}

	void PrintName(){
		m_Name.Print();
	}
private:
	String m_Name;
};

int main(){
	String name1 = "Phoenix_flame";
	String name2 = "Alireza";
	String name3 = "Mohammadi";

	std::cout << "1:\t";name1.Print();
	std::cout << "2:\t";name2.Print();
	std::cout << "3:\t";name3.Print();

	name2 = name1;
	name3 = std::move(name1);
	std::cout << "1:\t";name1.Print();
	std::cout << "2:\t";name2.Print();
 	std::cout << "3:\t";name3.Print();
}
