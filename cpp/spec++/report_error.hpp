// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// ----------------------------------------------------------------------------
#ifndef CPP_SPECPP_REPORT_ERROR_HPP
#define CPP_SPECPP_REPORT_ERROR_HPP

#include <cpp/spec++/exceptions.hpp>

namespace cpp { namespace spec {

bool
report_error(std::string const& error_message)
{
    throw expectation_notmet( error_message );
    return false;
}

}}

#endif /* CPP_SPECPP_REPORT_ERROR_HPP */
