// � Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::be(T1 const& expected)
{
    if(actual_m == expected)
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m )
                        + "\" should have been \"" + detail::to_string( expected ) + "\"";
    throw expectation_notmet( message );
}
// ---------------------------------------------------------------------------
template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::not_be(T1 const& expected)
{
    if(actual_m != expected)
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m )
                        + "\" shouldn't have been \"" + detail::to_string( expected ) + "\" but was";
    throw expectation_notmet( message );
}