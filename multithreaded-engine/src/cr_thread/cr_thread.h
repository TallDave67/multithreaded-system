#ifndef _THREAD_H_
#define _THREAD_H_

#include "cr_thread_constants.h"
#include <functional>

namespace CR
{
    class Thread
    {
    public:
        Thread();
        ~Thread();

        bool init(std::function<int()> _thread_ftn);
        void run();

    private:
        std::function<int()> thread_ftn;
    };
}

#endif