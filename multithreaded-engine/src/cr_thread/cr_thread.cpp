#include "cr_thread.h"
#include <thread>
#include <iostream>
#include <chrono>
#include <sstream>

using namespace std::chrono_literals;

namespace CR
{
    int Thread::max_wrapper_id = 0;

    Thread::Thread()
        : thread_ptr(nullptr), done(false)
    {
        Thread::max_wrapper_id++;
        wrapper_id = Thread::max_wrapper_id;
    }

    Thread::~Thread()
    {
        if(thread_ptr)
        {
            std::cout << "cr_thread (wrapper " << get_wrapper_id() << ") has an std::thread to destroy" << std::endl;
            if(thread_ptr->joinable())
            {
                std::cout << "    the std::thread is joinable, so we must join it before destruction" << std::endl;
                thread_ptr->join();
            }
            delete thread_ptr;
        }
    }

    void Thread::run()
    {
        auto &done_l = done;
        thread_ptr = new std::thread(
            [&done_l]()
            {
                std::stringstream ss;
                ss << "    cr_thread (id " << std::this_thread::get_id() << ") is alive" << std::endl;
                std::cout << ss.str();
                std::this_thread::sleep_for(1000ms);
                ss.str("");
                ss << "    cr_thread (id " << std::this_thread::get_id() << ") is waking up" << std::endl;
                std::cout << ss.str();
                done_l = true;
                return 0;
            }
        );
    }

    void Thread::wait()
    {
        if(thread_ptr) thread_ptr->join();
    }

    void Thread::detach()
    {
        if(thread_ptr) thread_ptr->detach();
    }

    bool Thread::is_done()
    {
        std::stringstream ss;
        ss << "cr_thread (wrapper " << get_wrapper_id() << ") is_done = " << done << std::endl;
        std::cout << ss.str();
        return done;
    }

    int Thread::get_wrapper_id()
    {
        return wrapper_id;
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