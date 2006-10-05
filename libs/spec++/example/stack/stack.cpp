#include <thebc/spec++.hpp>
#include <thebc/spec++/format/compiler_format.hpp>
#include "stack_spec.hpp"

int main(int argc, char* argv[])
{
    // We first get the options for this spec
    spec::options option(argc, argv);

    // Should we continue to run or is this session done
    if(option.continue_run())
    {
        // pass the runner with the options so it knows what the user wants it
        // to do.
        spec::runner r(option);

        // Run all the context and get the result
        spec::runner::result result = r.run();

        // Last pass the options and the result to the display that will
        // display the result as the user wants it.
        spec::display(option, result);
    }

    // destroy the singleton object
    spec::context_handler::destroy();
}

