// � Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

#ifndef CPP_SPECPP_OUTPUT_FORMAT_COMPILER_HPP
#define CPP_SPECPP_OUTPUT_FORMAT_COMPILER_HPP

// ---------------------------------------------------------------------------
#include <cpp/spec++/output_format/base.hpp>

// ---------------------------------------------------------------------------
namespace cpp {namespace spec { namespace output_format {

// ---------------------------------------------------------------------------
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

    void specifier(std::ostream& out, cpp::spec::runner::specify_result& specify)
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

// ---------------------------------------------------------------------------
}}}
// ---------------------------------------------------------------------------
#endif /* CPP_SPECPP_OUTPUT_FORMAT_COMPILER_HPP */
