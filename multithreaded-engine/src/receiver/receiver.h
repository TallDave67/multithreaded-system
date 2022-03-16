#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include "cr_thread.h"
#include <vector>

namespace CR
{
    class Receiver
    {
    public:
        Receiver();
        ~Receiver();

        bool init();
        void run();

    private:
        std::vector<CR::Thread> threads;
    };
}

#endif
