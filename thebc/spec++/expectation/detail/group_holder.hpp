#ifndef THEBC_SPECPP_GROUP_HOLDER_HPP
#define THEBC_SPECPP_GROUP_HOLDER_HPP

namespace spec { namespace detail {
	
template<class T>
struct group_holder
{
	typedef T		type;
};
	
}} // namespace specpp::detail

#endif /* THEBC_SPECPP_GROUP_HOLDER_HPP */
