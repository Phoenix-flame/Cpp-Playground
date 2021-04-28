#include <chrono>
#include <thread>



class Timer{
public:
    Timer(){}
    void Reset(){
        started = false;
        clock = std::chrono::high_resolution_clock::now();
    }
    void Start(){
        started = true;
        clock = std::chrono::high_resolution_clock::now();
    }

    template<typename T>
    int getElapsedTime(){
        if (!started){ return 0;}
        auto end = std::chrono::high_resolution_clock::now();
        return (std::chrono::duration_cast<T>(end - clock).count());
    }
    
    operator bool(){
        return this->started;
    }

private:
    bool started = false;
    std::chrono::system_clock::time_point clock;
};