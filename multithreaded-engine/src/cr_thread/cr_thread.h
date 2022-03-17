#ifndef _THREAD_H_
#define _THREAD_H_

#include "cr_thread_constants.h"
#include <functional>
#include <thread>

namespace CR
{
    class Thread
    {
    public:
        Thread();
        ~Thread();

        void init(std::function<int()> _thread_ftn);
        void run();
        void wait();

        std::thread::id get_id();
        std::thread::native_handle_type get_native_handle();

    private:
        std::function<int()> thread_ftn;
        std::thread* thread_ptr;
    };
}

#endif