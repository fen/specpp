// Spec++ exceptions.hpp  ----------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

namespace spec
{
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

    template<typename ActualT, typename ExpectedT>
    class expectation_notmet_impl : public expectation_notmet
    {
    public:
        typedef ActualT     actual_type;
        typedef ExpectedT   expected_type;

        expectation_notmet_impl(actual_type const& actual, expected_type const& expected,
                           std::string const& message)
        : message_m(message)
        {

        }

        ~expectation_notmet_impl() throw(){}

        char const* what() const throw()
        {
            return message_m.c_str();
        }

    private:
        std::string message_m;

    };
} // namespace spec

#endif // EXCEPTIONS_HPP
