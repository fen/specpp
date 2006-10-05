// Spec++ context_handler.hpp  -----------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef CONTEXT_HANDLER_HPP
#define CONTEXT_HANDLER_HPP

/*************************************************************************************************/

namespace spec
{

    namespace detail{ namespace impl
    {

/*************************************************************************************************/

            class context_handler
            {
            public:
                typedef std::vector<base_context_observer*>     value_type;

                void register_context(base_context_observer* observer);

                value_type const& get_contexts();

            private:
                value_type registered_observers_m;
            };

/*************************************************************************************************/

            void context_handler::register_context(base_context_observer* observer)
            {
                registered_observers_m.push_back(observer);
            }

/*************************************************************************************************/

            context_handler::value_type const& context_handler::get_contexts()
            {
                return registered_observers_m;
            }

/*************************************************************************************************/

    }} // namespace detail::impl



    typedef detail::singleton<detail::impl::context_handler> context_handler;

} // namespace spec


#endif // CONTEXT_HANDLER_HPP
