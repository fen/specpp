#ifndef THEBC_SPECPP_EXPECTATION_GROUPS_TYPE_CHECK_TYPE_HPP
#define THEBC_SPECPP_EXPECTATION_GROUPS_TYPE_CHECK_TYPE_HPP

#include <thebc/lengthof.hpp>

namespace spec { namespace groups { namespace type {

namespace detail {
    template<typename T>
    thebc::yes_type
    is_same(T*, T*);

    thebc::no_type
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
                                        (sizeof(thebc::yes_type) == sizeof(detail::is_same(&x, &y)))
                                    ,   (sizeof(Want) == sizeof(Has))
                                    >::value
        };
};

}}} // namespace spec::groups::type


#endif /* THEBC_SPECPP_EXPECTATION_GROUPS_TYPE_CHECK_TYPE_HPP */
