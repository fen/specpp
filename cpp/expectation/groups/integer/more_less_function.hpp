#ifndef CPP_EXPECTATION_GROUPS_INTEGER_MORE_LESS_FUNCTION_HPP
#define CPP_EXPECTATION_GROUPS_INTEGER_MORE_LESS_FUNCTION_HPP

#include <cpp/spec++/report_error.hpp>
#include "../../detail/check.hpp"
#include "../../detail/message_chooser.hpp"

#define USE_LESS        0
#define USE_MORE        1
#define WITH_EQUAL      true
#define WITHOUT_EQUAL   false

namespace cpp { namespace expectation { namespace groups { namespace integer {

namespace detail {

    namespace impl {
        template<bool Not, int Type, bool Equal>
        struct check;

        template<bool Not>
        struct check<Not, USE_LESS, WITHOUT_EQUAL>
        {
            template<typename Actual, typename Expected>
            bool operator()(Actual const& actual_value, Expected const& expected_value)
            {
                return cpp::spec::detail::check<Not>( actual_value < expected_value );
            }
        };
        template<bool Not>
        struct check<Not, USE_LESS, WITH_EQUAL>
        {
            template<typename Actual, typename Expected>
            bool operator()(Actual const& actual_value, Expected const& expected_value)
            {
                return spec::detail::check<Not>( actual_value <= expected_value );
            }
        };

        template<bool Not>
        struct check<Not, USE_MORE, WITHOUT_EQUAL>
        {
            template<typename Actual, typename Expected>
            bool operator()(Actual const& actual_value, Expected const& expected_value)
            {
                return spec::detail::check<Not>( actual_value > expected_value );
            }
        };
        template<bool Not>
        struct check<Not, USE_MORE, WITH_EQUAL>
        {
            template<typename Actual, typename Expected>
            bool operator()(Actual const& actual_value, Expected const& expected_value)
            {
                return spec::detail::check<Not>( actual_value >= expected_value );
            }
        };
    }

    template<bool Not, int Type, bool Equal, typename Actual, typename Expected>
    bool check(Actual const& a, Expected const& e)
    {
        return impl::check<Not, Type, Equal>()( a, e );
    }

}

template<typename Actual, bool Not, int Type, bool Equal>
struct more_less_function
{
    more_less_function(Actual const& actual_value):
        actual( actual_value )
    {
    }

    template<typename T>
    bool operator()(T const& expected)
    {
        if( integer::detail::check<Not, Type, Equal>( actual, expected ) )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Actual const& actual;
};

}}}}

#endif /* CPP_EXPECTATION_GROUPS_INTEGER_MORE_LESS_FUNCTION_HPP */
