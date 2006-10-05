// Spec++ result.hpp  --------------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/

#ifndef RESULT_HPP
#define RESULT_HPP

/*************************************************************************************************/

namespace spec
{
/*************************************************************************************************/
    namespace detail
    {
        namespace impl
        {
            /*!
                \brief Unique specifyer result.
            */
            class specify_result
            {
            public:
                /* REVISIT (fred) : specify_desc should be name.*/
                specify_result(std::string const& specify_desc,
                              bool expectation_met,
                              std::string message,
                              std::string filepath,
                              int line)
                : specify_description_m(specify_desc)
                , expectation_met_m(expectation_met)
                , message_m(message)
                , filepath_m(filepath)
                , line_m(line)
                {}

                specify_result(specify_result const& s)
                : specify_description_m(s.specify_description_m)
                , expectation_met_m(s.expectation_met_m)
                , message_m(s.message_m)
                , filepath_m(s.filepath_m)
                , line_m(s.line_m)
                {}

                bool expectation_met()
                {
                    return expectation_met_m;
                }

                std::string const& specify_description()
                {
                    return specify_description_m;
                }

                std::string const& message()
                {
                    return message_m;
                }

                std::string const& filepath()
                {
                    return filepath_m;
                }

                int line()
                {
                    return line_m;
                }


            private:
                std::string     specify_description_m;
                bool            expectation_met_m; // met   or notmet
                                               // true  or false
                std::string     message_m;
                std::string     filepath_m;
                int             line_m;

            };

            /*!
                \brief first in map is the description
            */
            typedef std::pair<std::string, std::vector<specify_result> > context_result;
            typedef std::vector<context_result> result;

        }
    }
}

#endif // RESULT_HPP
