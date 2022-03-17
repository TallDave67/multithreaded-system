#include "driver.h"
#include "driver_constants.h"
#include <iostream>
#include <chrono>
#include <sstream>

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
        for(int i = 0; i < CR::num_threads; i++)
        {
            threads.push_back(CR::Thread());
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
            ss << "cr_thread (wrapper " << t.get_wrapper_id() << ") with (id " << t.get_id() << ") with (native handle " << hid << ") is running" << std::endl;
            std::cout << ss.str();
        }

        /*
        for(auto & t : threads)
        {
            t.wait();
            std::stringstream ss;
            ss << "cr_thread (wrapper " << t.get_wrapper_id() << ") is terminated" << std::endl;
            std::cout << ss.str();
        }
        */

        
        for(auto & t : threads)
        {
            t.detach();
            std::stringstream ss;
            ss << "cr_thread (wrapper " << t.get_wrapper_id() << ") is detached" << std::endl;
            std::cout << ss.str();
        }
        

        bool done = false;
        while(!done)
        {
            std::this_thread::sleep_for(50ms);
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
        ss << "all child threads are done" << std::endl;
        std::cout << ss.str();

    }

}