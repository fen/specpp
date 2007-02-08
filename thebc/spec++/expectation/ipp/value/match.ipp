// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

#include <boost/regex.hpp>
// ---------------------------------------------------------------------------
template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::match(T1 const& pattern)
{
    boost::regex expression( pattern );

    if( boost::regex_match( actual_m, expression ) )
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m )
                        + "\" didn't match the pattern \"" + detail::to_string( pattern ) + "\"";

    throw expectation_notmet( message );
}
// ---------------------------------------------------------------------------
template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::not_match(T1 const& pattern)
{
    boost::regex expression( pattern );

    if( boost::regex_match( actual_m, expression ) )
    {
    std::string message = "actual value \"" + detail::to_string( actual_m )
                        + "\" did match the pattern \"" + detail::to_string( pattern ) 
                        + "\" but shouldn't have";
        throw expectation_notmet(message);
    }
    return true;
}
