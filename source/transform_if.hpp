#pragma once
#ifndef _STDEXTRA_TRANSFORM_IF_
#define _STDEXTRA_TRANSFORM_IF_

namespace stdextra
{

	template <typename InputIterator, typename OutputIterator, typename Predicate, typename UnaryFunction>
	inline OutputIterator transform_if(InputIterator _first, InputIterator _last, OutputIterator _dest, Predicate _pred, UnaryFunction _func)
	{
		for (; _first != _last; ++_first)
		{
			if (_pred(*_first))
			{
				*_dest++ = _func(*_first);
			}
		}
		return (_dest);
	}


	template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryPredicate, typename BinaryFunction>
	inline OutputIterator transform_if(InputIterator1 _first1, InputIterator1 _last1, InputIterator2 _first2, OutputIterator _dest, BinaryPredicate _pred, BinaryFunction _func)
	{
		for (; _first1 != _last1; ++_first1, ++_first2)
		{
			if (_pred(*_first1, *_first2))
			{
				*_dest++ = _func(*_first1, *_first2);
			}
		}
		return (_dest);
	}
}

#endif // _STDEXTRA_TRANSFORM_IF_
