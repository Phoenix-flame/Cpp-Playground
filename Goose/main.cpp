#include <iostream>
#include <Publisher.h>

int main(int argc, char** argv){
    std::cout << "Hello World!" << std::endl;
    Publisher publisher;
    try{
        publisher.Init();
        publisher.Run();
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return -1;
    }
    
    
    return 0;
}