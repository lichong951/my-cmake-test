#pragma once

#include <cassert>              // assert
#include <type_traits>          // std::enable_if
#include <sstream>		        // std::ostringstream
#include <Toolchain.hpp>		// HS_TOOLCHAIN_MSC
#include <HasMember.hpp>     // HS_HAS_MEMBER_TYPE
#include <ToString.hpp>      // hs::Stringifier
#include "stdio.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// hs::HighResolutionClock

#ifdef HS_TOOLCHAIN_MSC

#include <hs/platform/win/HighResolutionClock.hpp>   // hs::platform::win::HighResolutionClock

namespace hs
{
    using HighResolutionClock = platform::win::HighResolutionClock;
}

#else

// use standard c++11 chrono
#include <chrono>                                   // std::chrono::high_resolution_clock

namespace hs
{
    using HighResolutionClock = std::chrono::high_resolution_clock;
}

#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace hs
{
    namespace details
    {
        // measure measureable f() value changes. For example, f() could be a clock function, and measureChange() returns observable clock changes.
        template<class F>
        auto measureChange(F f) -> decltype(f() - f())
        {
            auto t0 = f();
            auto t1 = f();
            while (t1 == t0)
                t1 = f();
            auto t2 = f();
            while (t2 == t1)
                t2 = f();
            return t2 - t1;
        }

        // return the minimum value of f() in a few tries.
        template<class F>
        auto measureMinimum(F f, size_t tries) -> decltype(f())
        {
            assert(tries >= 1);

            auto v0 = f();
            for (size_t i = 1; i < tries; ++i)
            {
                auto v = f();
                if (v < v0)
	                v0 = v;
            }
            return v0;
        }

    } // details
} // hs

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace hs
{
    // measure the empirical resolution of a clock concept in std::chrono
    template<typename Clock>
    auto measureEmpiricalResolution(size_t tries = 1) -> decltype(Clock::now() - Clock::now())
    {
        return details::measureMinimum([](){
            return details::measureChange([](){
                return Clock::now();
            });
        }, tries);
    }
} // hs


namespace hs
{
    namespace details
    {
        // The macros below will create new classes. Embed in details namespace to avoid conflict with others.

        // for checking T::rep and T::period.
        HS_HAS_MEMBER_TYPE(rep)
        HS_HAS_MEMBER_TYPE(period)

        // check if Duration conforms to std::chrono::duration, i.e., see if Duration::rep and Duration::period member types exist.
        template<class Duration>
        struct IsDuration
        {
            static const bool value = hasMemberType_rep<Duration>::value && hasMemberType_period<Duration>::value;
        };

        // convert a std::chrono clock duaration to a string in readable form.
        template<class Duration>
        std::string durationToString(Duration duration)
        {
            static_assert(details::IsDuration<Duration>::value, "not a duration");

            double dur = duration.count() * double(Duration::period::num) / Duration::period::den;    // in seconds
            std::ostringstream s;
            if (dur >= 1e0)
                s << std::fixed << dur*1e0 << " s";
            else if (dur >= 1e-3)
                s << std::fixed << dur*1e3 << " ms";
            else if (dur >= 1e-6)
                s << std::fixed << dur*1e6 << " us";
            else if (dur >= 1e-9)
                s << std::fixed << dur*1e9 << " ns";
            else if (dur >= 1e-12)
                s << std::fixed << dur*1e12 << " ps";
            else
                s << std::fixed << dur*1e15 << " fs";
            return s.str();
        }

    } // details

    // partial specialization of Stringifier for all Duration types of T.
    // with this, you can now use hs::toString(Duration duration). see ToString.hpp.
    template<typename T>
    struct Stringifier<T, typename std::enable_if<details::IsDuration<T>::value>::type>
    {
        static std::string apply(const T& v) { return details::durationToString(v); }
    };

} // hs


