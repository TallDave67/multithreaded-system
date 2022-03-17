#ifndef _DRIVER_H_
#define _DRIVER_H_

#include "thread_wrapper.h"
#include <vector>

namespace CR
{
    class Driver
    {
    public:
        Driver();
        ~Driver();

        bool init();
        void run();

    private:
        std::vector<CR::ThreadWrapper> threads;
    };
}

#endif
