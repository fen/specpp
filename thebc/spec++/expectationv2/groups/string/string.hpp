#ifndef THEBC_SPECPP_EXPECTATION_GROUPS_STRING_STRING_HPP
#define THEBC_SPECPP_EXPECTATION_GROUPS_STRING_STRING_HPP

#include "equal_function.hpp"
#include "../../detail/if_not_impl.hpp"

namespace spec { namespace groups {
    
template<typename Actual, bool Not=false>
struct string_t: detail::if_not_impl<string_t, Actual, Not>
{
    string_t(Actual const& actual_value):
            base_t::base_t( actual_value )
        ,   equal( actual_value )
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
        return string::equal_function<Actual, true>( actual_ )( expected );
    }

    // match
    string::equal_function<Actual, Not>     equal;
private:
    Actual const& actual_;
};

}} // namespace spec::groups


#endif /* THEBC_SPECPP_EXPECTATION_GROUPS_STRING_STRING_HPP */
