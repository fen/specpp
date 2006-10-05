// Spec++ options.hpp  -------------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef OPTIONS_HPP
#define OPTIONS_HPP

/*************************************************************************************************/

namespace spec
{
/*************************************************************************************************/

    namespace po = boost::program_options;

    /*!
        \brief A class that takes client commandline parameters and handles them.
    */
    class options
    {
    public:
        options(int argc, char* argv[]);

        bool continue_run();
        std::vector<std::string>& specs();
        std::string format();

    private:
        bool continue_m;
        std::vector<std::string> specs_m;
        std::string format_m;

    };

/*************************************************************************************************/

    options::options(int argc, char* argv[])
    : continue_m(true)
    {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "produce help message")
            ("version,v", "show version number")
            ("spec,s", po::value< std::vector<std::string> >(),
            "specify one or more specs you want to run")
            ("format,f", po::value< std::vector<std::string> >(),
            "the format of the output")
            ;

        po::positional_options_description p;
        p.add("spec", -1);
        p.add("format", 1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).
          options(desc).positional(p).run(), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << "\n";
            continue_m = false;
        }
        else if(vm.count("version"))
        {
            std::cout << "Version: " << SPECPP_VERSION << '\n';
            continue_m = false;
        }
        else if(vm.count("spec"))
        {
            specs_m = vm["spec"].as< std::vector<std::string> >();
        }
        else if(vm.count("format"))
        {
            format_m = vm["format"].as< std::vector<std::string> >()[0];
        }

    }


/*************************************************************************************************/
    /*!
        \brief Should the program continue to run.

        Command line arguments like [-h, --help] or [-v, --version] is information
        arguments the user does not expect to get any thing more than that information.
        The method returns true if we are going to continue to run after
        the command line options have been takencare of. Or false if the user
        has gotten the information he/she wanted from the options class.

        \return true if we are going to continue to run else false.
    */
    bool options::continue_run()
    {
        return continue_m;
    }

/*************************************************************************************************/
    /* RETURN (fred) : May a list be more appropriate here.*/
    /*!
        \brief Get list of specs to run that has been specified by the user.

        Return a list of context to run supplied by the users with the command line
        paramter [-s, --spec].

        \return A vector filled with 0..N context names to run.
    */
    std::vector<std::string>& options::specs()
    {
        return specs_m;
    }

/*************************************************************************************************/
    /*!
        \brief Get the user supplied option of witch format output the user wants.

        Return the output format option specified by the command line paramter
        [-f, --format]. If the supplied format is non existing or invalid the
        output will fallback to FORMAT_DEFAULT.

        \return A string containing the name of the formating option the user wants.
    */
    std::string options::format()
    {
        return format_m;
    }
}

#endif // OPTIONS_HPP
