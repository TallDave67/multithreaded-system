#include "receiver.h"
#include "receiver_constants.h"
#include <iostream>

namespace CR
{
    Receiver::Receiver()
    {
    }

    Receiver::~Receiver()
    {
    }

    bool Receiver::init()
    {
        CR::Thread cr_t1;
        cr_t1.init(
            []()
            {
                std::cout << "hello from cr_thread 1" << std::endl;
                return 0;
            }
        );
        threads.push_back(std::move(cr_t1));
        return true;
    }

    void Receiver::run()
    {
        for(auto & t : threads) t.run();
    }

}