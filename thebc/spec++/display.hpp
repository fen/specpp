#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <thebc/spec++/output_format/compiler.hpp>
#include <thebc/spec++/output_format/xml.hpp>

#include <stdexcept>
#include <fstream>

namespace spec
{
    void display(options& opt, spec::runner::result const& res)
    {
        // stdout is default so this is valid
        std::ostream output( std::cout.rdbuf() );
        bool file_output = false;
        std::ofstream file_stream;

        std::string const& format = opt.format();
        std::string const& output_method = opt.output_method();

        boost::shared_ptr<output_format::base> outformat;
        std::string file_extention;

        if( output_method == "stderr" )
            output.rdbuf( std::cerr.rdbuf() );
        else if( output_method == "file" )
            file_output = true;

        // REVISIT (fred) : I have to fix the file output stuff using the same
        // code is ugly :/
        if( format == "compiler" )
        {
            outformat.reset( new output_format::compiler() );
            file_extention = ".txt";
        }
        else if( format == "xml" )
        {
            outformat.reset( new output_format::xml() );
            file_extention = ".xml";
        }
        else
        {
            throw std::runtime_error( "format not supported" );
        }

        if( file_output )
        {
            std::string filename = opt.filename()+file_extention;
            file_stream.open(filename.c_str(), std::ios_base::out|std::ios_base::trunc);
            // If the file isn't open we should use the stdout as
            // fallback.
            if( file_stream.is_open() )
                output.rdbuf( file_stream.rdbuf() );
        }

        spec::output out( outformat, res, output );
        out.display();

    }
}

#endif // DISPLAY_HPP
