// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

#ifndef THEBC__SPECPP_OUTPUT_FORMAT_XML_HPP
#define THEBC__SPECPP_OUTPUT_FORMAT_XML_HPP

// ----------------------------------------------------------------------------
#include <thebc/spec++/output_format/base.hpp>
#include <algorithm>
#include <string>
#include <functional>

// ----------------------------------------------------------------------------
namespace spec { namespace output_format {

namespace detail {
    struct xml_valid_char: public std::unary_function<char, char>
    {
        char operator() (char c) const
        {
            switch( c )
            {
                case '<':
                case '>':
                    c = ' ';
                break;
            }
            return c;
        }
    };
}
// ----------------------------------------------------------------------------
// TODO (fred) : The description should follow the xml standard so illegal
// characters should be removed. 
class xml : public base
{
public:
    void start(std::ostream& out)
    {
        out << "<?xml version=\"1.0\"?>\n"
            << "<specpp>\n";
    }
    void finish(std::ostream& out)
    {
        out << "</specpp>";
    }

    void context_begin(std::ostream& out, std::string const& description)
    {
        std::string transformed;
        transformed.resize( description.size() );
        std::transform( description.begin(), description.end(),
                        transformed.begin(),
                        detail::xml_valid_char() );

        out << "\t<context description=\"" << transformed << "\">\n";
    }
    void context_end(std::ostream& out, std::string const& description)
    {
        out << "\t</context>\n";
    }

    void specifier(std::ostream& out, spec::runner::specify_result& specify)
    {
        std::string transformed;
        std::string const& description = specify.specify_description();
        transformed.resize( description.size() );
        std::transform( description.begin(), description.end(),
                        transformed.begin(),
                        detail::xml_valid_char() );

        out << "\t\t<specify description=\"" << transformed
            << "\">\n";
        if( !specify.expectation_met() )
        {
            std::string transformed_message;
            std::string const& message = specify.message();
            transformed_message.resize( message.size() );
            std::transform( message.begin(), message.end(),
                            transformed_message.begin(),
                            detail::xml_valid_char() );
            out << "\t\t\t" << transformed_message << '\n';
        }
        out << "\t\t</specify>\n";
    }
};

// ----------------------------------------------------------------------------
}} // namespace spec::output_format

// ----------------------------------------------------------------------------
#endif /* THEBC__SPECPP_OUTPUT_FORMAT_XML_HPP */

