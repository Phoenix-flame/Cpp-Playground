#include <Publisher.h>
#include <stdexcept>

Publisher::~Publisher(){
    LinkedList_destroyDeep(m_DataSetValues, (LinkedListValueDeleteFunction) MmsValue_delete);
}


void Publisher::Init(){
    m_DataSetValues = LinkedList_create();

	LinkedList_add(m_DataSetValues, MmsValue_newIntegerFromInt32(1234));
	LinkedList_add(m_DataSetValues, MmsValue_newBinaryTime(false));
	LinkedList_add(m_DataSetValues, MmsValue_newIntegerFromInt32(5678));

	CommParameters gooseCommParameters;

	gooseCommParameters.appId = 1000;
	gooseCommParameters.dstAddress[0] = 0x01;
	gooseCommParameters.dstAddress[1] = 0x0c;
	gooseCommParameters.dstAddress[2] = 0xcd;
	gooseCommParameters.dstAddress[3] = 0x01;
	gooseCommParameters.dstAddress[4] = 0x00;
	gooseCommParameters.dstAddress[5] = 0x01;
	gooseCommParameters.vlanId = 0;
	gooseCommParameters.vlanPriority = 4;

    m_Publisher = GoosePublisher_create(&gooseCommParameters, m_Interface.c_str());
    if (! m_Publisher){
        throw std::runtime_error("Failed to create GOOSE publisher. Reason can be that the Ethernet interface doesn't exist or root permission are required.");
    }
}


void Publisher::Run(){
    GoosePublisher_setGoCbRef(m_Publisher, "simpleIOGenericIO/LLN0$GO$gcbAnalogValues");
    GoosePublisher_setConfRev(m_Publisher, 1);
    GoosePublisher_setDataSetRef(m_Publisher, "simpleIOGenericIO/LLN0$AnalogValues");

    int i = 0;

    for (i = 0; i < 3; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (GoosePublisher_publish(m_Publisher, m_DataSetValues) == -1) {
            printf("Error sending message!\n");
        }
    }

    GoosePublisher_destroy(m_Publisher);
}
