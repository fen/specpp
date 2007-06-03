#ifndef THEBC_SPECPP_EXPECTATION_DETAIL_MESSAGE_CHOOSER_HPP
#define THEBC_SPECPP_EXPECTATION_DETAIL_MESSAGE_CHOOSER_HPP

#include <string>

#include <thebc/spec++/detail/to_string.hpp>

namespace spec { namespace detail {

template<bool Not, typename T1, typename T2>
std::string message_chooser(std::string const& str1, std::string const& str2, T1 const& actual, T2 const& expected)
{
    std::string message;

    if( Not )
    {
        message = str2;
    }
    else
    {
        message = str1;
    }

    // Fund the location of the actual value
    std::string::size_type loc = message.find( "${A}", 0 );

    if( loc != std::string::npos )
    {
        message.replace( loc, 4, spec::detail::to_string( actual ) );
    }

    // Find the location of the expected value
    loc = message.find( "${E}", 0 );

    if( loc != std::string::npos )
    {
        message.replace( loc, 4, spec::detail::to_string( expected ) );
    }

    return message;
}


}} // namespace spec::detail



#endif /* THEBC_SPECPP_EXPECTATION_DETAIL_MESSAGE_CHOOSER_HPP */
