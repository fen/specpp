// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// ---------------------------------------------------------------------------
#ifndef CPP_SPECPP_SPECIFY_HPP
#define CPP_SPECPP_SPECIFY_HPP

#define CPP_SPECIFY( TEXT )\
struct JOIN(specify_, __LINE__) : cpp::spec::base_specify, data \
{\
    JOIN(specify_, __LINE__)() : cpp::spec::base_specify(TEXT, __FILE__, __LINE__), data()\
    {\
        observer.register_self(this);\
    }\
    void specify_method();\
};\
JOIN(specify_, __LINE__) JOIN(specify_obj_, __LINE__);\
void JOIN(specify_, __LINE__)::specify_method()

#endif // CPP_SPECPP_SPECIFY_HPP
