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
    template<typename ActualT, typename ExpectedT>
    class expectation_notmet : public std::exception
    {
    public:
        typedef ActualT     actual_type;
        typedef ExpectedT   expected_type;

        expectation_notmet(actual_type const& actual, expected_type const& expected,
                           std::string const& message)
        : actual_m(actual), expected_m(expected), message_m(message){}

        ~expectation_notmet() throw(){}

        char const* what() const throw()
        {
            return message_m.c_str();
        }

        actual_type const& get_actual()
        {
            return actual_m;
        }

        expected_type const& get_expected()
        {
            return expected_m;
        }

    private:
        actual_type actual_m;
        expected_type expected_m;
        std::string message_m;

    };
} // namespace spec

#endif // EXCEPTIONS_HPP
