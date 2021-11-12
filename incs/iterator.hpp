/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:57:56 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/10 17:17:20 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <iostream>

namespace ft
{
	struct random_access_iterator_tag
	{
		
	};

	struct bidirectional_iterator_tag
	{

	};
	

	template <class Iter>
	class	iterator_traits
	{
		public:
			typedef	typename	Iter::difference_type	difference_type;
			typedef typename	Iter::value_type		value_type;
			typedef	typename	Iter::pointer			pointer;
			typedef	typename	Iter::reference			reference;
			typedef	typename	Iter::iterator_category	iterator_category;
	};

	template <class T>
	class	iterator_traits<T*>
	{
		public:
			typedef				ptrdiff_t						difference_type;
			typedef				T								value_type;
			typedef				T*								pointer;
			typedef				T&								reference;
			typedef				ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits< const T*>
	{
		public:
			typedef				ptrdiff_t						difference_type;
			typedef				T								value_type;
			typedef				const T*						pointer;
			typedef				const T&						reference;
			typedef				ft::random_access_iterator_tag	iterator_category;
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};

	template <class T>
	class random_access_iterator : public iterator<ft::random_access_iterator_tag, T>
	{
		private:
			T*	_ptr;
		public:

			typedef	typename	ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			random_access_iterator() : _ptr(0)
			{
				
			};

			random_access_iterator(T* ptr) : _ptr(ptr)
			{

			};

			random_access_iterator(random_access_iterator const &copy) : _ptr(copy._ptr)
			{

			};

			random_access_iterator	&operator=(random_access_iterator const &other)
			{
				if (this == &other)
					return (*this);
				this->_ptr = other._ptr;
				return (*this);
			};

			virtual					~random_access_iterator()
			{

			};

			T*						base()			const
			{
				return (this->_ptr);
			};

			T&						operator*()		const
			{
				return (*(this->_ptr));
			};

			T*						operator->()	const
			{
				return (this->_ptr);
			};

			random_access_iterator&	operator++()
			{
				this->_ptr++;
				return (*this);
			};

			random_access_iterator	operator++(int)
			{

				random_access_iterator	it(*this);

				this->operator++();
				return (it);
			};

			random_access_iterator&	operator--()
			{
				this->_ptr--;
				return (*this);
			};

			random_access_iterator	operator--(int)
			{
				random_access_iterator	it(*this);

				this->operator--();
				return (it);
			};

			random_access_iterator	operator+(difference_type n)	const
			{
				return (this->_ptr + n);
			};

			random_access_iterator	operator-(difference_type n)	const
			{
				return (this->_ptr - n);
			};

			random_access_iterator&	operator+=(difference_type n)
			{
				this->_ptr += n;
				return (*this);
			};

			random_access_iterator&	operator-=(difference_type n)
			{
				this->_ptr -= n;
				return (*this);
			};

			T&						operator[](difference_type n)	const
			{
				return (*(operator+(n)));
			};
	};

	template<class Iterator1, class Iterator2>
	bool	operator<(ft::random_access_iterator<Iterator1> const &lhs, ft::random_access_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator>(ft::random_access_iterator<Iterator1> const &lhs, ft::random_access_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator<=(ft::random_access_iterator<Iterator1> const &lhs, ft::random_access_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator>=(ft::random_access_iterator<Iterator1> const &lhs, ft::random_access_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator==(ft::random_access_iterator<Iterator1> const &lhs, ft::random_access_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator!=(ft::random_access_iterator<Iterator1> const &lhs, ft::random_access_iterator<Iterator2> const &rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template<class Iter>
	random_access_iterator<Iter>	operator+(typename random_access_iterator<Iter>::difference_type n,
										 const random_access_iterator<Iter>& it)
	{
		return (random_access_iterator<Iter>(it.base() - n));
	};

	template<class Iter>
	typename	random_access_iterator<Iter>::difference_type	operator-(const random_access_iterator<Iter> &lhs,
																	const random_access_iterator<Iter> &rhs)
	{
		return (lhs.base() - rhs.base());
	};

	template<class Iter>
	class	reverse_iterator
	{
		public:
			typedef				Iter											iterator_type;
			typedef	typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef	typename	ft::iterator_traits<Iter>::value_type			value_type;
			typedef	typename	ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef	typename	ft::iterator_traits<Iter>::pointer				pointer;
			typedef	typename	ft::iterator_traits<Iter>::reference			reference;

		private:
			iterator_type		_it;

		public:
			reverse_iterator() : _it(0)
			{

			};

			explicit	reverse_iterator(iterator_type x) : _it(x)
			{

			};

			template<class U>
			reverse_iterator(const reverse_iterator<U> &other) : _it(other.base())
			{

			};

			virtual		~reverse_iterator()
			{

			};

			template<class U>
			reverse_iterator&	operator=(const reverse_iterator<U> &other)
			{
				if (this == &other)
					return(*this);
				this->_it = other._it;
				return (*this);
			};

			iterator_type		base()							const
			{
				return (this->_it);
			};

			reference			operator*()						const
			{
				iterator_type	tmp = this->_it;
				return (*--tmp);
			};

			pointer				operator->()					const
			{
				return (&(this->operator*()));
			};

			reference			operator[](difference_type n)	const
			{
				return (this->_it[-n - 1]);
			}

			reverse_iterator&	operator++()
			{
				--this->_it;
				return (*this);
			};

			reverse_iterator	operator++(int)
			{

				reverse_iterator	it(*this);

				this->operator++();
				return (it);
			};

			reverse_iterator&	operator--()
			{
				++this->_it;
				return (*this);
			};

			reverse_iterator	operator--(int)
			{
				reverse_iterator	it(*this);

				this->operator--();
				return (it);
			};

			reverse_iterator	operator+(difference_type n)	const
			{
				return (reverse_iterator(this->_it - n));
			};

			reverse_iterator	operator-(difference_type n)	const
			{
				return (reverse_iterator(this->_it + n));
			};

			reverse_iterator&	operator+=(difference_type n)
			{
				this->_it -= n;
				return (*this);
			};

			reverse_iterator&	operator-=(difference_type n)
			{
				this->_it += n;
				return (*this);
			};
	};

	template<class Iterator1, class Iterator2>
	bool	operator==(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator!=(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator<(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator<=(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator>(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template<class Iterator1, class Iterator2>
	bool	operator>=(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template<class Iter>
	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n,
										 const reverse_iterator<Iter>& it)
	{
		return (reverse_iterator<Iter>(it.base() - n));
	};

	template<class Iter>
	typename	reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter> &lhs,
																	const reverse_iterator<Iter> &rhs)
	{
		return (lhs.base() - rhs.base());
	};
}
#endif