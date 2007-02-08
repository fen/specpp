// © Copyright Fredrik Eriksson.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// ---------------------------------------------------------------------------
#ifndef RUNNER_HPP
#define RUNNER_HPP

#include <functional>
#include <algorithm>

// ---------------------------------------------------------------------------

namespace spec {
// ---------------------------------------------------------------------------
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
    bool run_context(std::string const& name);
    bool run_specify(std::string const& name);

    result result_m;
    options& options_m;
};

// ---------------------------------------------------------------------------

runner::runner(options& opt)
: options_m( opt )
{
}

// ---------------------------------------------------------------------------

runner::result& runner::run()
{
    runnable_type run;

    // clear the old results
    result_m.clear();

    foreach( spec::base_context_observer* c, run )
    {
        if( run_context( c->name ) )
        {
            result_m.push_back( std::make_pair( c->name, specify_container() ) );
            foreach( spec::base_specify* s, c->specifyers_m )
            {
                if( !run_specify( s->name ) )
                {
                    continue;
                }
                std::string message;
                bool expected_result = true;

                try
                {
                    s->specify_method();
                }
                catch( expectation_notmet const& ex )
                {
                    message = ex.what();
                    expected_result = false;
                }
                catch( ... )
                {
                    message = "unknown exception thrown.";
                    expected_result = false;
                }

                // create the result
                result_m.back().second.push_back( specify_result( s->name,
                                                        expected_result,
                                                        message,
                                                        s->file,
                                                        s->line ) );

            }
        }
    }

    return result_m;
}

// ---------------------------------------------------------------------------

// TODO (fred) : All this should be done with hash string compare is so
// slow.
bool runner::run_context(std::string const& name)
{
    std::vector<std::string>& context_names = options_m.contexts();

    // If the user didn't give us any context's to specifically run we
    // know that he wants to run every context so we should always return
    // true.
    if( context_names.empty() )
    {
        return true;
    }

    // Find name in the context_names list
    std::vector<std::string>::iterator 
        iter = std::find_if( context_names.begin(), context_names.end(), 
                                std::bind1st( std::equal_to<std::string>(), name ) );


    if( iter != context_names.end() )
        return true;
        
    return false;
}


bool runner::run_specify( std::string const& name )
{
    std::vector<std::string>& specify_names = options_m.specifiers();

    if( specify_names.empty() )
    {
        return true;
    }

    std::vector<std::string>::iterator 
        iter = std::find_if( specify_names.begin(), specify_names.end(), 
                                std::bind1st( std::equal_to<std::string>(), name ) );


        if( iter != specify_names.end() )
        return true;
        
    return false;
}

// ---------------------------------------------------------------------------

} // namespace spec

// ---------------------------------------------------------------------------

#endif // RUNNER_HPP
