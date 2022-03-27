#ifndef TIME_HPP
#define TIME_HPP

#include <vector>
#include <systemc.h>
#include <cstdlib>

class Time
{
    public:
        Time(const size_t n, const unsigned int timearray[]);

        sc_core::sc_time GetTime();

    private:
        std::vector<unsigned int> timearray;
        unsigned int index;
        size_t length;
};

#endif
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

