#ifndef CPP_EXPECTATION_BOOLEAN_INVERTER_HPP
#define CPP_EXPECTATION_BOOLEAN_INVERTER_HPP

namespace cpp { namespace expectation { namespace detail {

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

}}}

#endif /* CPP_EXPECTATION_BOOLEAN_INVERTER_HPP */
