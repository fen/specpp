#ifndef CPP_EXPECTATION_GROUPS_INTEGER_EQUAL_FUNCTION_HPP
#define CPP_EXPECTATION_GROUPS_INTEGER_EQUAL_FUNCTION_HPP

#include <cpp/spec++/report_error.hpp>
#include "../../detail/check.hpp"
#include "../../detail/message_chooser.hpp"

namespace cpp { namespace expectation { namespace groups { namespace integer {

template<typename Actual, bool Not>
struct equal_function
{
    equal_function(Actual const& actual_value):
        actual( actual_value )
    {
    }

    template<typename T>
    bool operator()(T const& expected)
    {
        if( cpp::expectation::detail::check<Not>( actual, expected ) )
        {
            return true;
        }
        else
        {
            return report_error
                   (
                        cpp::expectation::detail::message_chooser<Not>
                        (
                                "Actual integer ${A} should have been equal to ${E} but wasn't"
                            ,   "Actual integer ${A} should not have been equal to ${E} but was"
                            ,   actual
                            ,   expected
                        )
                   )
                   ;
        }
    }

    Actual const& actual;
};

}}}}

#endif /* CPP_EXPECTATION_GROUPS_INTEGER_EQUAL_FUNCTION_HPP */
