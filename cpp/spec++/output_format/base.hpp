// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

#ifndef CPP_SPECPP_OUTPUT_FORMAT_BASE_HPP
#define CPP_SPECPP_OUTPUT_FORMAT_BASE_HPP

// ----------------------------------------------------------------------------

namespace cpp { namespace spec { namespace output_format {

// ----------------------------------------------------------------------------

class base
{
public:
    virtual ~base() {}

    virtual void start(std::ostream&) = 0;
    virtual void finish(std::ostream&) = 0;
    
    virtual void context_begin(std::ostream&, std::string const&) = 0;
    virtual void context_end(std::ostream&, std::string const&) = 0;

    virtual void specifier(std::ostream&, cpp::spec::runner::specify_result&) = 0;
};

// ----------------------------------------------------------------------------
}}}
// ----------------------------------------------------------------------------
#endif /* CPP_SPECPP_OUTPUT_FORMAT_BASE_HPP */
