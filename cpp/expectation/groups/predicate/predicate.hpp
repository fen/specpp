#ifndef CPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_HPP
#define CPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_HPP

#include "predicate_function.hpp"
#include "../../detail/if_not_impl.hpp"
#include "../../detail/boolean_inverter.hpp"
#include "../../detail/group_holder.hpp"

namespace cpp { namespace expectation { namespace groups {

template<typename Actual, bool Not = false>
struct predicate_t: 
	detail::if_not_impl<detail::group_holder<predicate_t<Actual, detail::boolean_inverter<Not>::value> >, Actual, Not> 
{
	typedef detail::if_not_impl<detail::group_holder<predicate_t<Actual, detail::boolean_inverter<Not>::value> >, Actual, Not>	
			base_type_t;
	
    predicate_t(Actual const& actual_value):
            base_type_t( actual_value )  // Pass the actual_value to the base class 
        ,   be_true( actual_value )
        ,   be_false( actual_value )

    {
    }

    predicate::predicate_function<Actual, true, Not> be_true;
    predicate::predicate_function<Actual, false, Not> be_false;
};
    
}}}

#endif /* CPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_HPP */
