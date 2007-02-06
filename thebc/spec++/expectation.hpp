// Spec++ expectation.hpp  ---------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef EXPECTATION_HPP
#define EXPECTATION_HPP

#include <boost/regex.hpp>
#include <thebc/spec++/detail/to_string.hpp>

namespace spec
{
    template<typename T>
    struct spec_t;

    namespace detail
    {
        namespace impl
        {
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
                // Equality section

                template<typename T1>
                bool equal(T1 const& expected) const
                {
                    if(actual_m != expected)
                    {
                        std::string message = "actual value \"" + detail::to_string( actual_m ) 
                                            + "\" should have been equal to \"" + detail::to_string( expected )
                                            + "\"";
                        throw expectation_notmet( message );
                    }
                    return true;
                }

                template<typename T1>
                bool not_equal(T1 const& expected) const
                {
                    if(actual_m == expected)
                    {
                        std::string message = "actual value \"" + detail::to_string( actual_m ) 
                                            + "\" shouldn't have been equal to \"" + detail::to_string( expected )
                                            + "\" but was";
                        throw expectation_notmet( message );
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

// ---------------------------------------------------------------------------

                template<typename T1>
                bool be_more_than(T1 const& lower_bound) const
                {
                    if(actual_m > lower_bound)
                    {
                        return true;
                    }
                    std::string message = "actual value \"" + detail::to_string( actual_m )
                                        + "\" should have been bigger than \"" + detail::to_string( lower_bound ) + "\"";

                    throw expectation_notmet( message );
                }

                template<typename T1>
                bool operator>(T1 const& lower_bound) const
                {
                    return be_more_than<T1>( lower_bound );
                }

                template<typename T1>
                bool be_less_than(T1 const& upper_bound) const
                {
                    if(actual_m < upper_bound)
                    {
                        return true;
                    }
                    std::string message = "actual value \"" + detail::to_string( actual_m )
                                        + "\" should have been less than \"" + detail::to_string( upper_bound ) + "\"";

                    throw expectation_notmet( message );
                }

                template<typename T1>
                bool operator<(T1 const& upper_bound) const
                {
                    return be_less_than<T1>( upper_bound );
                }

                template<typename T1>
                bool be_more_than_or_equal_to(T1 const& lower_bound) const
                {
                    if( actual_m >= lower_bound )
                    {
                        return true;
                    }
                    std::string message = "actual value \"" + detail::to_string( actual_m )
                                        + "\" should have been bigger than or equal to \"" 
                                        + detail::to_string( lower_bound ) + "\"";

                    throw expectation_notmet( message );
                }

                template<typename T1>
                bool operator>=(T1 const& lower_bound) const
                {
                    return be_more_than_or_equal_to( lower_bound );
                }

                template<typename T1>
                bool be_less_than_or_equal_to(T1 const& upper_bound) const
                {
                    if( actual_m <= upper_bound )
                    {
                        return true;
                    }

                    std::string message = "actual value \"" + detail::to_string( actual_m )
                                        + "\" should have been less than or equal to \"" + detail::to_string( upper_bound ) + "\"";

                    throw expectation_notmet( message );
                }

                template<typename T1>
                bool operator<=(T1 const& upper_bound) const
                {
                    return be_less_than_or_equal_to( upper_bound );
                }

// ---------------------------------------------------------------------------

                template<typename T1>
                between<T, T1> be_between(T1 const& lower_bound) const
                {
                    bool lower = false;
                    if( actual_m > lower_bound )
                    {
                        lower = true;
                    }
                    return between<T, T1>( actual_m, lower_bound, lower, false );
                }

                template<typename T1>
                between<T, T1> not_be_between(T1 const& lower_bound) const
                {
                    bool lower = false;
                    if( actual_m > lower_bound )
                    {
                        lower = true;
                    }

                    return between<T, T1>( actual_m, lower_bound, lower, true );
                }


                template<typename T1>
                between_equal<T,T1> be_between_or_equal_to(T1 const& lower_bound) const
                {
                    bool lower = false;
                    if( actual_m >= lower_bound )
                    {
                        lower = true;
                    }
                    return between_equal<T, T1>( actual_m, lower_bound, lower, false );
                }

                template<typename T1>
                between_equal<T,T1> not_be_between_or_equal_to(T1 const& lower_bound) const
                {
                    bool lower = false;
                    if( actual_m >= lower_bound )
                    {
                        lower = true;
                    }

                    return between_equal<T, T1>( actual_m, lower_bound, lower, true );
                }

/*************************************************************************************************/

                template<typename T1>
                within<T> be_within(T1 const& tolerance) const
                {
                    return within<T>(actual_m, tolerance);
                }

                template<typename T1>
                not_within<T> not_be_within(T1 const& tolerance) const
                {
                    return not_within<T>( actual_m, tolerance );
                }


// ---------------------------------------------------------------------------
                template<typename T1>
                bool be(T1 const& expected)
                {
                    if(actual_m == expected)
                    {
                        return true;
                    }
                    std::string message = "actual value \"" + detail::to_string( actual_m )
                                        + "\" should have been \"" + detail::to_string( expected ) + "\"";
                    throw expectation_notmet( message );
                }

                template<typename T1>
                bool not_be(T1 const& expected)
                {
                    if(actual_m != expected)
                    {
                        return true;
                    }
                    std::string message = "actual value \"" + detail::to_string( actual_m )
                                        + "\" shouldn't have been \"" + detail::to_string( expected ) + "\" but was";
                    throw expectation_notmet( message );
                }

// ---------------------------------------------------------------------------
                template<typename T1>
                bool match(T1 const& pattern)
                {
                    boost::regex expression( pattern );

                    if( boost::regex_match( actual_m, expression ) )
                    {
                        return true;
                    }
                    std::string message = "actual value \"" + detail::to_string( actual_m )
                                        + "\" didn't match the pattern \"" + detail::to_string( pattern ) + "\"";

                    throw expectation_notmet( message );
                }

                template<typename T1>
                bool not_match(T1 const& pattern)
                {
                    boost::regex expression( pattern );

                    if( boost::regex_match( actual_m, expression ) )
                    {
                    std::string message = "actual value \"" + detail::to_string( actual_m )
                                        + "\" did match the pattern \"" + detail::to_string( pattern ) 
                                        + "\" but shouldn't have";
                        throw expectation_notmet(message);
                    }
                    return true;
                }

// ---------------------------------------------------------------------------


                T& actual_m;
            };

// ---------------------------------------------------------------------------
            template<typename T, typename T2>
            struct between
            {
                explicit between(T& actual, T2 const& lower_bound, bool lower, bool should_not)
                :actual_m( actual ), lower_bound_( lower_bound ), lower_( lower ), should_not_( should_not ){}

                template<typename T1>
                bool And(T1 const& upper_bound)
                {
                    bool upper = false;
                    if( actual_m < upper_bound )
                    {
                        upper = true;
                    }

                    if( should_not_ )
                    {
                        if( !upper || !lower_ )
                        {
                            return true;
                        }
                        std::string message = "actual value \"" + detail::to_string( actual_m )
                                            + "\" should not have been between \""
                                            + detail::to_string( lower_bound_ ) + "\" and \""
                                            + detail::to_string( upper_bound ) + "\"";
                        throw expectation_notmet( message );
                    }
                    else
                    {
                        if( upper && lower_ )
                        {
                            return true;
                        }
                        std::string message = "actual value \"" + detail::to_string( actual_m )
                                            + "\" should have been between \""
                                            + detail::to_string( lower_bound_ ) + "\" and \""
                                            + detail::to_string( upper_bound ) + "\"";
                        throw expectation_notmet( message );
                    }
                }

                template<typename T1>
                bool operator&&(T1 const& upper_bound)
                {
                    return And( upper_bound );
                }

                T& actual_m;
                T2 const& lower_bound_;
                bool lower_;
                bool should_not_;
            };

            template<typename T, typename T2>
            struct between_equal
            {
                explicit between_equal(T& actual, T2 const& lower_bound, bool lower, bool should_not)
                 :actual_m( actual ), lower_bound_( lower_bound ), lower_( lower ), should_not_( should_not ){}

                template<typename T1>
                bool And(T1 const& upper_bound)
                {
                    bool upper = false;
                    if( actual_m <= upper_bound )
                    {
                        upper = true;
                    }

                    if( should_not_ )
                    {
						if( !upper || !lower_ )
                        {
                            return true;
                        }
                        std::string message = "actual value \"" + detail::to_string( actual_m )
                                            + "\" should not have been between or equal to \""
                                            + detail::to_string( lower_bound_ ) + "\" and \""
                                            + detail::to_string( upper_bound ) + "\"";
                        throw expectation_notmet( message );
                    }
                    else
                    {
                        if( upper && lower_ )
                        {
                            return true;
                        }
                        std::string message = "actual value \"" + detail::to_string( actual_m )
                                            + "\" should have been between or equal to \""
                                            + detail::to_string( lower_bound_ ) + "\" and \""
                                            + detail::to_string( upper_bound ) + "\"";
                        throw expectation_notmet( message );
                    }
                }

                template<typename T1>
                bool operator&&(T1 const& upper_bound)
                {
                    return And( upper_bound );
                }

                T& actual_m;
                T2 const& lower_bound_;
                bool lower_;
                bool should_not_;
            };

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

        }
    }

    template<typename T>
    spec_t<T> value(T const& actual)
    {
        return spec_t<T>(actual);
    }

    void violated(std::string const& message)
    {
        throw expectation_notmet(message);
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

#define function\
    bool thrown = false;\
    try {

#define method function

#define should_throw\
    }\
    catch( ... ){ thrown = true; }\
    if( !thrown ){ violated( "Didn't throw an exception but should have" ); }

#define should_not_throw\
    }\
    catch( ... ){ thrown = true; }\
    if( thrown ){ violated( "Did throw an exception but shouldn't" ); } 

#define STRINGIFY( X ) #X

#define should_throw_an( TYPE )\
    }\
    catch( TYPE& ){ thrown = true; }\
    catch( ... ) { }\
    if( !thrown ){ violated( "Didn't throw an exception of type " STRINGIFY( TYPE ) " but should have" ); }

#endif // EXPECTATION_HPP
