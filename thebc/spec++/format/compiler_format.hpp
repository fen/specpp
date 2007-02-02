// Spec++ context_handler.hpp  -----------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/
#ifndef COMPILER_FORMAT_HPP
#define COMPILER_FORMAT_HPP

class compiler_format
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

#endif // COMPILER_FORMAT_HPP
