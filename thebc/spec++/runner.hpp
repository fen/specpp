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
        typedef detail::impl::result                        result;
        typedef runnable_contexts<context_registration>     runnable_type;

        runner(int argc, char** argv);

        result& run();

    private:
    };

/*************************************************************************************************/

    runner::runner(int argc, char** argv)
    {
    }

/*************************************************************************************************/



    runner::result& runner::run()
    {
        // Get all contexts that are runnable
        runnable_type runnable;
        runnable_type::iterator iter = runnable.begin();
        for( runnable_type::iterator end = runnable.end();
             iter != end; ++iter)
        {
            for(runnable_type::size_type i = 1;
                i < runnable.number_of_specifyers(iter); ++i)
            {
                try
                {
                    if(runnable.run(iter, i))
                    {
                        // log the result as AS_SPECIFYED
                        std::cout << "log" << i << std::endl;
                    }
                }
                catch(...)
                {
                    std::cout << "Handling exception" << std::endl;
                }
            }
        }
        std::cout << "end" << std::endl;
    }

/*************************************************************************************************/

} // namespace spec

/*************************************************************************************************/

#endif // RUNNER_HPP
