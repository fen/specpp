// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// ---------------------------------------------------------------------------
#ifndef OPTIONS_HPP
#define OPTIONS_HPP

// ---------------------------------------------------------------------------

namespace spec
{
// ---------------------------------------------------------------------------

    namespace po = boost::program_options;

    class options
    {
    public:
        options(int argc, char* argv[]);

        bool continue_run();
        std::vector<std::string>& contexts();
        std::vector<std::string>& specifiers();
        std::string const& format() const;
        std::string const& output_method() const;
        std::string const& filename() const;

    private:
        bool continue_m;
        std::vector<std::string> contexts_;
        std::vector<std::string> specifiers_;
        std::string format_;
        std::string output_method_;
        std::string filename_;

    };

// ---------------------------------------------------------------------------

    options::options(int argc, char* argv[])
    : continue_m( true )
    {
        po::options_description general( "General options" );
        general.add_options()
            ("help,h", "Print Help (this message) and exit")
            ("version,v", "Print version information and exit")
            ;

        po::options_description format( "Output format options" );
        format.add_options()
            ("output-method", po::value<std::string>()->default_value("stdout"),
             "Choose one output method (stdout, stderr, or file)")
            ("filename", po::value<std::string>()->default_value("specpp"),
             "If file has been choose as output method arg will be used as filename, file extension is added automatically")
            ("format,f",po::value<std::string>()->default_value("compiler"),
             "Use arg as output")
            ;

        po::options_description spec( "Specification options" );
        spec.add_options()
            ("context,c", po::value< std::vector<std::string> >(),
             "Specify by description the context you want to run.")
            ("specify,s", po::value< std::vector<std::string> >(),
             "Specify by description the specifier you want to run.")
            ;

        po::options_description all( "Allowed options" );
        all.add( general ).add( format ).add( spec );

        po::variables_map vm;
        po::store( po::parse_command_line( argc, argv, all ), vm );
        po::notify( vm );

        if( vm.count( "help" ) )
        {
            std::cout << all << "\n";
            continue_m = false;
        }
        else if( vm.count( "version" ) )
        {
            std::cout << "Spec++ " << SPECPP_VERSION << "\n\n" << SPECPP_COPYRIGHT << "\n\n" << SPECPP_AUTHOR << '\n';
            continue_m = false;
        }

        if( vm.count( "context" ) )
        {
            contexts_ = vm["context"].as< std::vector<std::string> >();
        }

        if( vm.count( "specify" ) )
        {
            specifiers_ = vm["specify"].as< std::vector<std::string> >();
        }
        
        if( vm.count( "format" ) )
        {
            format_ = vm["format"].as< std::string >();
        }

        if( vm.count( "output-method" ) )
        {
            output_method_ = vm["output-method"].as< std::string >();
        }

        if( vm.count( "filename" ) )
        {
            filename_ = vm["filename"].as< std::string >();
        }

    }


// ---------------------------------------------------------------------------
    bool options::continue_run()
    {
        return continue_m;
    }
// ---------------------------------------------------------------------------
    std::vector<std::string>& options::contexts()
    {
        return contexts_;
    }
// ---------------------------------------------------------------------------
    std::vector<std::string>& options::specifiers()
    {
        return specifiers_;
    }
// ---------------------------------------------------------------------------
    std::string const& options::format() const
    {
        return format_;
    }
// ---------------------------------------------------------------------------
    std::string const& options::output_method() const
    {
        return output_method_;
    }
// ---------------------------------------------------------------------------
    std::string const& options::filename() const
    {
        return filename_;
    }
// ---------------------------------------------------------------------------
}

#endif // OPTIONS_HPP
