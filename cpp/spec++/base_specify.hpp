// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// ---------------------------------------------------------------------------
#ifndef CPP_SPECPP_BASE_SPECIFY_HPP
#define CPP_SPECPP_BASE_SPECIFY_HPP

namespace cpp { namespace spec {

    struct base_specify
    {
        std::string name;
        std::string file;
        int line;

        base_specify(std::string n, std::string f, int l)
        :name(n)
        ,file(f)
        ,line(l) {}

        virtual ~base_specify(){}

        virtual void specify_method() = 0;
    };

}}

#endif // CPP_SPECPP_BASE_SPECIFY_HPP
