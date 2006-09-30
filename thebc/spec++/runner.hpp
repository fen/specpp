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
        typedef detail::impl::context_result                context_result;
        typedef std::vector<specify_result>                 specify_container;

        typedef runnable_contexts<context_handler>          runnable_type;

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
        runnable_type run;

        // clear the old results
        result_m.clear();

        foreach(spec::base_context_observer* c, run)
        {
            result_m.push_back(std::make_pair(c->name, specify_container()));
            foreach(spec::base_specify* s, c->specifyers_m)
            {
                std::string message;
                bool expected_result = true;

                try
                {
                    s->specify_method();
                }
                catch(expectation_notmet const& ex)
                {
                    message = ex.what();
                    expected_result = false;
                }
                catch(...)
                {
                    message = "unknown exception thrown.";
                    expected_result = false;
                }

                // create the result
                result_m.back().second.push_back(specify_result(s->name,
                                                       expected_result,
                                                       message,
                                                       s->file,
                                                       s->line));

            }
        }

        return result_m;
    }

/*************************************************************************************************/

} // namespace spec

/*************************************************************************************************/

#endif // RUNNER_HPP
