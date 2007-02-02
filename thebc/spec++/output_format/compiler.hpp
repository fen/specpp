#ifndef THEBC__SPECPP_OUTPUT_FORMAT_COMPILER_HPP
#define THEBC__SPECPP_OUTPUT_FORMAT_COMPILER_HPP

#include <thebc/spec++/output_format/base.hpp>

namespace spec { namespace output_format {

class compiler : public base
{
public:
    void start(std::ostream& out)
    {
    }

    void context_begin(std::ostream& out, std::string const& name)
    {
        out << name << '\n';
    }

    void specifier(std::ostream& out, spec::runner::specify_result& specify)
    {
        out << '\t' << specify.specify_description() << '\n';
        if( !specify.expectation_met() )
        {
            // <path>:<line> error: <message>\n
            out << specify.filepath() << ':'
                << specify.line() << " error: "
                << specify.message() << '\n';
        }
    }

    void context_end( std::ostream& out, std::string const& text )
    {
        // This implementation 
    }

    void finish(std::ostream& out)
    {
        out.flush();
    }
};

}} // namespace spec::output_format


#endif /* THEBC__SPECPP_OUTPUT_FORMAT_COMPILER_HPP */
