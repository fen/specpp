#ifndef THEBC_SPECPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_FUNCTION_HPP
#define THEBC_SPECPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_FUNCTION_HPP

#include <thebc/spec++/detail/to_string.hpp>
#include <thebc/spec++/report_error.hpp>

namespace spec { namespace groups { namespace predicate {

template<typename Actual, bool Predicate, bool Not>
struct predicate_function
{
    predicate_function(Actual const& actual_value):
    actual( actual_value )
    {
    }
    
    bool operator()()
    {
        if( check<Not>() )
        {
            return true;
        }
        else
        {
            return report_error( create_message<Not>() );
        }
    }

    template<bool N>
    bool check();

    // Normal statement
    // e.g. should.be_true()
    template<>
    bool check<false>()
    {
        return actual == Predicate;
    }
    // This is when the not statement is set
    // e.g. should.not.be_true()
    template<>
    bool check<true>()
    {
        return actual != Predicate;
    }

    template<bool N>
    std::string create_message();

    template<>
    std::string create_message<false>()
    {
        return std::string( "Actual predicate value (\"" + detail::to_string( actual ) + 
                            "\") should have been " + detail::to_string( Predicate ) 
                          );
    }
    template<>
    std::string create_message<true>()
    {
        return std::string( "Actual predicate value (\"" + detail::to_string( actual ) + 
                            "\") should not have been " + detail::to_string( Predicate ) +
                            " but was"
                          );
    }

    Actual const& actual;
};
    
}}} // namespace spec::groups::predicate


#endif /* THEBC_SPECPP_EXPECTATION_GROUPS_PREDICATE_PREDICATE_FUNCTION_HPP */
