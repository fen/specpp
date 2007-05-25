#ifndef THEBC_SPECPP_EXPECTATION_DETAIL_IMPLEMENTOR_HPP
#define THEBC_SPECPP_EXPECTATION_DETAIL_IMPLEMENTOR_HPP

namespace spec { namespace detail {
    
template<typename Impl>
struct implementor_t
{
    template<typename T>
    implementor_t(T const& actual_value):
#if defined(SPECPP_USE_MUST)
    must( actual_value )
#else
    should( actual_value )
#endif
    {
    }

#if defined(SPECPP_USE_MUST)
    Impl must;
#else
    Impl should;
#endif
};

}} // namespace spec::detail


#endif /* THEBC_SPECPP_EXPECTATION_DETAIL_IMPLEMENTOR_HPP */
