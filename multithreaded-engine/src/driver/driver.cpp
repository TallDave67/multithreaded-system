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
            CR::Thread crt;
            crt.init(
                []()
                {
                    std::stringstream ss;
                    ss << "    hello from cr_thread (" << std::this_thread::get_id() << ")" << std::endl;
                    std::cout << ss.str();
                    std::this_thread::sleep_for(50ms);
                    return 0;
                }
            );
            threads.push_back(std::move(crt));
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
            ss << "cr_thread (" << t.get_id() << ") with (native handle = " << hid << ") is running" << std::endl;
            std::cout << ss.str();
        }

        for(auto & t : threads)
        {
            t.wait();
            std::stringstream ss;
            ss << "cr_thread (" << t.get_id() << ") is terminated" << std::endl;
            std::cout << ss.str();
        }
    }

}