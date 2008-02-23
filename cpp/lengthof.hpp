#ifndef CPP_LENGTHOF_HPP
#define CPP_LENGTHOF_HPP

namespace cpp {
    namespace detail {
        template<int N> struct sized_type { typedef char(&type)[N]; };

        template<typename T, int N>
        typename sized_type<N>::type lengthof_impl(T (&x)[N]);
    }

    typedef detail::sized_type<1>::type yes_type;
    typedef detail::sized_type<2>::type no_type;
}
#define lengthof(arg) (sizeof(cpp::detail::lengthof_impl(arg)))

#endif /* CPP_LENGTHOF_HPP */
