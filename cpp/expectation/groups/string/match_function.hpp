#ifndef CPP_EXPECTATION_GROUPS_STRING_MATCH_FUNCTION_HPP
#define CPP_EXPECTATION_GROUPS_STRING_MATCH_FUNCTION_HPP

#include <boost/regex.hpp>

#include "../../detail/check.hpp"
#include "../../detail/message_chooser.hpp"
#include <cpp/spec++/report_error.hpp>

namespace cpp { namespace expectation { namespace groups { namespace string {

template<typename Actual, bool Not>
struct match_function
{
    match_function(Actual const& actual_value):
    actual( actual_value )
    {
    }

    template<typename T>
    bool operator()(T const& pattern)
    {
        boost::regex expression( pattern );

        if( detail::check<Not>( boost::regex_match( actual, expression ) ) )
        {
            return true;
        }
        else
        {
            return report_error
                   (
                        detail::message_chooser<Not>
                        (
                                "Actual ${A} didn't match the pattern ${E}"
                            ,   "Actual ${A} did match the pattern ${E} but shouldn't have"
                            ,   actual
                            ,   pattern
                        )
                   );
        }
    }

    Actual const& actual;
};

}}}}

#endif /* CPP_EXPECTATION_GROUPS_STRING_MATCH_FUNCTION_HPP */
