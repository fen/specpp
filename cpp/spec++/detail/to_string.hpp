// � Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

#ifndef CPP_SPECPP_DETAIL_TO_STRING_HPP
#define CPP_SPECPP_DETAIL_TO_STRING_HPP

// ---------------------------------------------------------------------------

#include <sstream>
#include <stdexcept>

// ---------------------------------------------------------------------------

namespace cpp { namespace spec { namespace detail {

// ---------------------------------------------------------------------------
namespace impl {
    template<typename T>
    std::string to_string(T const& obj)
    {
        std::ostringstream os;
        os << std::fixed;
        os << obj;

        return os.str();
    }

    // 
    // We have to use basic_ostream because if we use ostringstream we will
    // always get a perfect match.
    //
    template<typename Element, typename Traits, typename T>
    std::basic_ostream<Element, Traits>& operator<<(std::basic_ostream<Element, Traits> const&, T const& obj)
    {
        throw std::runtime_error("error converting to string");
    }
} // namespace impl

// ---------------------------------------------------------------------------
template<typename T>
std::string to_string(T const& obj)
{
    try {
        return impl::to_string<T>(obj);
    }
    catch(...){ return ""; }
}

// ---------------------------------------------------------------------------
std::string to_string(char const* const& str)
{
    return str;
}
std::string to_string(char* const& str)
{
    return str;
}

// ---------------------------------------------------------------------------
std::string to_string(std::string const& str)
{
    return str;
}

// ---------------------------------------------------------------------------
std::string to_string(bool v)
{
    return v?"true":"false";
}

// ---------------------------------------------------------------------------
}}}


// ---------------------------------------------------------------------------
#endif /* CPP_SPECPP_DETAIL_TO_STRING_HPP */
