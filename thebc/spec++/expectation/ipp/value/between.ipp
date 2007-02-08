// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

template<typename T>
template<typename T1>
spec::detail::value::between<T, T1> 
spec::detail::value::should<T>::be_between(T1 const& lower_bound)
{
    bool lower = false;
    if( actual_m > lower_bound )
    {
        lower = true;
    }
    return between<T, T1>( actual_m, lower_bound, lower, false );
}
// ---------------------------------------------------------------------------
template<typename T>
template<typename T1>
spec::detail::value::between<T, T1> 
spec::detail::value::should<T>::not_be_between(T1 const& lower_bound)
{
    bool lower = false;
    if( actual_m > lower_bound )
    {
        lower = true;
    }

    return between<T, T1>( actual_m, lower_bound, lower, true );
}
// ---------------------------------------------------------------------------
template<typename T>
template<typename T1>
spec::detail::value::between_equal<T,T1> 
spec::detail::value::should<T>::be_between_or_equal_to(T1 const& lower_bound)
{
    bool lower = false;
    if( actual_m >= lower_bound )
    {
        lower = true;
    }
    return between_equal<T, T1>( actual_m, lower_bound, lower, false );
}
// ---------------------------------------------------------------------------
template<typename T>
template<typename T1>
spec::detail::value::between_equal<T,T1> 
spec::detail::value::should<T>::not_be_between_or_equal_to(T1 const& lower_bound)
{
    bool lower = false;
    if( actual_m >= lower_bound )
    {
        lower = true;
    }

    return between_equal<T, T1>( actual_m, lower_bound, lower, true );
}
// ---------------------------------------------------------------------------
namespace spec { namespace detail { namespace value {
// ---------------------------------------------------------------------------
template<typename T, typename T2>
struct between
{
    explicit between(T& actual, T2 const& lower_bound, bool lower, bool should_not)
    :actual_m( actual ), lower_bound_( lower_bound ), lower_( lower ), should_not_( should_not ){}

    template<typename T1>
    bool And(T1 const& upper_bound)
    {
        bool upper = false;
        if( actual_m < upper_bound )
        {
            upper = true;
        }

        if( should_not_ )
        {
            if( !upper || !lower_ )
            {
                return true;
            }
            std::string message = "actual value \"" + detail::to_string( actual_m )
                                + "\" should not have been between \""
                                + detail::to_string( lower_bound_ ) + "\" and \""
                                + detail::to_string( upper_bound ) + "\"";
            throw expectation_notmet( message );
        }
        else
        {
            if( upper && lower_ )
            {
                return true;
            }
            std::string message = "actual value \"" + detail::to_string( actual_m )
                                + "\" should have been between \""
                                + detail::to_string( lower_bound_ ) + "\" and \""
                                + detail::to_string( upper_bound ) + "\"";
            throw expectation_notmet( message );
        }
    }

    template<typename T1>
    bool operator&&(T1 const& upper_bound)
    {
        return And( upper_bound );
    }

    T& actual_m;
    T2 const& lower_bound_;
    bool lower_;
    bool should_not_;
};
// ---------------------------------------------------------------------------
template<typename T, typename T2>
struct between_equal
{
    explicit between_equal(T& actual, T2 const& lower_bound, bool lower, bool should_not)
        :actual_m( actual ), lower_bound_( lower_bound ), lower_( lower ), should_not_( should_not ){}

    template<typename T1>
    bool And(T1 const& upper_bound)
    {
        bool upper = false;
        if( actual_m <= upper_bound )
        {
            upper = true;
        }

        if( should_not_ )
        {
            if( !upper || !lower_ )
            {
                return true;
            }
            std::string message = "actual value \"" + detail::to_string( actual_m )
                                + "\" should not have been between or equal to \""
                                + detail::to_string( lower_bound_ ) + "\" and \""
                                + detail::to_string( upper_bound ) + "\"";
            throw expectation_notmet( message );
        }
        else
        {
            if( upper && lower_ )
            {
                return true;
            }
            std::string message = "actual value \"" + detail::to_string( actual_m )
                                + "\" should have been between or equal to \""
                                + detail::to_string( lower_bound_ ) + "\" and \""
                                + detail::to_string( upper_bound ) + "\"";
            throw expectation_notmet( message );
        }
    }

    template<typename T1>
    bool operator&&(T1 const& upper_bound)
    {
        return And( upper_bound );
    }

    T& actual_m;
    T2 const& lower_bound_;
    bool lower_;
    bool should_not_;
};
// ---------------------------------------------------------------------------
}}} // namespace spec::detail::value
