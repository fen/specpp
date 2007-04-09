#ifndef THEBC_SPECPP_EXPECTATION_DETAIL_CHECK_HPP
#define THEBC_SPECPP_EXPECTATION_DETAIL_CHECK_HPP

#include <cstring>
#include <cwchar>

namespace spec { namespace detail {

    template<bool Not>
    bool ret(bool p);
    template<>
    inline bool ret<true>(bool p)
    {
        return !p;
    }
    template<>
    inline bool ret<false>(bool p)
    {
        return p;
    }

    template<bool Not, typename X, typename Y>
    inline bool check(X const& x, Y const& y)
    {
        return ret<Not>( x == y );
    }

    // char pointer check
    template<bool Not>
    inline bool check(char const* const& x, char const* const& y)
    {
        return ret<Not>( ::strcmp( x, y ) == 0 );
    }
    template<bool Not>
    inline bool check(char* const& x, char const* const& y)
    {
        return ret<Not>( ::strcmp( x, y ) == 0 );
    }
    template<bool Not>
    inline bool check(char const* const& x, char* const& y)
    {
        return ret<Not>( ::strcmp( x, y ) == 0 );
    }
    template<bool Not>
    inline bool check(char* const& x, char* const& y)
    {
        return ret<Not>( ::strcmp( x, y ) == 0 );
    }


    // wchar_t pointer check
    template<bool Not>
    bool check(wchar_t const* const& x, wchar_t const* const& y)
    {
        return ret<Not>( ::wcscmp( x, y ) == 0 );
    }
    template<bool Not>
    bool check(wchar_t* const& x, wchar_t const* const& y)
    {
        return ret<Not>( ::wcscmp( x, y ) == 0 );
    }
    template<bool Not>
    bool check(wchar_t const* const& x, wchar_t* const& y)
    {
        return ret<Not>( ::wcscmp( x, y ) == 0 );
    }
    template<bool Not>
    bool check(wchar_t* const& x, wchar_t* const& y)
    {
        return ret<Not>( ::wcscmp( x, y ) == 0 );
    }

}} // namespace spec::detail



#endif /* THEBC_SPECPP_EXPECTATION_DETAIL_CHECK_HPP */
