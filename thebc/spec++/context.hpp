// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// ---------------------------------------------------------------------------
#ifndef CONTEXT_HPP
#define CONTEXT_HPP

// ---------------------------------------------------------------------------
#if defined( USING_THEBC_CONTEXT_MACRO ) || defined( USING_THEBC_MACRO )
// THEBC_CONTEXT( "...", helper_class )
#else
// context( "...", helper_class )
#endif

#define context( TEXT, DATA )\
namespace JOIN(JOIN(DATA, _namespace_),__LINE__){\
    typedef DATA    data;\
    struct context_observer : spec::base_context_observer\
    {\
        context_observer() : spec::base_context_observer(TEXT)\
        {\
            spec::context_handler::pointer ptr;\
            ptr->register_context(this);\
        }\
        using spec::base_context_observer::register_self;\
    };\
    context_observer observer;\
}\
namespace JOIN(JOIN(DATA, _namespace_),__LINE__)

// ---------------------------------------------------------------------------

#endif // CONTEXT_HPP
