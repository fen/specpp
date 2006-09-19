// Spec++ base_context_handler.hpp  ------------------------------------------//
// © Copyright Fredrik Eriksson. 

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef BASE_CONTEXT_HANDLER_HPP
#define BASE_CONTEXT_HANDLER_HPP

/*************************************************************************************************/

namespace spec
{
/*************************************************************************************************/

	struct base_context_handler
	{
		typedef int		identifier_type;

		virtual ~base_context_handler(){}
		virtual bool run(identifier_type const&) = 0;
		virtual std::size_t size() = 0;
	};

/*************************************************************************************************/

}

#endif // BASE_CONTEXT_HANDLER_HPP
