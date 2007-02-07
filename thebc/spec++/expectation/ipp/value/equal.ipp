template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::equal(T1 const& expected)
{
    if(actual_m != expected)
    {
        std::string message = "actual value \"" + detail::to_string( actual_m ) 
                            + "\" should have been equal to \"" + detail::to_string( expected )
                            + "\"";
        throw expectation_notmet( message );
    }
    return true;
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::not_equal(T1 const& expected)
{
    if(actual_m == expected)
    {
        std::string message = "actual value \"" + detail::to_string( actual_m ) 
                            + "\" shouldn't have been equal to \"" + detail::to_string( expected )
                            + "\" but was";
        throw expectation_notmet( message );
    }
    return true;
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::operator==(T1 const& expected)
{
    return equal<T1>(expected);
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::operator!=(T1 const& expected)
{
    return not_equal<T1>(expected);
}
