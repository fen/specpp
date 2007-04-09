#ifndef THEBC_SPECPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_FUNCTION_HPP
#define THEBC_SPECPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_FUNCTION_HPP

#include <thebc/spec++/report_error.hpp>
#include "../../detail/check.hpp"
#include "../../detail/message_chooser.hpp"

namespace spec { namespace groups { namespace predicate {

template<typename Actual, bool Predicate, bool Not>
struct predicate_function
{
    predicate_function(Actual const& actual_value):
    actual( actual_value )
    {
    }
    
    bool operator()()
    {
        if( detail::check<Not>( actual, Predicate ) )
        {
            return true;
        }
        else
        {
            return report_error( 
                                 detail::message_chooser<Not>(
                                        "Actual predicate value (${A}) should have been ${E}"
                                    ,   "Actual predicate value (${A}) should not have been ${E} but was"
                                    , actual
                                    , Predicate
                                 )
                               );
        }
    }

    Actual const& actual;
};
    
}}} // namespace spec::groups::predicate


#endif /* THEBC_SPECPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_FUNCTION_HPP */
