// Spec++ output.hpp  --------------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

// ----------------------------------------------------------------------------
#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <boost/shared_ptr.hpp>
#include <thebc/spec++/output_format/base.hpp>

// ----------------------------------------------------------------------------

namespace spec
{

// ----------------------------------------------------------------------------

class output
{
    typedef runner::result                                          result;
    typedef runner::specify_result                                  specify_result;
    typedef std::pair<std::string, std::vector<specify_result> >    context_pair;
    typedef boost::shared_ptr<output_format::base>                  format_ptr;

public:

    output(format_ptr& ptr, result const& result, std::ostream& output_stream)
    : result_( result ), output_stream_( output_stream ), format_( ptr )
    {}

    void display();
    void display(runner::result const& result);

private:
    runner::result  result_;
    std::ostream&   output_stream_;
    format_ptr      format_;
};

// ----------------------------------------------------------------------------

void output::display()
{
    format_->start( output_stream_ );
    foreach(context_pair context, result_)
    {
        // first is the context name/description
        format_->context_begin( output_stream_, context.first );

        // second is the vector with N specifyers.
        foreach(specify_result& specify, context.second)
        {
            format_->specifier( output_stream_, specify );
        }
        format_->context_end( output_stream_, "" );
    }
    format_->finish( output_stream_ );
}

// ----------------------------------------------------------------------------

void output::display(runner::result const& result)
{
    result_ = result;
    display();
}

} // namespace spec

// ----------------------------------------------------------------------------



#endif // OUTPUT_HPP

