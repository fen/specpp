// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------
template<typename T>
bool spec::detail::value::should<T>::be_even()
{
    if( (actual_m % 2) == 0 )
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m ) 
                        + "\" should have been even but was not";
    throw expectation_notmet( message );
}
// ---------------------------------------------------------------------------
template<typename T>
bool spec::detail::value::should<T>::be_odd()
{
    if( (actual_m % 2) != 0 )
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m ) 
                        + "\" should have been odd but was not";
    throw expectation_notmet( message );
}
