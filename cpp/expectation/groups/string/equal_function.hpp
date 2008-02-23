#ifndef CPP_EXPECTATION_GROUPS_STRING_EQUAL_FUNCTION_HPP
#define CPP_EXPECTATION_GROUPS_STRING_EQUAL_FUNCTION_HPP

#include <cstring>
#include "../../detail/check.hpp"
#include "../../detail/message_chooser.hpp"
#include <cpp/spec++/report_error.hpp>

namespace cpp { namespace expectation { namespace groups { namespace string {
    
template<typename Actual, bool Not>
struct equal_function
{
    equal_function(Actual const& actual_value)
    : actual( actual_value )
    {
    }

    ///
    /// \return boolean value true if the actual value was equal to the
    ///         expected. False only if the report_error function is
    ///         configured to return a value and not throw an exception.
    ///
    template<typename T>
    bool operator()(T const& expected)
    {
        if( detail::check<Not>( actual, expected ) )
        {
            return true;
        }
        else
        {
            return report_error
                   (
                        detail::message_chooser<Not>
                        (
                                "Actual string (\"${A}\") should have been equal to (\"${E}\") but was not"
                            ,   "Actual string (\"${A}\") should no have been equal to (\"${E}\") be was"
                            , actual
                            , expected
                        )
                   );
        }
    }


    Actual const& actual;
};

}}}}

#endif /* CPP_EXPECTATION_GROUPS_STRING_EQUAL_FUNCTION_HPP */
