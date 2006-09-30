// Spec++ expectation.hpp  ---------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef EXPECTATION_HPP
#define EXPECTATION_HPP

namespace spec
{
    template<typename T>
    struct spec_t;

    namespace detail
    {
        namespace impl
        {
            template<typename T>
            struct between;

            template<typename T>
            struct between_equal;

            template<typename T>
            struct within;

            template<typename T>
            struct should
            {
                explicit should(T& actual)
                : actual_m(actual){}

                template<typename T1>
                bool equal(T1 const& expected) const
                {
                    if(actual_m != expected)
                    {
                        throw expectation_notmet_impl<T, T1>(actual_m, expected, "actual did not equal expected");
                    }
                    return true;
                }

                template<typename T1>
                bool not_equal(T1 const& expected) const
                {
                    if(actual_m == expected)
                    {
                        throw expectation_notmet_impl<T, T1>(actual_m, expected, "actual did equal expected");
                    }
                    return true;
                }

                template<typename T1>
                bool operator==(T1 const& expected) const
                {
                    return equal<T1>(expected);
                }

                template<typename T1>
                bool operator!=(T1 const& expected) const
                {
                    return not_equal<T1>(expected);
                }


                template<typename T1>
                bool be_more_than(T1 const& lower_bound) const
                {
                    if(actual_m > lower_bound)
                    {
                        return true;
                    }
                    throw 1;
                }

                template<typename T1>
                bool operator>(T1 const& lower_bound) const
                {
                    return be_more_than<T1>(lower_bound);
                }

                template<typename T1>
                bool be_less_than(T1 const& upper_bound) const
                {
                    if(actual_m < upper_bound)
                    {
                        return true;
                    }
                    throw 1;
                }

                template<typename T1>
                bool operator<(T1 const& upper_bound) const
                {
                    return be_less_than<T1>(upper_bound);
                }

                template<typename T1>
                between<T1> be_between(T1 const& lower_bound) const
                {
                    if(actual_m > lower_bound)
                    {
                        return between<T1>(actual_m);
                    }
                    throw 1;
                }

                template<typename T1>
                between_equal<T1> be_between_or_equal_to(T1 const& lower_bound) const
                {
                    if(actual_m >= lower_bound)
                    {
                        return between_equal<T1>(actual_m);
                    }
                    throw 1;
                }

                template<typename T1>
                within<T1> be_within(T1 const& tolerance) const
                {
                    return within<T1>(actual_m, tolerance);
                }

                template<typename T1>
                bool be(T1 const& expected)
                {
                    if(actual_m == expected)
                    {
                        return true;
                    }
                    throw expectation_notmet_impl<T, T1>(actual_m, expected, "actual was not equal to expected");
                }

                template<typename T1>
                bool not_be(T1 const& expected)
                {
                    if(actual_m != expected)
                    {
                        return true;
                    }
                    throw expectation_notmet_impl<T, T1>(actual_m, expected, "actual was equal to expected");
                }



                T& actual_m;
            };

            template<typename T>
            struct between
            {
                explicit between(T& actual)
                :actual_m(actual){}

                template<typename T1>
                bool And(T1 const& upper_bound)
                {
                    if(actual_m < upper_bound)
                    {
                        return true;
                    }

                    throw 1;
                }

                /*!
                NOTE (fred) : The operator && (and) was added to make it
                              possible to have this syntax: actual.should.be_between(lower_bound) and(upper_bound)
                              , or actual.should.be_between(lower_bound) && (upper_bound).
                              The problem is that VC++ 7.1 don't treated and as an keyword so && is only supported.
                */
                template<typename T1>
                bool operator&&(T1 const& upper_bound)
                {
                    if(actual_m < upper_bound)
                    {
                        return true;
                    }

                    throw 1;
                }

                T& actual_m;
            };

            template<typename T>
            struct between_equal
            {
                explicit between_equal(T& actual)
                :actual_m(actual){}

                template<typename T1>
                bool And(T1 const& upper_bound)
                {
                    if(actual_m <= upper_bound)
                    {
                        return true;
                    }

                    throw 1;
                }

                template<typename T1>
                bool operator&&(T1 const& expected)
                {
                    if(actual_m <= expected)
                    {
                        return true;
                    }

                    throw 1;
                }

                T& actual_m;
            };

            template<typename T>
            struct within
            {
                explicit within(T& actual, T const& tolerance)
                : actual_m(actual), tolerance_m(tolerance){}

                template<typename T1>
                bool of(T1 const& expected)
                {
                    if((actual_m - tolerance_m) >= expected
                       || (actual_m + tolerance_m) <= expected)
                    {
                        return true;
                    }

                    throw 1;
                }

                T& actual_m;
                T tolerance_m;
            };

        }
    }

    template<typename T>
    spec_t<T> value(T const& actual)
    {
        return spec_t<T>(actual);
    }

    void violated(std::string const& message)
    {
        throw 1;
    }

    template<typename T>
    struct spec_t
    {
        spec_t(T const& actual)
        : actual_m(actual), should(actual_m), must(actual_m){}

        T actual_m;
        detail::impl::should<T> should;
        detail::impl::should<T> must;
    };
} // namespace spec

#endif // EXPECTATION_HPP
