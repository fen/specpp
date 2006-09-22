// Spec++ runnable_contexts.hpp  ---------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef RUNNABLE_CONTEXTS_HPP
#define RUNNABLE_CONTEXTS_HPP

/*************************************************************************************************/

namespace spec
{
/*************************************************************************************************/

    template<typename RegistrationT>
    class runnable_contexts
    {
    public:
        typedef RegistrationT                                   registration_type;
        typedef typename registration_type::instance_type       instance_type;
        typedef typename instance_type::value_type              value_type;
        typedef typename instance_type::identifier_type         identifier_type;
        typedef typename value_type::iterator                   iterator;
        typedef typename value_type::const_iterator             const_iterator;
        typedef typename value_type::reverse_iterator           reverse_iterator;
        typedef typename value_type::const_reverse_iterator     const_reverse_iterator;
        typedef typename value_type::size_type                  size_type;

        runnable_contexts();

        size_type size() const;

        size_type max_size() const;

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        void run(iterator const& iter);

        bool run(iterator const& iter, int specifyer);

        void run(identifier_type const& identifier);

        bool run(identifier_type const& identifier, int specifyer);

        /* REVISIT (fred) : void run(iterator const& start, iterator const& end) */

        identifier_type const& identifier(iterator const& iter);

        size_type number_of_specifyers(iterator const& iter);

        std::string const& context_description(iterator const& iter);

        std::string const& specify_description(iterator const& iter, int specifyer);

    private:
        value_type runnable_contexts_m;

    };

/*************************************************************************************************/

    template<typename RegistrationT>
    runnable_contexts<RegistrationT>::runnable_contexts()
    {
        typename registration_type::pointer ptr;
        runnable_contexts_m = ptr->get_registered_contexts();
    }

/*************************************************************************************************/

    template<typename T>
    typename runnable_contexts<T>::size_type runnable_contexts<T>::size() const
    {
        return runnable_contexts_m.size();
    }

/*************************************************************************************************/

    template<typename T>
    typename runnable_contexts<T>::size_type runnable_contexts<T>::max_size() const
    {
        return size();
    }

/*************************************************************************************************/

    template<typename T>
    typename runnable_contexts<T>::iterator runnable_contexts<T>::begin()
    {
        return runnable_contexts_m.begin();
    }

/*************************************************************************************************/

    template<typename T>
    typename runnable_contexts<T>::iterator runnable_contexts<T>::end()
    {
        return runnable_contexts_m.end();
    }

/*************************************************************************************************/

    template<typename T>
    typename runnable_contexts<T>::const_iterator runnable_contexts<T>::begin() const
    {
        return runnable_contexts_m.begin();
    }

/*************************************************************************************************/

    template<typename T>
    typename runnable_contexts<T>::const_iterator runnable_contexts<T>::end() const
    {
        return runnable_contexts_m.end();
    }

/*************************************************************************************************/

    template<typename T>
    void runnable_contexts<T>::run(iterator const& iter)
    {
        for(unsigned int i = 1;
             i <= number_of_specifyers(iter);
             ++i)
        {
            run(iter, i);
        }
    }

/*************************************************************************************************/

    template<typename T>
    bool runnable_contexts<T>::run(iterator const& iter, int specifyer)
    {
        return (*iter).second->run(specifyer);
    }

/*************************************************************************************************/

    template<typename T>
    void runnable_contexts<T>::run(identifier_type const& identifier)
    {
        iterator iter = runnable_contexts_m.find(identifier);
        if(iter != end())
        {
           run(iter);
        }
    }

/*************************************************************************************************/

    template<typename T>
    bool runnable_contexts<T>::run(identifier_type const& identifier, int specifyer)
    {
        iterator iter = runnable_contexts_m.find(identifier);
        if(iter != end())
        {
           return run(iter,specifyer);
        }
        return false;
    }

/*************************************************************************************************/

    template<typename T>
    typename runnable_contexts<T>::identifier_type const& runnable_contexts<T>::identifier(iterator const& iter)
    {
        return (*iter).first;
    }

/*************************************************************************************************/

    template<typename T>
    typename runnable_contexts<T>::size_type runnable_contexts<T>::number_of_specifyers(iterator const& iter)
    {
        return (*iter).second->size();
    }

/*************************************************************************************************/
    template<typename T>
    std::string const& runnable_contexts<T>::context_description(iterator const& iter)
    {
        return (*iter).second->context_description();
    }
/*************************************************************************************************/
    template<typename T>
    std::string const& runnable_contexts<T>::specify_description(iterator const& iter, int specifyer)
    {
        return (*iter).second->specify_description(specifyer);
    }

/*************************************************************************************************/


}
/*************************************************************************************************/

#endif // RUNNABLE_CONTEXTS_HPP
