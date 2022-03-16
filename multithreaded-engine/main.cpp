#include <iostream>
#include "receiver.h"

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        std::cout << "usage: multithreaded-engine" << std::endl;
        return -1;
    }

    CR::Receiver receiver;
    if (receiver.init())
    {
        receiver.run();
        std::cout << "receiver ran" << std::endl;
        return 0;
    }

    std::cout << "receiver did not run" << std::endl;
    return -1;
}
