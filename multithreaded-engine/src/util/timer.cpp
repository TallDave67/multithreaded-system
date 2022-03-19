#include "timer.h"
#include "util_constants.h"
#include <iostream>
#include <sstream>

namespace CR
{
    Timer::Timer(int _id) 
        : id(_id)
    {
    }

    Timer::~Timer()
    {
    }

    void Timer::add_timepoint(const std::string & _name)
    {
        uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        timepoints.push_back({_name, ns});
    }

    void Timer::display_timepoints()
    {
        if(timepoints.size() >= 2)
        {
            std::stringstream ss;
            ss << "timer (id " << id << ")" << std::endl;
            for(int i = 1; i < timepoints.size(); i++)
            {
                auto dur = timepoints[i].timepoint - timepoints[i - 1].timepoint;
                ss << "    timepoint " << timepoints[i].name << ": " << dur << "ns" << std::endl;
            }
            ss << "    total: " << (timepoints[timepoints.size()-1].timepoint - timepoints[0].timepoint) << "ns" << std::endl;
            std::cout << ss.str();
        }
    }
}
