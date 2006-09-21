// Spec++ tools.hpp  ---------------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef TOOLS_HPP
#define TOOLS_HPP

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
                    if(actual_m == expected)
                    {
                        return true;
                    }
                    throw 1;
                }

                template<typename T1>
                bool not_equal(T1 const& expected) const
                {
                    if(actual_m != expected)
                    {
                        return true;
                    }

                    throw 1;
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
                bool be_less_than(T1 const& upper_bound) const
                {
                    if(actual_m < upper_bound)
                    {
                        return true;
                    }
                    throw 1;
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
                within<T1> be_within(T1 const& range) const
                {
                    return within<T1>(actual_m, range);
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
                explicit within(T& actual, T const& range)
                : actual_m(actual), range_m(range){}

                template<typename T1>
                bool of(T1 const& expected)
                {
                    if((actual_m - range_m) >= expected
                       || (actual_m + range_m) <= expected)
                    {
                        return true;
                    }

                    throw 1;
                }

                T& actual_m;
                T range_m;
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
        // throw some thing...
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

#endif // TOOLS_HPP
