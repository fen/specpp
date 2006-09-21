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
                explicit should(T& value)
                : value_m(value){}

                template<typename T1>
                bool equal(T1 const& value) const
                {
                    if(value_m != value)
                    {
                        throw 1;
                    }
                }

                template<typename T1>
                bool not_equal(T1 const& value) const
                {
                    if(value_m == value)
                    {
                        throw 1;
                    }
                }

                template<typename T1>
                bool be_more_than(T1 const& value) const
                {
                    if(value_m > value)
                    {
                        return true;
                    }
                    throw 1;
                }

                template<typename T1>
                bool be_less_than(T1 const& value) const
                {
                    if(value_m < value)
                    {
                        return true;
                    }
                    throw 1;
                }

                template<typename T1>
                between<T1> be_between(T1 const& value) const
                {
                    if(value_m > value)
                    {
                        return between<T1>(value_m);
                    }
                    throw 1;
                }

                template<typename T1>
                between_equal<T1> be_between_or_equal_to(T1 const& value) const
                {
                    if(value_m >= value)
                    {
                        return between_equal<T1>(value_m);
                    }
                    throw 1;
                }

                template<typename T1>
                within<T1> be_within(T1 const& value) const
                {
                    return within<T1>(value_m, value);
                }



                T& value_m;
            };

            template<typename T>
            struct between
            {
                explicit between(T& value)
                :value_m(value){}

                template<typename T1>
                bool And(T1 const& value)
                {
                    if(value_m < value)
                    {
                        return true;
                    }

                    throw 1;
                }

                template<typename T1>
                bool operator&&(T1 const& value)
                {
                    if(value_m < value)
                    {
                        return true;
                    }

                    throw 1;
                }

                T& value_m;
            };

            template<typename T>
            struct between_equal
            {
                explicit between_equal(T& value)
                :value_m(value){}

                template<typename T1>
                bool And(T1 const& value)
                {
                    if(value_m <= value)
                    {
                        return true;
                    }

                    throw 1;
                }

                template<typename T1>
                bool operator&&(T1 const& value)
                {
                    if(value_m <= value)
                    {
                        return true;
                    }

                    throw 1;
                }

                T& value_m;
            };

            template<typename T>
            struct within
            {
                explicit within(T& value, T const& range)
                : value_m(value), range_m(range){}

                template<typename T1>
                bool of(T1 const& expected)
                {
                    if((value_m - range_m) >= expected
                       || (value_m + range_m) <= expected)
                    {
                        return true;
                    }

                    throw 1;
                }

                T& value_m;
                T range_m;
            };

        }
    }

    template<typename T>
    spec_t<T> value(T const& v)
    {
        return spec_t<T>(v);
    }

    void violated(std::string const& message)
    {
        // throw some thing...
        throw 1;
    }

    template<typename T>
    struct spec_t
    {
        spec_t(T const& value)
        : value_m(value), should(value_m), must(value_m){}

        detail::impl::should<T> should;
        detail::impl::should<T> must;
        T value_m;
    };
} // namespace spec

#endif // TOOLS_HPP
