#include "driver.h"
#include "driver_constants.h"
#include <iostream>
#include <sstream>

#include <chrono>
using namespace std::chrono_literals;

namespace CR
{
    Driver::Driver()
    {
    }

    Driver::~Driver()
    {
    }

    bool Driver::init()
    {
        std::cout << "create " << CR::num_threads << " threads" << std::endl;
        for(int i = 0; i < CR::num_threads; i++)
        {
            threads.push_back(CR::ThreadWrapper());
        }
        return true;
    }

    void Driver::run()
    {
        for(auto & t : threads)
        {
            t.run();
            //
            std::thread::native_handle_type hid = t.get_native_handle();
            std::stringstream ss;
            ss << "thread_wrapper (wrapper " << t.get_wrapper_id() << ") with (id " << t.get_id() << ") with (native handle " << hid << ") is launched" << std::endl;
            std::cout << ss.str();
        }

        /*
        for(auto & t : threads)
        {
            t.wait();
            std::stringstream ss;
            ss << "thread_wrapper (wrapper " << t.get_wrapper_id() << ") is terminated" << std::endl;
            std::cout << ss.str();
        }
        */

        
        for(auto & t : threads)
        {
            t.detach();
            //std::stringstream ss;
            //ss << "thread_wrapper (wrapper " << t.get_wrapper_id() << ") is detached" << std::endl;
            //std::cout << ss.str();
        }
        

        bool done = false;
        while(!done)
        {
            std::this_thread::sleep_for(1000ms);
            done = true;
            for(auto & t : threads)
            {
                if(!t.is_done())
                {
                    done = false;
                    break;
                }
            }
        }
        std::stringstream ss;
        ss << "all " << CR::ThreadWrapper::get_max_wrapper_id() << " child threads are done" << std::endl;
        std::cout << ss.str();

    }

}