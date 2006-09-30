// Spec++ spec++.hpp  --------------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef SPECPP_HPP
#define SPECPP_HPP

#define SPECPP_VERSION "0.1.0-M1"

/* REVISIT (fred) : I found that boost has the same macros so I should use those */
#define DO_JOIN2(X,Y) X##Y
#define DO_JOIN(X,Y) DO_JOIN2(X,Y)
#define JOIN(X,Y) DO_JOIN(X,Y)

/*************************************************************************************************/
// Dependences
/* REVISIT (fred) : Use the boost singleton class instead if it is possible. */

#include <vector>
#include <string>
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH
#include <thebc/spec++/detail/singleton.hpp>

/*************************************************************************************************/
// Behinder the scenes

#include <thebc/spec++/base_specify.hpp>
#include <thebc/spec++/base_context_observer.hpp>
#include <thebc/spec++/context_handler.hpp>
#include <thebc/spec++/runnable_contexts.hpp>
#include <thebc/spec++/exceptions.hpp>
#include <thebc/spec++/options.hpp>
/*************************************************************************************************/
// User useful

#include <thebc/spec++/result.hpp>
#include <thebc/spec++/runner.hpp>
#include <thebc/spec++/output.hpp>

#include <thebc/spec++/expectation.hpp>

#include <thebc/spec++/context.hpp>
#include <thebc/spec++/specify.hpp>

#endif // SPECPP_HPP
