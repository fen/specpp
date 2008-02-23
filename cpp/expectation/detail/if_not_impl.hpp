#ifndef CPP_EXPECTATION_DETAIL_IF_NOT_IMPL_HPP
#define CPP_EXPECTATION_DETAIL_IF_NOT_IMPL_HPP

namespace cpp { namespace expectation { namespace detail {
    
template<
        class T
    ,   typename Actual
    ,   bool Not
>
struct if_not_impl;

template<
        class T
    ,   typename Actual
>
struct if_not_impl<T,Actual,false>
{
    typedef if_not_impl<T, Actual, false>       base_t;

    if_not_impl(Actual const& actual_value):
    not( actual_value )
    {
    }

    typename T::type not;
};

template<
        class T
    ,   typename Actual
>
struct if_not_impl<T,Actual,true>
{
    typedef if_not_impl<T, Actual, true>       base_t;

    if_not_impl(Actual const& actual_value)
    {
    }
};

}}}

#endif /* CPP_EXPECTATION_DETAIL_IF_NOT_IMPL_HPP */
