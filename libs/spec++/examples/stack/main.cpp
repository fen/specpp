#include <thebc/spec++.hpp>
#include <thebc/spec++/format/compiler_format.hpp>
#include "stack_spec.hpp"

int main(int argc, char* argv[])
{
    spec::runner r(argc, argv);
    spec::runner::result res = r.run();

    spec::output<compiler_format> out(res);

    out.display();

    spec::context_registration::destroy();
}

