#ifndef CPP_EXPECTATION_DETAIL_IMPLEMENTOR_HPP
#define CPP_EXPECTATION_DETAIL_IMPLEMENTOR_HPP

namespace cpp { namespace expectation { namespace detail {
    
template<typename Impl>
struct implementor_t
{
    template<typename T>
    implementor_t(T const& actual_value):
#if defined(CPP_USE_MUST)
    must( actual_value )
#else
    should( actual_value )
#endif
    {
    }

#if defined(CPP_USE_MUST)
    Impl must;
#else
    Impl should;
#endif
};

}}}

#endif /* CPP_EXPECTATION_DETAIL_IMPLEMENTOR_HPP */
