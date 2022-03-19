#include <iostream>
#include "driver.h"

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        std::cout << "usage: multithreaded-engine" << std::endl;
        return -1;
    }

    CR::Driver driver;
    if (driver.init())
    {
        driver.run();
        std::cout << "driver ran" << std::endl;
        return 0;
    }

    std::cout << "driver did not run" << std::endl;
    return -1;
}

