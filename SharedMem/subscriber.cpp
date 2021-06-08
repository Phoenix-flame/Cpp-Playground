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
    ConfiguratorMsg *value1 = (ConfiguratorMsg*) shmat(shmid,(void*)0,0);
    //int *value2 = (int*) shmat(shmid,(void*)1,0);
    value1->SPIConfig_Waiting = true;
	value1->SPIConfig_CRCError = false;
    std::thread a([&](){
    	while(true){
    		value1->SPIConfig_CRCError ^= true;
    		value1->SPIConfig_Waiting ^= true;
    		std::cout << value1->SPIData_CRCError << value1->SPIData_Waiting << std::endl;
    		std::this_thread::sleep_for(std::chrono::seconds(1));
    	}
    });
    a.join();
    //detach from shared memory 
    shmdt(value1);
    
    // destroy the shared memory
    shmctl(shmid,IPC_RMID,NULL);
     
    return 0;
}
