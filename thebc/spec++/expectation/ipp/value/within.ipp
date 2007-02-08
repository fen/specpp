// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

template<typename T>
template<typename T1>
spec::detail::value::within<T> spec::detail::value::should<T>::be_within(T1 const& tolerance)
{
    return within<T>(actual_m, tolerance);
}
// ---------------------------------------------------------------------------
template<typename T>
template<typename T1>
spec::detail::value::not_within<T> spec::detail::value::should<T>::not_be_within(T1 const& tolerance)
{
    return not_within<T>( actual_m, tolerance );
}
// ---------------------------------------------------------------------------
namespace spec { namespace detail { namespace value {
// ---------------------------------------------------------------------------
template<typename T>
struct within
{
    explicit within(T& actual, T const& tolerance)
    : actual_m(actual), tolerance_m(tolerance){}

    template<typename T1>
    bool of(T1 const& expected)
    {
        if( actual_m >= (expected - tolerance_m)
        &&  actual_m <= (expected + tolerance_m) )
        {
            return true;
        }
        std::string message = "actual value \"" + detail::to_string( actual_m )
                            + "\" should have been in the tolerance \"" + detail::to_string( tolerance_m )
                            + "\" of the expected \"" + detail::to_string( expected ) + "\"";

        throw expectation_notmet( message );
    }

    T& actual_m;
    T tolerance_m;
};
// ---------------------------------------------------------------------------
template<typename T>
struct not_within
{
    explicit not_within(T& actual, T const& tolerance)
    : actual_m(actual), tolerance_m(tolerance){}

    template<typename T1>
    bool of(T1 const& expected)
    {
        if( actual_m >= (expected - tolerance_m)
        &&  actual_m <= (expected + tolerance_m) )
        {
            std::string message = "actual value \"" + detail::to_string( actual_m )
                                + "\" should not have been in the tolerance \"" + detail::to_string( tolerance_m )
                                + "\" of the expected \"" + detail::to_string( expected ) + "\"";

            throw expectation_notmet( message );
        }

        return true;
    }

    T& actual_m;
    T tolerance_m;
};
// ---------------------------------------------------------------------------
}}} // namespace spec::detail::value
