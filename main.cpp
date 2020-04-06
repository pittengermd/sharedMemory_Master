#include <iostream>
#include "sharedmemory.hh"
#include "sharedMemoryMasterMessage.pb.h"
#define UNMANAGED 1

using namespace sharedMemoryMasterMessage;


struct TestStruct
{
    uint32_t var1 {0}, var2 {0}, var3 {0}, var4 {0};
    bool var1Off {true}, var2Off {false}, var3Off {true}, var4Off {true};
};

Commands CreateCommandMessage(const TestStruct& input)
{

}


int main()
{
    std::string quit;
    SharedMemory MySharedMemory {"TestSharedMemory", sizeof(TestStruct), sharedMemMode::ReadWrite, sharedMemRole::Master };
    TestStruct MyTestStruct;
    Commands TestMessage;
    MySharedMemory.Create();
    MySharedMemory.Open();
    MySharedMemory.Write(MyTestStruct);
    std::cout << "Time to Quit[y/n]: ";
    while(1)
    {
        std::cin >> quit;
        if (quit == "y")
        {
            break;
        }
        else
        {
            MySharedMemory.Write(MyTestStruct);
            std::cout << "Time to Quit[y/n]: ";
        }
    }
    return 0;
}
