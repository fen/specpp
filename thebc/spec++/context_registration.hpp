// Spec++ context_registration.hpp  ------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef CONTEXT_REGISTRATION_HPP
#define CONTEXT_REGISTRATION_HPP

#include <thebc/spec++/detail/singleton.hpp>

namespace spec
{
    namespace detail
    {
        namespace registration
        {
            template<typename ContextT
                ,typename IdentifierT>
            class context_impl
            {
            public:
                typedef IdentifierT                                         identifier_type;
                typedef ContextT                                            cotext_type;

                typedef typename std::map<identifier_type, cotext_type*>         value_type;

                context_impl()
                {
                }

                void register_context(identifier_type const& identifier, cotext_type* context)
                {
                    reged_contexts_m[identifier] = context;
                }

                value_type get_registered_contexts() const
                {
                    return reged_contexts_m;
                }

            private:
                value_type reged_contexts_m;
            };
        }
    } // namespace detail
    typedef detail::singleton<detail::registration::context_impl<base_context_handler, std::string> > context_registration;
} // namespace spec

#endif // CONTEXT_REGISTRATION_HPP
