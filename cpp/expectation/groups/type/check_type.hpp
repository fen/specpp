#ifndef CPP_EXPECTATION_GROUPS_TYPE_CHECK_TYPE_HPP
#define CPP_EXPECTATION_GROUPS_TYPE_CHECK_TYPE_HPP

#include <cpp/lengthof.hpp>

namespace cpp { namespace expectation { namespace groups { namespace type {

namespace detail {
    template<typename T>
    cpp::yes_type
    is_same(T*, T*);

    cpp::no_type
    is_same(...);

    template<bool p1, bool p2>
    struct is_same_and
    {
        enum{ value = (p1 && p2) };
    };
}
template<typename Want, typename Has>
struct check_type
{
    static Want x;
    static Has y;
    enum{ 
            value = detail::is_same_and<
                                        (sizeof(cpp::yes_type) == sizeof(detail::is_same(&x, &y)))
                                    ,   (sizeof(Want) == sizeof(Has))
                                    >::value
        };
};

}}}}

#endif /* CPP_EXPECTATION_GROUPS_TYPE_CHECK_TYPE_HPP */
