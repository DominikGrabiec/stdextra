#pragma once
#ifndef _STDEXTRA_TRANSFORM_IF_
#define _STDEXTRA_TRANSFORM_IF_

namespace stdextra
{

	template <class InputIterator, class OutputIterator, class Predicate, class UnaryFunction>
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


	template <class InputIterator1, class InputIterator2, class OutputIterator, class BinaryPredicate, class BinaryFunction>
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
