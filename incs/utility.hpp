/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:07:21 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/10/28 02:00:38 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILITY_HPP

# define _UTILITY_HPP

namespace ft
{
	template <class T1, class T2>
	struct  pair
	{
		typedef T1  first_type;
		typedef T2  second_type;

		first_type  first;
		second_type second;

		pair() : first(), second()
		{
			
		};

		pair(const pair &pr) : first(pr.first), second(pr.second)
		{

		};

		pair(const first_type &a, const second_type &b) : first(a), second(b)
		{

		};

		~pair()
		{

		};

		pair	&operator=(const pair &pr)
		{
			if (&pr == this)
				return (*this);
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		};
	};
	template <class T1, class T2>
	bool	operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template <class T1, class T2>
	bool	operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T1, class T2>
	bool	operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	};
	
	template <class T1, class T2>
	bool	operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (!(rhs < lhs));
	};

	template <class T1, class T2>
	bool	operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	};

	template <class T1, class T2>
	bool	operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return (!(lhs < rhs));
	};

	template <class T1, class T2>
	ft::pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	};
};

#endif