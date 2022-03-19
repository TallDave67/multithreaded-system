#ifndef _THREAD_H_
#define _THREAD_H_

#include "thread_wrapper_constants.h"
#include <functional>
#include <thread>
#include <memory>

namespace CR
{
    class ThreadWrapper
    {
    private:
        static int max_wrapper_id;

    public:
        static int get_max_wrapper_id();

    public:
        ThreadWrapper();
        ~ThreadWrapper();

        //delete the copy constructor and copy assignment operator
        ThreadWrapper(const ThreadWrapper&) = delete;
        ThreadWrapper& operator=(const ThreadWrapper&) = delete;

        //create defauls of the move constructor and move assignment operator
        ThreadWrapper(ThreadWrapper&&) noexcept = default;
        ThreadWrapper& operator=(ThreadWrapper&&) noexcept = default;

        void run();
        void wait();
        void detach();
        bool is_done();

        int get_wrapper_id();
        std::thread::id get_id();
        std::thread::native_handle_type get_native_handle();

    private:
        int wrapper_id;
        std::unique_ptr<std::thread> thread_ptr;
        bool done;
    };
}

#endif