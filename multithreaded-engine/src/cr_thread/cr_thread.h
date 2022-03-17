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

        void run();
        void wait();
        void detach();
        bool is_done();

        std::thread::id get_id();
        std::thread::native_handle_type get_native_handle();

    private:
        std::thread* thread_ptr;
        bool done;
    };
}

#endif