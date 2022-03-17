#include "cr_thread.h"
#include <thread>

namespace CR
{
    Thread::Thread()
        : thread_ftn(nullptr), thread_ptr(nullptr)
    {
    }

    Thread::~Thread()
    {
        delete thread_ptr;
    }

    void Thread::init(std::function<int()> _thread_ftn)
    {
        thread_ftn = std::move(_thread_ftn);
    }

    void Thread::run()
    {
        thread_ptr = new std::thread(thread_ftn);
    }

    void Thread::wait()
    {
        if(thread_ptr) thread_ptr->join();
    }

    std::thread::id Thread::get_id()
    {
        std::thread::id tid;
        if(thread_ptr) tid = thread_ptr->get_id();
        return tid;
    }
 
    std::thread::native_handle_type Thread::get_native_handle()
    {
        std::thread::native_handle_type hid;
        if(thread_ptr) hid = thread_ptr->native_handle();
        return hid;
    }
}