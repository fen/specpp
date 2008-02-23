#ifndef THEBC_SPECPP_EXPECTATION_GROUPS_STRING_STRING_HPP
#define THEBC_SPECPP_EXPECTATION_GROUPS_STRING_STRING_HPP

#include "equal_function.hpp"
#include "match_function.hpp"
#include "../../detail/if_not_impl.hpp"
#include "../../detail/boolean_inverter.hpp"
#include "../../detail/group_holder.hpp"

namespace spec { namespace groups {
    
template<typename Actual, bool Not=false>
struct string_t: detail::if_not_impl<detail::group_holder<string_t<Actual, detail::boolean_inverter<Not>::value> >, Actual, Not>
{
	typedef detail::if_not_impl<detail::group_holder<string_t<Actual, detail::boolean_inverter<Not>::value> >, Actual, Not>
		base_type_t;
	
    string_t(Actual const& actual_value):
            base_type_t( actual_value )
        ,   equal( actual_value )
        ,   match( actual_value )
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

    string::equal_function<Actual, Not>     equal;
    string::match_function<Actual, Not>     match;
private:
    Actual const& actual_;
};

}} // namespace spec::groups


#endif /* THEBC_SPECPP_EXPECTATION_GROUPS_STRING_STRING_HPP */
