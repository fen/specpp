// Spec++ context.hpp  -------------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/
#ifndef CONTEXT_HPP
#define CONTEXT_HPP

/*************************************************************************************************/

/* REVISIT (fred) : register_info should not be here should move it out to contex_handler*/

/*!
    \brief The context in which you will run yout executable example.

    You create a context with a name and a constructor. The name is a
    unique identifier to your context. The constructor is the object that does
    the setup/teardown of your context. Every specifyer you create will have
    direct contact to this object that includes public methods and public
    variables.
    <code>
    struct new_account
    {
        new_account()
        {
            // setup
        }
        ...
    };
    context("A new account ", new_account)
    {
        ...
    }
    </code>
*/
#define context( NAME, CONSTRUCTOR ) \
    namespace CONSTRUCTOR##_namespace{\
        template<typename CONSTRUCTOR>\
        struct abstract : CONSTRUCTOR\
        {\
            template<int n>\
            void specify_func()\
            {\
                dummy_m = true;\
            }\
            template<int n>\
            void register_info()\
            {\
            }\
            bool dummy_m;\
            std::map<int, std::string> specify_text;\
            std::map<int, int> specify_line;\
            std::map<int, std::string> specify_file;\
        };\
        typedef spec::context_handler<CONSTRUCTOR##_namespace::abstract<CONSTRUCTOR> > data;\
        data object(NAME);\
    }\
    namespace CONSTRUCTOR##_namespace

/*************************************************************************************************/

#define CONTEXT context

/*************************************************************************************************/

/* REVISIT (fred) : The registration of TEXT __LINE__ __FILE__ has to be done better.*/
/*!
    \brief Specify is the method to hold the example code that expresses an event.

    <code>
    struct new_account
    {
     ...
    };
    context("A new account ", new_account)
    {
        specify("should have a balance of $0", 1)
        {
            ...
        }
    }
    </code>
*/
#define specify( NAME, IDENTIFIER ) \
    template<>\
    template<>\
    void data::context::register_info<IDENTIFIER>()\
    {\
        specify_text[IDENTIFIER] = NAME;\
        specify_line[IDENTIFIER] = __LINE__;\
        specify_file[IDENTIFIER] = __FILE__;\
    }\
    template<>\
    template<>\
    void data::context::specify_func<IDENTIFIER>()\

/*************************************************************************************************/

#define SPECIFY specify

/*************************************************************************************************/

#endif // CONTEXT_HPP
