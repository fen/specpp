#ifndef THEBC_SPECPP_EXPECTATION_GROUPS_INTEGER_INTEGER_HPP
#define THEBC_SPECPP_EXPECTATION_GROUPS_INTEGER_INTEGER_HPP

#include "../../detail/if_not_impl.hpp"
#include "equal_function.hpp"
#include "more_less_function.hpp"

namespace spec { namespace groups {

template<typename Actual, bool Not = false>
struct integer_t: detail::if_not_impl<integer_t, Actual, Not> 
{
    integer_t(Actual const& actual_value):
            base_t::base_t( actual_value ) // Pass the actual_value to the base class 
        ,   equal( actual_value )
        ,   be_less_than( actual_value )
        ,   be_less_than_or_equal_to( actual_value )
        ,   be_more_than( actual_value )
        ,   be_more_than_or_equal_to( actual_value )
        ,   actual_( actual_value )
    {
    }

    template<typename T>
    bool operator==(T const& expected)
    {
        return equal( expected );
    }
    template<typename T>
    bool operator!=(T const& expected)
    {
        return integer::equal_function<Actual, true>( actual_ )( expected );
    }
    template<typename T>
    bool operator<(T const& expected)
    {
        return integer::more_less_function<Actual, Not, USE_LESS, WITHOUT_EQUAL>( actual_ )( expected );
    }
    template<typename T>
    bool operator<=(T const& expected)
    {
        return integer::more_less_function<Actual, Not, USE_LESS, WITH_EQUAL>( actual_ )( expected );
    }
    template<typename T>
    bool operator>(T const& expected)
    {
        return integer::more_less_function<Actual, Not, USE_MORE, WITHOUT_EQUAL>( actual_ )( expected );
    }
    template<typename T>
    bool operator>=(T const& expected)
    {
        return integer::more_less_function<Actual, Not, USE_MORE, WITH_EQUAL>( actual_ )( expected );
    }

    integer::equal_function<Actual, Not>                                equal;

    integer::more_less_function<Actual, Not, USE_LESS, WITHOUT_EQUAL>   be_less_than;    
    integer::more_less_function<Actual, Not, USE_LESS, WITH_EQUAL>      be_less_than_or_equal_to;    
    integer::more_less_function<Actual, Not, USE_MORE, WITHOUT_EQUAL>   be_more_than;    
    integer::more_less_function<Actual, Not, USE_MORE, WITH_EQUAL>      be_more_than_or_equal_to;    

private:
    Actual const& actual_;
};

}} // namespace spec::groups

#undef USE_LESS
#undef USE_MORE
#undef WITH_EQUAL
#undef WITHOUT_EQUAL

#endif /* THEBC_SPECPP_EXPECTATION_GROUPS_INTEGER_INTEGER_HPP */
