#ifndef _TIMER_H_
#define _TIMER_H_

#include <string>
#include <chrono>
#include <vector>

namespace CR
{
    typedef struct _TimePoint
    {
        std::string name;
        uint64_t timepoint;

        _TimePoint(const std::string & _name, uint64_t _timepoint)
        {
            name = _name;
            timepoint = _timepoint;
        }
    }TimePoint;

    class Timer
    {
    public:
        Timer(int _id);
        ~Timer();

        void add_timepoint(const std::string & _name);
        void display_timepoints();

    private:
        int id;
        std::vector<TimePoint> timepoints;
    };
}

#endif
