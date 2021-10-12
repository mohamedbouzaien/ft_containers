/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:08:06 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/10/06 21:04:47 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP

# define MAP_HPP

# include <memory>
# include "functional.hpp"
# include "utility.hpp"
# include "stl_tree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef	Key											key_type;
			typedef	T											mapped_type;
			typedef	ft::pair<const key_type, mapped_type>		value_type;
			typedef	Compare										key_compare;
			class	value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					Compare	comp;
					value_type(Compare c) : comp(c)
					{
						
					}
				public:
					typedef	bool		result_type;
					typedef	value_type	first_argument_type;
					typedef	value_type	second_argument_type;
					bool	operator() (const value_type &x, const value_type &y)	const
					{
						return (comp(x.first, y.first));
					};

			};
			typedef				Alloc											allocator_type;
			typedef	typename	allocator_type::reference						reference;
			typedef	typename	allocator_type::const_reference					const_reference;
			typedef	typename	allocator_type::pointer							pointer;
			typedef	typename	allocator_type::const_pointer					const_pointer;
			typedef				ft::rb_tree_iterator<value_type>				iterator;
			typedef				ft::rb_tree_const_iterator<value_type>			const_iterator;
			typedef				ft::reverse_iterator<iterator>					reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename	ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename	allocator_type::size_type						size_type;

		private:
			allocator_type		_alloc;
			key_compare			_comp;
			node<value_type>	_parent;


		public:
			explicit	map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()):
						_alloc(alloc), _comp(comp)
			{
				
			};

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), 
				const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0):
				_alloc(alloc), _comp(comp)
			{
				
			};

			map (const map &x) : _alloc(x._alloc), _comp(x._comp)
			{

			};
			
			~map()
			{

			};
			
			map							&operator=(const map &x)
			{

			};

			iterator					begin()
			{

			};

			const_iterator				begin()						const
			{

			};

			iterator					end()
			{

			};

			const_iterator				end()						const
			{

			};

			reverse_iterator			rbegin()
			{

			};

			const_reverse_iterator		rbegin()					const
			{

			};

			reverse_iterator			rend()
			{

			};

			const_reverse_iterator		rend()						const
			{
				
			};

			bool						empty()						const
			{

			};

			size_type					size()						const
			{

			};

			size_type					max_size()					const
			{

			};

			mapped_type					operator[](const key_type &k)
			{

			};

			ft::pair<iterator, bool>	insert(const value_type &val)
			{

			};

			iterator					insert(iterator position, const value_type &val)
			{

			};

			template <class InputIterator>
			void						insert(InputIterator first, InputIterator last)
			{

			};

			void						erase(iterator position)
			{

			};

			size_type					erase(const key_type &k)
			{

			};

			void						erase(iterator first, iterator last)
			{

			};

			void						swap(map &x)
			{

			};

			void						clear()
			{

			};

			key_compare					key_comp()						const
			{

			};

			value_compare				value_comp()					const
			{

			};

			iterator					find(const key_type &k)
			{

			};

			const_iterator				find(const key_type &k)			const
			{

			};
			
			size_type					count(const key_type &k)		const
			{

			};

			iterator					lower_bound(const key_type &k)
			{

			};

			const_iterator				lower_bound(const key_type &k)	const
			{

			};

			iterator					upper_bound(const key_type &k)
			{

			};

			const_iterator				upper_bound(const key_type &k)	const
			{

			};

			pair<const_iterator, const_iterator>	equal_range(const key_type &k)	const
			{

			};

			pair<terator, iterator>		equal_range(const key_type &k)
			{

			};

			allocator_type				get_allocator()					const
			{
				return (this->_alloc);
			};
	};
};

#endif