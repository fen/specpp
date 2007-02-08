// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

#ifndef RUNNABLE_CONTEXTS_HPP
#define RUNNABLE_CONTEXTS_HPP

// ---------------------------------------------------------------------------
namespace spec {
// ---------------------------------------------------------------------------
template<typename HandlerT>
class runnable_contexts
{
public:
    typedef typename HandlerT::instance_type::value_type    value_type;
    typedef typename value_type::iterator                   iterator;
    typedef typename value_type::const_iterator             const_iterator;
    typedef typename value_type::reverse_iterator           reverse_iterator;
    typedef typename value_type::const_reverse_iterator     const_reverse_iterator;
    typedef typename value_type::size_type                  size_type;

    runnable_contexts();

    size_type size() const;
    bool empty() const;

    size_type max_size() const;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

private:
    value_type runnable_contexts_m;
};

// ---------------------------------------------------------------------------
template<typename RegistrationT>
runnable_contexts<RegistrationT>::runnable_contexts()
{
    spec::context_handler::pointer ptr;
    runnable_contexts_m = ptr->get_contexts();
}
// ---------------------------------------------------------------------------
template<typename T>
typename runnable_contexts<T>::size_type runnable_contexts<T>::size() const
{
    return runnable_contexts_m.size();
}
// ---------------------------------------------------------------------------
template<typename T>
bool runnable_contexts<T>::empty() const
{
    return runnable_contexts_m.empty();
}
// ---------------------------------------------------------------------------
template<typename T>
typename runnable_contexts<T>::size_type runnable_contexts<T>::max_size() const
{
    return size();
}
// ---------------------------------------------------------------------------
template<typename T>
typename runnable_contexts<T>::iterator runnable_contexts<T>::begin()
{
    return runnable_contexts_m.begin();
}
// ---------------------------------------------------------------------------
template<typename T>
typename runnable_contexts<T>::iterator runnable_contexts<T>::end()
{
    return runnable_contexts_m.end();
}
// ---------------------------------------------------------------------------
template<typename T>
typename runnable_contexts<T>::const_iterator runnable_contexts<T>::begin() const
{
    return runnable_contexts_m.begin();
}
// ---------------------------------------------------------------------------
template<typename T>
typename runnable_contexts<T>::const_iterator runnable_contexts<T>::end() const
{
    return runnable_contexts_m.end();
}

// ---------------------------------------------------------------------------
} // namespace spec
// ---------------------------------------------------------------------------
#endif // RUNNABLE_CONTEXTS_HPP
