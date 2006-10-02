#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <thebc/spec++/format/compiler_format.hpp>

namespace spec
{
    void display(options& opt, spec::runner::result const& res)
    {
        std::string format = opt.format();

        if(format == "" || format == "compiler")
        {
            spec::output<compiler_format> out(res);
            out.display();
        }
    }
}

#endif // DISPLAY_HPP
