// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------

#ifndef DETAIL_SINGLETON_HPP
#define DETAIL_SINGLETON_HPP

// ---------------------------------------------------------------------------
namespace spec { namespace detail {

// ---------------------------------------------------------------------------
template <typename T>
class singleton
{
public:
    typedef T       instance_type;

    static T* instance() 
    {
        if(m_instance == 0)
        {
            m_instance = new T();
        }
        return m_instance;
    }

    class pointer
    {
    public:
        pointer() : m_ptr(singleton::instance()) {}
        T* operator*()
        {
            if(m_instance == 0)
            {
                m_ptr = singleton::instance();
            }
            return *m_ptr;
        }
        T* operator->()
        {
            if(m_instance == 0)
            {
                m_ptr = singleton::instance();
            }
            return m_ptr;
        }
    private:
        pointer(pointer const&);
        pointer& operator=(const pointer&);
    private:
        T* m_ptr;
    };

    static void destroy()
    {
        delete m_instance;
        m_instance = 0;
    }
private:
    singleton();
    ~singleton();
    singleton(const singleton&);
    singleton& operator=(const singleton&);

    static T* m_instance;
};
// ---------------------------------------------------------------------------
template<typename T>
T* singleton<T>::m_instance=0;
// ---------------------------------------------------------------------------
}} // namespace spec::detail

#endif // DETAIL_SINGLETON_HPP
