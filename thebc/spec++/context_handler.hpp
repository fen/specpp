// Spec++ context_handler.hpp  -----------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef CONTEXT_HANDLER_HPP
#define CONTEXT_HANDLER_HPP

#ifndef MAXSPECIFYERS
# define MAXSPECIFYERS 100
#endif

/*************************************************************************************************/

namespace spec
{

/*************************************************************************************************/

    template<typename ContextT, int MaxSpecifyers = MAXSPECIFYERS>
    class context_handler : public base_context_handler
    {
    public:
        typedef ContextT                                        context;

        /* REVISIT (fred) : boost::function should be used this is not readable */
        typedef void (context::*specifyer_pointer)();           //specifyer_pointer

        typedef std::map<identifier_type, specifyer_pointer>    value_type;

        context_handler(std::string const& text);
        ~context_handler();

        std::size_t size();

        bool run(identifier_type const& identifier);
        std::string& specifyer_text(identifier_type const& identifier)
        {
            return context_m.specify_text[identifier];
        }

    private:
        void register_specifyer(identifier_type const& identifier,
                                specifyer_pointer ptr);
        void register_specifyer_information(identifier_type const& identifier,
                                            specifyer_pointer ptr);

        template<int N, typename T=void>
        class recursive
        {
        public:
            static void recurv(context_handler& con)
            {
                con.register_specifyer(N, &context::template specify_func<N>);
                con.register_specifyer_information(N, &context::template register_info<N>);
                recursive<N-1>::recurv(con);
            }
        };

        template<typename T>
        class recursive<0, T>
        {
        public:
            static void recurv(context_handler& con){}
        };

        value_type reged_context_storage_m;
        value_type reged_info_storage_m;
        context context_m;
    };

/*************************************************************************************************/

    /*!
        Default constructor that registrate a test suite with a unique \c name.
        \param name name of the test suite this name is used to identifie this test suite and
                    there fore has to be unique.
    */
    template<typename ContextT, int MaxSpecifyers>
    context_handler<ContextT, MaxSpecifyers>::context_handler(std::string const& text)
    {
        context_registration::pointer ptr;
        ptr->register_context(text, this);
        // do a regursive register of all the test cases for this test suite
        recursive<MaxSpecifyers>::recurv(*this);

    }

/*************************************************************************************************/

    template<typename ContextT, int MaxSpecifyers>
    context_handler<ContextT, MaxSpecifyers>::~context_handler()
    {
    }

/*************************************************************************************************/

    template<typename ContextT, int MaxSpecifyers>
    std::size_t context_handler<ContextT, MaxSpecifyers>::size()
    {
        return reged_context_storage_m.size();
    }

/*************************************************************************************************/

    /*!
        Allows the client to run the test case with the unique \c identifier.

        \param identifier tells the runner with test case to run.
        \return true upon normal run and false if no test was executed.
    */
    template<typename ContextT, int MaxSpecifyers>
    bool context_handler<ContextT, MaxSpecifyers>::run(identifier_type const& identifier)
    {
        typename value_type::iterator iter = reged_context_storage_m.find(identifier);
        bool return_value = false;

        if(iter != reged_context_storage_m.end())
        {
            (context_m.*((*reged_info_storage_m.find(identifier)).second))();
            try
            {
                (context_m.*((*iter).second))();
            }
            catch(...)
            {
                context_m.dummy_m = false;
                throw;
            }
            // execute the test case


            if(!context_m.dummy_m)
            {
                return_value = true;
            }

            context_m.dummy_m = false;
        }

        return return_value;
    }

/*************************************************************************************************/

    /*!
        Registrate a test case with a unique \c identifier and a pointer to the test case method.

        \param identifier some type of unique identifier that will specify this test case.
        \param testcase_ptr pointer to the test case method.
    */
    template<typename ContextT, int MaxSpecifyers>
    void context_handler<ContextT, MaxSpecifyers>::register_specifyer(identifier_type const& identifier,
                                                    specifyer_pointer ptr)
    {
       reged_context_storage_m[identifier] = ptr;
    }

/*************************************************************************************************/
    template<typename ContextT, int MaxSpecifyers>
    void context_handler<ContextT, MaxSpecifyers>::register_specifyer_information(identifier_type const& identifier,
                                        specifyer_pointer ptr)
    {
        reged_info_storage_m[identifier] = ptr;
    }


} // namespace spec


#endif // CONTEXT_HANDLER_HPP
