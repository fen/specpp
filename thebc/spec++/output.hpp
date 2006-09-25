// Spec++ output.hpp  --------------------------------------------------------//
// © Copyright Fredrik Eriksson.

// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// See http://www.thebc.org/libs/ for documenation

/*************************************************************************************************/
#ifndef OUTPUT_HPP
#define OUTPUT_HPP

/*************************************************************************************************/

namespace spec
{

/*************************************************************************************************/

    template<typename FormatT>
    class output
    {
        typedef runner::result              result;
        typedef runner::specify_result      specify_result;
        typedef std::pair<std::string, std::vector<specify_result> > context_pair;

    public:
        typedef FormatT     format_type;

        output(runner::result const& result)
        : result_m(result)
        {}

        void display();
        void display(runner::result const& result);

    private:
        runner::result  result_m;
        format_type     format_m;
    };

/*************************************************************************************************/

    template<typename T>
    void output<T>::display()
    {
        foreach(context_pair context, result_m)
        {
            // first is the context name/description
            format_m.context_start(std::cout, context.first);

            // second is the vector with N specifyers.
            foreach(specify_result& specify, context.second)
            {
                format_m.specifyer(std::cout, specify);
            }
        }
        format_m.finish(std::cout);
    }

/*************************************************************************************************/

    template<typename T>
    void output<T>::display(runner::result const& result)
    {
        result_m = result;
        display();
    }

} // namespace spec

/*************************************************************************************************/



#endif // OUTPUT_HPP

