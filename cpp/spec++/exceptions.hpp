// � Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// ----------------------------------------------------------------------------
#ifndef CPP_SPECPP_EXCEPTIONS_HPP
#define CPP_SPECPP_EXCEPTIONS_HPP

#include <string>
#include <exception>

// ----------------------------------------------------------------------------
namespace cpp { namespace spec {

// ----------------------------------------------------------------------------
class expectation_notmet : public std::exception
{
public:
    expectation_notmet() {}

    expectation_notmet(std::string const& message)
    : message_( message )
    {}

    virtual ~expectation_notmet() throw() {}

    virtual char const* what() const throw()
    {
        return message_.c_str();
    }
private:
    std::string message_;
};

// ---------------------------------------------------------------------------
}}

#endif /* CPP_SPECPP_EXCEPTIONS_HPP */
