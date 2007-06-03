#ifndef THEBC_SPECPP_EXPECTATION_ACTUAL_HPP
#define THEBC_SPECPP_EXPECTATION_ACTUAL_HPP

#include "detail/implementor.hpp"

#include "groups/groups.hpp"

namespace spec 
{

namespace detail 
{
   
// actual_t object {{{1
template<typename Actual>
struct actual_t
{
    template<typename T>
    actual_t(T const& actual_value):

        // Add you group bellow
            predicate( actual_value )
        ,   type( actual_value )
        ,   string( actual_value )
        ,   integer( actual_value )
    {
    }

    // Add your group bellow
    detail::implementor_t<groups::predicate_t<Actual> >     predicate;
    detail::implementor_t<groups::type_t<Actual> >          type;
    detail::implementor_t<groups::string_t<Actual> >        string;
    detail::implementor_t<groups::integer_t<Actual> >       integer;
};

}

// actual {{{1
template<typename T>
detail::actual_t<T> actual(T const& actual_value)
{
    return detail::actual_t<T>( actual_value );
}

} // namespace spec


#endif /* THEBC_SPECPP_EXPECTATION_ACTUAL_HPP */
