#ifndef THEBC_SPECPP_DISPLAY_HPP
#define THEBC_SPECPP_DISPLAY_HPP

// ----------------------------------------------------------------------------

#include <boost/shared_ptr.hpp>

#include <thebc/spec++/output_format/compiler.hpp>
#include <thebc/spec++/output_format/xml.hpp>

#include <stdexcept>
#include <fstream>

// ----------------------------------------------------------------------------

namespace spec {
void display(options& opt, spec::runner::result const& res)
{
    // stdout is default so this is valid
    std::ostream output( std::cout.rdbuf() );
    bool file_output = false;
    std::ofstream file_stream;

    std::string const& format = opt.format();
    std::string const& output_method = opt.output_method();

    boost::shared_ptr<output_format::base> outformat;
    std::string file_extension;

    if( output_method == "stderr" )
        output.rdbuf( std::cerr.rdbuf() );
    else if( output_method == "file" )
        file_output = true;

// Add you output format the same way as bellow DON'T FORGET TO ADD
// FILE EXTENSION 
// ---------------------------------------------------------------------------
    if( format == "compiler" )
    {
        outformat.reset( new output_format::compiler() );
        file_extension = ".txt";
    }
// ---------------------------------------------------------------------------
    else if( format == "xml" )
    {
        outformat.reset( new output_format::xml() );
        file_extension = ".xml";
    }
// ---------------------------------------------------------------------------
    else
    {
        throw std::runtime_error( "output format not supported" );
    }

    if( file_output )
    {
        std::string filename = opt.filename()+file_extension;
        file_stream.open(filename.c_str(), std::ios_base::out|std::ios_base::trunc);
        if( file_stream.is_open() )
            output.rdbuf( file_stream.rdbuf() );
    }

    spec::output out( outformat, res, output );
    out.display();

}

// ----------------------------------------------------------------------------

} // namespace spec

#endif /* THEBC_SPECPP_DISPLAY_HPP */
