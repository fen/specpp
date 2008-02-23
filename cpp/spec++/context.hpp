// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// ---------------------------------------------------------------------------
#ifndef CPP_SPECPP_CONTEXT_HPP
#define CPP_SPECPP_CONTEXT_HPP

// ---------------------------------------------------------------------------
#define CPP_CONTEXT( TEXT, DATA )\
namespace JOIN(JOIN(DATA, _namespace_),__LINE__){\
    typedef DATA    data;\
    struct context_observer : cpp::spec::base_context_observer\
    {\
        context_observer() : cpp::spec::base_context_observer(TEXT)\
        {\
            cpp::spec::context_handler::pointer ptr;\
            ptr->register_context(this);\
        }\
        using cpp::spec::base_context_observer::register_self;\
    };\
    context_observer observer;\
}\
namespace JOIN(JOIN(DATA, _namespace_),__LINE__)

// ---------------------------------------------------------------------------

#endif // CPP_SPECPP_CONTEXT_HPP
