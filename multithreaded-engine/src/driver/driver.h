#ifndef _DRIVER_H_
#define _DRIVER_H_

#include "cr_thread.h"
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
        std::vector<CR::Thread> threads;
    };
}

#endif
