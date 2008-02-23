// Spec++ spec++.hpp  --------------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ----------------------------------------------------------------------------
#ifndef CPP_SPECPP_HPP
#define CPP_SPECPP_HPP

// ----------------------------------------------------------------------------

#define SPECPP_VERSION "0.2.0"
#define SPECPP_COPYRIGHT "Distributed under the Boost Software License, Version 1.0. (See\n"\
                         "accompanying file LICENSE_1_0.txt or copy at\n"\
                         "http://www.boost.org/LICENSE_1_0.txt)\n"
#define SPECPP_AUTHOR   "Fredrik Eriksson <Fredrik.Eriksson@cpp.se>"

// ----------------------------------------------------------------------------

#define DO_JOIN2(X,Y) X##Y
#define DO_JOIN(X,Y) DO_JOIN2(X,Y)
#define JOIN(X,Y) DO_JOIN(X,Y)

// ----------------------------------------------------------------------------

/* REVISIT (fred) : Use the boost singleton class instead if it is possible. */

#include <vector>
#include <string>
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH
#include <cpp/spec++/detail/singleton.hpp>

// ----------------------------------------------------------------------------

#include <cpp/spec++/base_specify.hpp>
#include <cpp/spec++/base_context_observer.hpp>
#include <cpp/spec++/context_handler.hpp>
#include <cpp/spec++/runnable_contexts.hpp>
#include <cpp/spec++/exceptions.hpp>
#include <cpp/spec++/options.hpp>

// ----------------------------------------------------------------------------

#include <cpp/spec++/result.hpp>
#include <cpp/spec++/runner.hpp>
#include <cpp/spec++/output.hpp>
#include <cpp/spec++/display.hpp>

#include <cpp/expectation.hpp>

#include <cpp/spec++/context.hpp>
#include <cpp/spec++/specify.hpp>

// ----------------------------------------------------------------------------

using namespace cpp::expectation;

// ----------------------------------------------------------------------------

// Define the standard main function
#define CPP_SPECPP_MAIN\
    int main(int argc, char* argv[])\
    {\
        try{\
        cpp::spec::options option(argc, argv);\
        if(option.continue_run())\
        {\
            cpp::spec::runner r(option);\
            cpp::spec::runner::result result = r.run();\
            cpp::spec::display(option, result);\
        }\
            cpp::spec::context_handler::destroy();\
        }\
        catch(std::exception& ex)\
        {\
            std::cerr << ex.what() << std::endl;\
        }\
        catch(...)\
        {\
            std::cerr << "unknown error have occurred this should not have happen" << std::endl; \
        }\
    }
    

#endif /* CPP_SPECPP_HPP */
