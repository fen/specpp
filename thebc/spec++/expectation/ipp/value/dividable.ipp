// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------
template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::be_dividable_by(T1 const& expected)
{
    if( (actual_m % expected) == 0 )
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m ) 
                        + "\" should have been dividable by \"" + detail::to_string( expected )
                        + "\"";
    throw expectation_notmet( message );
}
// ---------------------------------------------------------------------------
template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::not_be_dividable_by(T1 const& expected)
{
    if( (actual_m % expected) != 0 )
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m ) 
                        + "\" should not have been dividable by \"" + detail::to_string( expected )
                        + "\" but was";
    throw expectation_notmet( message );
}
