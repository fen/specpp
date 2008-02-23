#ifndef THEBC_SPECPP_BOOLEAN_INVERTER_HPP
#define THEBC_SPECPP_BOOLEAN_INVERTER_HPP

namespace spec { namespace detail {

template<bool B>
struct boolean_inverter;	

template<>
struct boolean_inverter<true>
{
	static const bool value = false;
};

template<>
struct boolean_inverter<false>
{
	static const bool value = true;
};

}} // namespace specpp::detail

#endif /* THEBC_SPECPP_BOOLEAN_INVERTER_HPP */
