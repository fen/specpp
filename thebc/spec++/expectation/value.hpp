#ifndef THEBC_SPECPP_EXPECTATION_VALUE_HPP
#define THEBC_SPECPP_EXPECTATION_VALUE_HPP

#include <thebc/spec++/detail/to_string.hpp>

namespace spec {
    
template<typename T>
struct value_spec_t;

namespace detail { namespace value {

    template<typename T, typename T2>
    struct between;

    template<typename T, typename T2>
    struct between_equal;

    template<typename T>
    struct within;

    template<typename T>
    struct not_within;

    template<typename T>
    struct should
    {
        explicit should(T& actual)
        : actual_m(actual){}

// ---------------------------------------------------------------------------
// ipp/value/equal.ipp
        template<typename T1>
        bool equal(T1 const& expected);

        template<typename T1>
        bool not_equal(T1 const& expected);

        template<typename T1>
        bool operator==(T1 const& expected);

        template<typename T1>
        bool operator!=(T1 const& expected);
// ---------------------------------------------------------------------------
// ipp/value/less_more.ipp
        template<typename T1>
        bool be_more_than(T1 const& lower_bound);

        template<typename T1>
        bool operator>(T1 const& lower_bound);

        template<typename T1>
        bool be_less_than(T1 const& upper_bound);

        template<typename T1>
        bool operator<(T1 const& upper_bound);

        template<typename T1>
        bool be_more_than_or_equal_to(T1 const& lower_bound);

        template<typename T1>
        bool operator>=(T1 const& lower_bound);

        template<typename T1>
        bool be_less_than_or_equal_to(T1 const& upper_bound);

        template<typename T1>
        bool operator<=(T1 const& upper_bound);
// ---------------------------------------------------------------------------
// ipp/value/between.ipp
        template<typename T1>
        between<T, T1> be_between(T1 const& lower_bound);

        template<typename T1>
        between<T, T1> not_be_between(T1 const& lower_bound); 

        template<typename T1>
        between_equal<T,T1> be_between_or_equal_to(T1 const& lower_bound); 

        template<typename T1>
        between_equal<T,T1> not_be_between_or_equal_to(T1 const& lower_bound);
// ---------------------------------------------------------------------------
// ipp/value/within.ipp
        template<typename T1>
        within<T> be_within(T1 const& tolerance);

        template<typename T1>
        not_within<T> not_be_within(T1 const& tolerance);
// ---------------------------------------------------------------------------
// ipp/value/be.ipp
        template<typename T1>
        bool be(T1 const& expected);

        template<typename T1>
        bool not_be(T1 const& expected);
// ---------------------------------------------------------------------------
// ipp/value/match.hpp
        template<typename T1>
        bool match(T1 const& pattern);

        template<typename T1>
        bool not_match(T1 const& pattern);
// ---------------------------------------------------------------------------


        T& actual_m;
    };
}} // namespace detail::value

template<typename T>
value_spec_t<T> value(T const& actual)
{
    return value_spec_t<T>(actual);
}

template<typename T>
struct value_spec_t
{
    value_spec_t(T const& actual)
    : actual_(actual), should(actual_){}

    T actual_;
    detail::value::should<T> should;
};

} // namespace spec

// include the implementation 
#include <thebc/spec++/expectation/ipp/value/equal.ipp>
#include <thebc/spec++/expectation/ipp/value/less_more.ipp>
#include <thebc/spec++/expectation/ipp/value/between.ipp>
#include <thebc/spec++/expectation/ipp/value/within.ipp>
#include <thebc/spec++/expectation/ipp/value/be.ipp>
#include <thebc/spec++/expectation/ipp/value/match.ipp>

#endif /* THEBC_SPECPP_EXPECTATION_VALUE_HPP */
