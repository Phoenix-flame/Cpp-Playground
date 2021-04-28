#include <vector>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;



int main(){
	std::vector<unsigned char> a, b;

	std::vector<unsigned char> v;
	for (unsigned int i = 'A' ; i < 'G' ; i++){
		v.push_back(i);
	}

	a = std::move(v);

	unsigned char* ap = a.data();
	unsigned char* bp = new unsigned char[5];

	b.resize(a.size());

	for (int i = 0 ; i < 5 ; i++){
		bp[i] = 'A';
	}

	for (auto i:b)
		LOG(i);

}