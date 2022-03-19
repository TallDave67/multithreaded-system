#include "thread_wrapper.h"
#include "thread_wrapper_constants.h"
#include "timer.h"
#include <thread>
#include <iostream>
#include <sstream>
#include <mutex>

//#include <chrono>
//using namespace std::chrono_literals;

std::mutex g_shared_resource_mutex;

namespace CR
{
    int ThreadWrapper::max_wrapper_id = 0;
    int ThreadWrapper::get_max_wrapper_id()
    {
        return ThreadWrapper::max_wrapper_id;
    }

    ThreadWrapper::ThreadWrapper()
        : thread_ptr(nullptr), done(false)
    {
        ThreadWrapper::max_wrapper_id++;
        wrapper_id = ThreadWrapper::max_wrapper_id;
    }

    ThreadWrapper::~ThreadWrapper()
    {
        if(thread_ptr)
        {
            std::cout << "thread_wrapper (wrapper " << get_wrapper_id() << ") has an std::thread to destroy" << std::endl;
            if(thread_ptr->joinable())
            {
                std::cout << "    the std::thread is joinable, so we must join it before destruction" << std::endl;
                thread_ptr->join();
            }
        }
    }

    void ThreadWrapper::run()
    {
        auto id = wrapper_id;
        auto &done_l = done;
        thread_ptr = std::make_unique<std::thread>(
            [id, &done_l]()
            {
                CR::Timer timer(id);
                timer.add_timepoint(CR::timepoint_start);

                //g_shared_resource_mutex.lock();
                //timer.add_timepoint(CR::timepoint_got_lock);

                std::stringstream ss;
                ss << "thread_wrapper (id " << std::this_thread::get_id() << ") is running" << std::endl;
                std::cout << ss.str();

                //std::this_thread::sleep_for(50ms);
                //ss.str("");
                //ss << "thread_wrapper (id " << std::this_thread::get_id() << ") is waking up" << std::endl;
                //std::cout << ss.str();

                //g_shared_resource_mutex.unlock();

                timer.add_timepoint(CR::timepoint_end);
                timer.display_timepoints();
                done_l = true;
                return 0;
            }
        );
    }

    void ThreadWrapper::wait()
    {
        if(thread_ptr) thread_ptr->join();
    }

    void ThreadWrapper::detach()
    {
        if(thread_ptr) thread_ptr->detach();
    }

    bool ThreadWrapper::is_done()
    {
        std::stringstream ss;
        ss << "thread_wrapper (wrapper " << get_wrapper_id() << ") is_done = " << done << std::endl;
        std::cout << ss.str();
        return done;
    }

    int ThreadWrapper::get_wrapper_id()
    {
        return wrapper_id;
    }

    std::thread::id ThreadWrapper::get_id()
    {
        std::thread::id tid;
        if(thread_ptr) tid = thread_ptr->get_id();
        return tid;
    }
 
    std::thread::native_handle_type ThreadWrapper::get_native_handle()
    {
        std::thread::native_handle_type hid;
        if(thread_ptr) hid = thread_ptr->native_handle();
        return hid;
    }

}