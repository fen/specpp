#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <iostream>
#include <fstream>
#include <iterator>

namespace spec
{
    namespace po = boost::program_options;
    class options
    {
    public:
        options(int argc, char* argv[]);

        bool run();

    private:
        bool run_m;

    };

    options::options(int argc, char* argv[])
    : run_m(true)
    {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "produce help message")
            ("version,v", "show version number")
            ("spec,s", po::value< std::vector<std::string> >(),
            "specify one or more specs you want to run")
            ;

        po::positional_options_description p;
        p.add("spec", -1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).
          options(desc).positional(p).run(), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << "\n";
            run_m = false;
        }
        else if(vm.count("version"))
        {
            std::cout << "Version: " << SPECPP_VERSION << '\n';
            run_m = false;
        }
        else if(vm.count("spec"))
        {
            foreach(std::string s, vm["spec"].as< std::vector<std::string> >())
            {
                std::cout << s << '\n';
            }
        }

    }

    bool options::run()
    {
        return run_m;
    }
}

#endif // OPTIONS_HPP
