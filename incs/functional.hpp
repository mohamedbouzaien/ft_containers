/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:53:00 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/09/30 21:10:51 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_HPP

# define FUNCTIONAL_HPP

namespace ft
{
	template <class Arg1, class Arg2, class Result>
	struct	binary_function
	{
		typedef	Arg1	first_argument_type;
		typedef	Arg2	second_argument_type;
		typedef	Result	result_type;
	};

	template <class T>
	struct less : binary_function <T, T, bool>
	{
		bool	operator() (const T &x, const T &y)	const
		{
			return (x < y);
		};
	};
	
};

#endif