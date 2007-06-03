#ifndef THEBC_SPECPP_EXPECTATION_GROUPS_TYPE_TYPE_HPP
#define THEBC_SPECPP_EXPECTATION_GROUPS_TYPE_TYPE_HPP

#include "check_type.hpp"

namespace spec { namespace groups {

template<typename Actual, bool Not = false>
struct type_t: detail::if_not_impl<type_t, Actual, Not>
{
    type_t(Actual const& actual_value):

    base_t::base_t( actual_value )
    {
    }

    template<typename Expected>
    bool be_a()
    {
        if( type::check_type<Actual, Expected>::value )
        {
            if( Not )
            {
                std::string message = "The actual type should not have matched but did";
                return report_error( message );
            }
            else
                return true;
        }
        else
        {
            if( Not )
                return true;
            else
            {
                std::string message = "The actual type didn't match the expected type";
                return report_error( message );
            }
        }
    }
    template<typename Expected>
    inline bool be_an()
    {
        return be_a<Expected>();
    }

};
    
}} // namespace spec::groups


#endif /* THEBC_SPECPP_EXPECTATION_GROUPS_TYPE_TYPE_HPP */
