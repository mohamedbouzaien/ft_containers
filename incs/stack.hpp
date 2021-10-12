/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:30:24 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/09/30 17:43:27 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	T			value_type;
			typedef	Container	container_type;
			typedef	size_t		size_type;

		protected:
			container_type		_ctnr;
		
		public:
			explicit	stack(const container_type &ctnr = container_type()) : _ctnr(ctnr)
			{
				
			};

			bool				empty()	const
			{
				return (this->_ctnr.empty());
			};

			size_type			size()	const
			{
				return (this->_ctnr.size());
			};

			value_type			&top()
			{
				return (this->_ctnr.back());
			};

			const value_type	&top()	const
			{
				return (this->_ctnr.back());
			};

			void				push(const value_type &val)
			{
				return (this->_ctnr.push_back(val));
			};

			void				pop()
			{
				return (this->_ctnr.pop_back());
			};
			template<class value_type, class container_type>
			friend	bool	operator==(const stack<value_type, container_type> &lhs, stack<value_type, container_type> &rhs);
			
			template<class value_type, class container_type>
			friend	bool	operator!=(const stack<value_type, container_type> &lhs, const stack<value_type, container_type> &rhs);

			template<class value_type, class container_type>
			friend	bool	operator<(const stack<value_type, container_type> &lhs, const stack<value_type, container_type> &rhs);

			template<class value_type, class container_type>
			friend	bool	operator<=(const stack<value_type, container_type> &lhs, const stack<value_type, container_type> &rhs);

			template<class value_type, class container_type>
			friend	bool	operator>(const stack<value_type, container_type> &lhs, const stack<value_type, container_type> &rhs);

			template<class value_type, class container_type>
			friend	bool	operator>=(const stack<value_type, container_type> &lhs, const stack<value_type, container_type> &rhs);
	};

	template<class T, class Container>
	bool	operator==(const stack<T, Container> &lhs, stack<T, Container> &rhs)
	{
		return (lhs._ctnr == rhs._ctnr);
	};

	template<class T, class Container>
	bool	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr != rhs._ctnr);
	};

		template<class T, class Container>
	bool	operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr < rhs._ctnr);
	};

	template<class T, class Container>
	bool	operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr <= rhs._ctnr);
	};

	template<class T, class Container>
	bool	operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr > rhs._ctnr);
	};

	template<class T, class Container>
	bool	operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._ctnr >= rhs._ctnr);
	};
};

#endif