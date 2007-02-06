// This stack is for the purpose of showing stack++
// it is totally useless and should not be used for any thing other
// than this :)

#include <cassert>
#include <stdexcept>

#ifndef STACK_HPP
#define STACK_HPP

#define STACK_CAPACITY 128

template<typename ValueT>
class stack
{
public:
    typedef ValueT      value_type;
    stack();

    void push(value_type const& value);
    value_type top();
    value_type pop();
    bool empty();
    bool full();
    std::size_t size();

private:
    value_type      array_m[STACK_CAPACITY];
    int             top_m;
};

template<typename T>
stack<T>::stack()
: top_m(-1) {}

template<typename T>
void stack<T>::push(T const& value)
{
    if( full() )
        throw std::runtime_error( "can't push a full stack" );

    array_m[++top_m] = value;
}


template<typename T>
T stack<T>::top()
{
    if( empty() )
        throw std::runtime_error( "empty stack has no top" );

    return array_m[top_m];
}

template<typename T>
T stack<T>::pop()
{
    if( empty() )
        throw std::runtime_error( "can't pop empty stack" );

    T tmp = top();
    --top_m;
    return tmp;
}

template<typename T>
bool stack<T>::empty()
{
    if( top_m == -1 )
        return true;
    else
        return false;
}

template<typename T>
bool stack<T>::full()
{
    return top_m == STACK_CAPACITY-1 ? true:false;
}

template<typename T>
std::size_t stack<T>::size()
{
    return top_m+1;
}

#endif // STACK_HPP
