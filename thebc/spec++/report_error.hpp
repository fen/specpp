#ifndef THEBC_SPECPP_REPORT_ERROR_HPP
#define THEBC_SPECPP_REPORT_ERROR_HPP

#include <thebc/spec++/exceptions.hpp>

namespace spec {

bool
report_error(std::string const& error_message)
{
    throw expectation_notmet( error_message );
    return false;
}

} // namespace spec


#endif /* THEBC_SPECPP_REPORT_ERROR_HPP */
