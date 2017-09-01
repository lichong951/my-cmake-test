#pragma once

#include <chrono>                           // std::chrono
#include <hs/HighResolutionClock.hpp>       // hs::HighResolutionClock
#include <hs/IntTypes.hpp>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// timestamp and stamper

namespace hs
{
    using Timestamp = Uint64;   // should hold long time even if unit is nanoseconds


    // stamp current time in nanoseconds.
    inline Timestamp stampNs()
    {
        return std::chrono::duration_cast< std::chrono::nanoseconds > ( HighResolutionClock::now().time_since_epoch() ).count();
    }

    // stamp current time in microseconds.
    inline Timestamp stampUs()
    {
        return std::chrono::duration_cast< std::chrono::microseconds > (HighResolutionClock::now().time_since_epoch()).count();
    }

    // stamp current time in milliseconds.
    inline Timestamp stampMs()
    {
        return std::chrono::duration_cast< std::chrono::milliseconds > (HighResolutionClock::now().time_since_epoch()).count();
    }

    // get time stamp of current (now)
    inline Timestamp stamp() { return stampNs(); }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    inline Timestamp measureStampEmpiricalResolution(Timestamp(*stamp_func)(), size_t tries = 1)
    {
        return details::measureMinimum([=](){
            return details::measureChange([=](){
                return stamp_func();
            });
        }, tries);
    }

} // hs
