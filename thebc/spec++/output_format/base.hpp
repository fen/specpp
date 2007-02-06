#ifndef THEBC_SPECPP_OUTPUT_FORMAT_BASE_HPP
#define THEBC_SPECPP_OUTPUT_FORMAT_BASE_HPP

// ----------------------------------------------------------------------------

namespace spec { namespace output_format {

// ----------------------------------------------------------------------------

class base
{
public:
    virtual ~base() {}

    virtual void start(std::ostream&) = 0;
    virtual void finish(std::ostream&) = 0;
    
    virtual void context_begin(std::ostream&, std::string const&) = 0;
    virtual void context_end(std::ostream&, std::string const&) = 0;

    virtual void specifier(std::ostream&, spec::runner::specify_result&) = 0;
};

// ----------------------------------------------------------------------------
}} // namespace spec::output_format

// ----------------------------------------------------------------------------
#endif /* THEBC_SPECPP_OUTPUT_FORMAT_BASE_HPP */
