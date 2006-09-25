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
        typedef detail::impl::specify_result                specify_result;
        typedef runnable_contexts<context_registration>     runnable_type;

        runner(int argc, char** argv);

        result& run();

    private:
        result result_m;
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

        result_m.clear();


        for( runnable_type::iterator end = runnable.end();
             iter != end;
             ++iter)
        {
            std::string context = runnable.context_description(iter);
            result_m[context] = std::vector<specify_result>();

            for(runnable_type::size_type i = 1;
                i < runnable.number_of_specifyers(iter); ++i)
            {
                try
                {
                    if(runnable.run(iter, i))
                    {
                        result_m[context].push_back( specify_result(runnable.specify_description(iter, i)
                                                        ,true
                                                        ,""
                                                        ,runnable.specify_file(iter, i)
                                                        ,runnable.specify_line(iter, i)) );
                    }
                }
                catch( std::exception const& ex )
                {
                    result_m[context].push_back( specify_result(runnable.specify_description(iter, i)
                                                    ,false
                                                    ,ex.what()
                                                    ,runnable.specify_file(iter, i)
                                                    ,runnable.specify_line(iter, i)) );
                }
                catch(...)
                {
                    // the rest of the exceptions
                }
            }

        }

        return result_m;
    }

/*************************************************************************************************/

} // namespace spec

/*************************************************************************************************/

#endif // RUNNER_HPP
