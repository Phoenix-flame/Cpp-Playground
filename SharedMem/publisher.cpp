#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <thread>
using namespace std;
  
  
struct ConfiguratorMsg{
	bool SPIData_CRCError;
	bool SPIData_Waiting;
	bool SPIConfig_CRCError;
	bool SPIConfig_Waiting;
};
  
int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);
  
    // shmget returns an identifier in shmid
    int shmid = shmget(key,sizeof(ConfiguratorMsg),0666|IPC_CREAT);
  
    // shmat to attach to shared memory
    ConfiguratorMsg* val1 = (ConfiguratorMsg*) shmat(shmid,(void*)0, 0);
	std::cout << "Here" << std::endl;
	val1->SPIData_Waiting = true;
	val1->SPIData_CRCError = false;

  
  std::thread a([&](){
    	while(true){
    		val1->SPIData_CRCError ^= true;
    		val1->SPIData_Waiting ^= true;
		std::cout << val1->SPIConfig_CRCError << val1->SPIConfig_Waiting << std::endl;
    		std::this_thread::sleep_for(std::chrono::seconds(1));
    	}
    });
    a.join();
      
    //detach from shared memory 
    shmdt(val1);

  
    return 0;
}
