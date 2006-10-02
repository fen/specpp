#include <thebc/spec++.hpp>
#include <thebc/spec++/format/compiler_format.hpp>
#include "stack_spec.hpp"

int main(int argc, char* argv[])
{
    // We first get the options for this spec
    spec::options opt(argc, argv);

    if(opt.run())
    {
        spec::runner r(opt);

        spec::runner::result res = r.run();

        spec::output<compiler_format> out(res);

        out.display();
    }
    spec::context_handler::destroy();
}

