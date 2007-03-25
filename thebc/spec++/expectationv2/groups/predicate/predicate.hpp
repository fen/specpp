#ifndef THEBC_SPECPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_HPP
#define THEBC_SPECPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_HPP

#include "predicate_function.hpp"
#include "../../detail/if_not_impl.hpp"

namespace spec { namespace groups {

template<typename Actual, bool Not = false>
struct predicate_t: detail::if_not_impl<predicate_t, Actual, Not> 
{
    predicate_t(Actual const& actual_value):

    base_t::base_t( actual_value ), // Pass the actual_value to the base class 
    be_true( actual_value ),
    be_false( actual_value )

    {
    }

    predicate::predicate_function<Actual, true, Not> be_true;
    predicate::predicate_function<Actual, false, Not> be_false;
};
    
}} // namespace spec::groups


#endif /* THEBC_SPEC++_EXPECTATION_GROUPS_PREDICATE_PREDICATE_HPP */
