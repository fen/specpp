template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::be_more_than(T1 const& lower_bound)
{
    if(actual_m > lower_bound)
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m )
                        + "\" should have been bigger than \"" + detail::to_string( lower_bound ) + "\"";

    throw expectation_notmet( message );
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::operator>(T1 const& lower_bound)
{
    return be_more_than<T1>( lower_bound );
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::be_less_than(T1 const& upper_bound)
{
    if(actual_m < upper_bound)
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m )
                        + "\" should have been less than \"" + detail::to_string( upper_bound ) + "\"";

    throw expectation_notmet( message );
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::operator<(T1 const& upper_bound)
{
    return be_less_than<T1>( upper_bound );
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::be_more_than_or_equal_to(T1 const& lower_bound)
{
    if( actual_m >= lower_bound )
    {
        return true;
    }
    std::string message = "actual value \"" + detail::to_string( actual_m )
                        + "\" should have been bigger than or equal to \"" 
                        + detail::to_string( lower_bound ) + "\"";

    throw expectation_notmet( message );
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::operator>=(T1 const& lower_bound)
{
    return be_more_than_or_equal_to( lower_bound );
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::be_less_than_or_equal_to(T1 const& upper_bound)
{
    if( actual_m <= upper_bound )
    {
        return true;
    }

    std::string message = "actual value \"" + detail::to_string( actual_m )
                        + "\" should have been less than or equal to \"" + detail::to_string( upper_bound ) + "\"";

    throw expectation_notmet( message );
}

template<typename T>
template<typename T1>
bool spec::detail::value::should<T>::operator<=(T1 const& upper_bound)
{
    return be_less_than_or_equal_to( upper_bound );
}
