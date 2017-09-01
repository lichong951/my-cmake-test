#pragma once

#include <sstream>		        // std::ostringstream

/*************************************************************************************************************
**************************************************************************************************************
*************************************************************************************************************/

namespace hs
{
    // call this function to convert an arbitrary object to string
    template<class T>
    std::string toString(const T& v);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// helper

namespace hs
{
    // default stringifier, works for all types that can be inserted to a stream.
    //
    // if you have any type that should stringified in a different way, use (partial or full) specialization, optionally
    //   using std::enable_if on Holder, of Stringifier. See test/ToString.cpp for examples.
    template<typename T, typename Holder = void>
    struct Stringifier
    {
        static std::string apply(const T& v)
        {
            std::ostringstream s;
            s << v;
            return s.str();
        }
    };

    // implementation
    template<typename T>
    std::string toString(const T& v)
    {
        return Stringifier<T>::apply(v);
    }
}









