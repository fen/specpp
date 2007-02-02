#ifndef THEBC__SPECPP_OUTPUT_FORMAT_XML_HPP
#define THEBC__SPECPP_OUTPUT_FORMAT_XML_HPP

#include <thebc/spec++/output_format/base.hpp>

namespace spec { namespace output_format {

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
        out << "\t<context description=\"" << description << "\">\n";
    }
    void context_end(std::ostream& out, std::string const& description)
    {
        out << "\t</context>\n";
    }

    void specifier(std::ostream& out, spec::runner::specify_result& specify)
    {
        out << "\t\t<specify description=\"" << specify.specify_description()
            << "\">\n";
        if( !specify.expectation_met() )
        {
            out << "\t\t\t" << specify.message() << '\n';
        }
        out << "\t\t</specify>\n";
    }
};

}} // namespace spec::output_format


#endif /* THEBC__SPECPP_OUTPUT_FORMAT_XML_HPP */

