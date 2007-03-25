#ifndef THEBC_LENGTHOF_HPP
#define THEBC_LENGTHOF_HPP

namespace thebc {
    namespace detail {
        template<int N> struct sized_type { typedef char(&type)[N]; };

        template<typename T, int N>
        typename sized_type<N>::type lengthof_impl(T (&x)[N]);
    }

    typedef detail::sized_type<1>::type yes_type;
    typedef detail::sized_type<2>::type no_type;
}
#define lengthof(arg) (sizeof(thebc::detail::lengthof_impl(arg)))

#endif /* THEBC_LENGTHOF_HPP */
