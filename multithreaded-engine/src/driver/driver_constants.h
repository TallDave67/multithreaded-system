#ifndef DRIVER_CONSTANTS_H
#define DRIVER_CONSTANTS_H

namespace CR
{
    constexpr int max_os_threads = (1<<15) - (1<<11);
    constexpr int num_threads = max_os_threads;
}

#endif //DRIVER_CONSTANTS_H
