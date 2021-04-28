#include <iostream>
#include <string>

class Magic {
public:
	Magic() = default;
	Magic& operator=(const Magic&) = delete;
	Magic& operator=(Magic&& other) {

		this->num = std::move(other.get_num());
		delete other;
		return *this;
	}
	Magic(int magic_num);
	int get_num(){return num;}
	friend std::ostream& operator<<(std::ostream&, const Magic&);
private:
	int num;
};
std::ostream& operator<<(std::ostream& out, const Magic& magic){
	out << magic.num;
	return out;
}
Magic::Magic(int magic_num) {this->num = magic_num; }

int main(){
	Magic magic(5);
	std::cout << magic << std::endl;
	Magic another;
	another = std::move(magic);
	std::cout << another << std::endl;
	return 0;

}
