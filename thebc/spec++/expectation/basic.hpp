#ifndef THEBC_SPECPP_EXPECTATION_BASIC_HPP
#define THEBC_SPECPP_EXPECTATION_BASIC_HPP

namespace spec {

//
// Fail the specification with a message
//
// @param message The message that will be shown for the mean of the failure.
// @warning This function will ALWAYS trow an exception 
// @code
//  fail( "expected result was " );
// @endcode
//
void fail(std::string const& message)
{
    throw expectation_notmet( message );
}

} // namespace spec


#endif /* THEBC_SPECPP_EXPECTATION_BASIC_HPP */
