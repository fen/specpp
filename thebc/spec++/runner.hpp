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
    /*!
        \brief Runns the spec that is specified with the options class.
    */
    class runner
    {
    public:
        typedef detail::impl::result                        result;
        typedef detail::impl::specify_result                specify_result;
        typedef detail::impl::context_result                context_result;
        typedef std::vector<specify_result>                 specify_container;

        typedef runnable_contexts<context_handler>          runnable_type;

        runner(options& opt);

        result& run();

    private:
        bool run_spec(std::string const& name);

        result result_m;
        options& options_m;
    };

/*************************************************************************************************/

    runner::runner(options& opt)
    : options_m(opt)
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
            if(run_spec(c->name))
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
        }

        return result_m;
    }

/*************************************************************************************************/

    bool runner::run_spec(std::string const& name)
    {
        if(options_m.specs().size() == 0)
        {
            return true;
        }

        foreach(std::string& spec_name, options_m.specs())
        {
            if(spec_name == name)
            {
                return true;
            }
        }

        return false;
    }

/*************************************************************************************************/

} // namespace spec

/*************************************************************************************************/

#endif // RUNNER_HPP
