#pragma once
#include <string>
#include <libiec61850/goose_publisher.h>
#include <libiec61850/mms_value.h>
#include <thread>
#include <chrono>


class Publisher{
public:
    Publisher() = default;
    ~Publisher();

    void Init();
    void Run();

private:
    std::string m_Interface = "enp4s0f2";
    LinkedList m_DataSetValues;
    GoosePublisher m_Publisher;
};

