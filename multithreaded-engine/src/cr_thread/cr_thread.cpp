#include "cr_thread.h"
#include <thread>

namespace CR
{
    Thread::Thread()
        : thread_ftn(nullptr)
    {
    }

    Thread::~Thread()
    {
    }

    bool Thread::init(std::function<int()> _thread_ftn)
    {
        thread_ftn = std::move(_thread_ftn);
        return true;
    }

    void Thread::run()
    {
        std::thread t {thread_ftn};
        t.join();
    }

}