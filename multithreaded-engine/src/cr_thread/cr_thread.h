#ifndef _THREAD_H_
#define _THREAD_H_

#include "cr_thread_constants.h"
#include <functional>
#include <thread>

namespace CR
{
    class Thread
    {
        static int max_wrapper_id;

    public:
        Thread();
        ~Thread();

        //delete the copy constructor and copy assignment operator
        Thread(const Thread&) = delete;
        Thread& operator=(const Thread&) = delete;

        //create defauls of the move constructor and move assignment operator
        Thread(Thread&&) noexcept = default;
        Thread& operator=(Thread&&) noexcept = default;

        void run();
        void wait();
        void detach();
        bool is_done();

        int get_wrapper_id();
        std::thread::id get_id();
        std::thread::native_handle_type get_native_handle();

    private:
        int wrapper_id;
        std::thread* thread_ptr;
        bool done;
    };
}

#endif