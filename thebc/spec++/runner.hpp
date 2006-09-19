// Spec++ runner.hpp  --------------------------------------------------------//
// © Copyright Fredrik Eriksson. 

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef RUNNER_HPP
#define RUNNER_HPP

/*************************************************************************************************/

namespace spec
{
/*************************************************************************************************/
	class runner
	{
	public:
		typedef detail::impl::result						result;

		runner(int argc, char** argv);

		template<typename T>
        result& operator()(int a);
	};

/*************************************************************************************************/

	runner::runner(int argc, char** argv)
	{
	}

/*************************************************************************************************/

	template<typename T>
    runner::result& runner::operator()(int a)
	{
	}

/*************************************************************************************************/

} // namespace spec

/*************************************************************************************************/

#endif // RUNNER_HPP
