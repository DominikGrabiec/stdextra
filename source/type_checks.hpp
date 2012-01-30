#pragma once
#ifndef _STDEXTRA_TYPE_CHECKS_
#define _STDEXTRA_TYPE_CHECKS_

#include <iterator>
#include <type_traits>

namespace stdextra
{
	template <class Iterator, class T>
	struct enable_if_iterates_type : public std::enable_if<std::is_same<typename std::iterator_traits<Iterator>::value_type, T>::value, T>
	{
	};
}

#endif // _STDEXTRA_TYPE_CHECKS_
