#ifndef THEBC_SPECPP_FORMAT_XML_FORMAT_HPP
#define THEBC_SPECPP_FORMAT_XML_FORMAT_HPP

class xml_format
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

#endif /* THEBC_SPECPP_FORMAT_XML_FORMAT_HPP */
