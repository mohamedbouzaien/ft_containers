/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:51:13 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/09/15 12:12:47 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
	template<class T, T v>
	struct integral_constant
	{
		static const	T						value = v;
		typedef			T						value_type;
		typedef			integral_constant<T, v>	type;
		operator T()
		{
			return v;
		}
	};

	typedef	integral_constant<bool, true>	true_type;

	typedef	integral_constant<bool, false>	false_type;

	template<typename>
	struct	is_integral_base: ft::false_type
	{

	};

	template<>
	struct	is_integral_base<bool>: ft::true_type
	{

	};

	template<>
	struct	is_integral_base<int>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<unsigned int>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<short>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<unsigned short int>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<long int>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<unsigned long int>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<long long int>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<unsigned long long int>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<char>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<signed char>: ft::true_type
	{
		
	};

	template<>
	struct	is_integral_base<unsigned  char>: ft::true_type
	{
		
	};

	template<typename T>
	struct	is_integral: is_integral_base<T>
	{

	};
	
}

#endif