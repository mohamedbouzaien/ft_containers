/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:08:06 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/14 20:11:52 by mbouzaie         ###   ########.fr       */
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
			typedef	ft::pair<const key_type, mapped_type >		value_type;
			typedef	Compare										key_compare;
			class	value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					Compare	comp;
					value_compare(Compare c) : comp(c)
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
			typedef	typename	ft::rb_tree<value_type, Compare>::iterator		iterator;
			typedef	typename	ft::rb_tree<value_type, Compare>::const_iterator	const_iterator;
			typedef				ft::reverse_iterator<iterator>					reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef 			ptrdiff_t										difference_type;
			typedef typename	allocator_type::size_type						size_type;

		private:
			allocator_type					_alloc;
			key_compare						_comp;
			rb_tree<value_type, Compare>	_tree;


		public:
			explicit	map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()):
						_alloc(alloc), _comp(comp), _tree(comp)
			{
				
			};

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), 
				const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0):
				_alloc(alloc), _comp(comp), _tree(comp)
			{
				this->insert(first, last);
			};

			map (const map &x) : _alloc(x._alloc), _comp(x._comp)
			{
				this->insert(x.begin(), x.end());
			};
			
			~map()
			{
				this->clear();
			};
			
			map							&operator=(const map &x)
			{	if (this == &x)
					return (*this);
				this->clear();
				this->insert(x.begin(), x.end());
				return (*this);
			};

			iterator					begin()
			{
				return (iterator(this->_tree.begin()));
			};

			const_iterator				begin()						const
			{
				return (const_iterator(this->_tree.begin()));
			};

			iterator					end()
			{
				return (iterator(this->_tree.end()));
			};

			const_iterator				end()						const
			{
				return (const_iterator(this->_tree.end()));
			};

			reverse_iterator			rbegin()
			{
				return (reverse_iterator(this->end()));
			};

			const_reverse_iterator		rbegin()					const
			{
				return (const_reverse_iterator(this->end()));
			};

			reverse_iterator			rend()
			{
				return (reverse_iterator(this->begin()));
			};

			const_reverse_iterator		rend()						const
			{
				return (const_reverse_iterator(this->begin()));				
			};

			bool						empty()						const
			{
				return (this->_tree.empty());
			};

			size_type					size()						const
			{
				return (this->_tree.size());
			};

			size_type					max_size()					const
			{
				return (this->_tree.max_size());
			};

			mapped_type&				operator[](const key_type &k)
			{
				return (this->insert(this->begin(), ft::make_pair(k, mapped_type()))->second);
			};

			ft::pair<iterator, bool>	insert(const value_type &val)
			{
				iterator it = this->find(val.first);
				if (it != this->end())
					return(ft::make_pair(it, false));
				return(ft::make_pair(_tree.insert(val), true));
			};

			iterator					insert(iterator position, const value_type &val)
			{
				position = this->find(val.first);
				if (position != this->end())
					return (position);
				return (_tree.insert(val));
			};

			template <class InputIterator>
			void						insert(InputIterator first, InputIterator last,
											typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				while (first != last)
					this->insert(*(first++));
			};

			void						erase(iterator position)
			{
				this->erase((*position).first);
			};

			size_type					erase(const key_type &k)
			{
				return (this->_tree.erase(ft::make_pair(k, mapped_type())));
			};

			void						erase(iterator first, iterator last)
			{
				while (first != last)
				{
					iterator	temp(first);
					first++;
					this->erase(temp);
				}
			};

			void						swap(map &x)
			{
				allocator_type					alloc;
				key_compare						comp;
				rb_tree<value_type, Compare>	tree;
				
				alloc = this->_alloc;
				this->_alloc = x._alloc;
				x._alloc = alloc;
				comp = this->_comp;
				this->_comp = x._comp;
				x._comp = comp;
				tree = this->_tree;
				this->_tree = x._tree;
				x._tree = tree;
			};

			void						clear()
			{
				this->erase(this->begin(), this->end());
			};

			key_compare					key_comp()						const
			{
				return (this->_comp);
			};

			value_compare				value_comp()					const
			{
				return (value_compare(this->_comp));
			};

			iterator					find(const key_type &k)
			{
				return (iterator(this->_tree.find(ft::make_pair(k, mapped_type()))));
			};

			const_iterator				find(const key_type &k)			const
			{
				return (const_iterator(this->_tree.find(ft::make_pair(k, mapped_type()))));
			};
			
			size_type					count(const key_type &k)		const
			{
				return (this->_tree.count(ft::make_pair(k, mapped_type())));
			};

			iterator					lower_bound(const key_type &k)
			{
				iterator	it = this->begin();

				while (it != this->end())
				{
					if (!this->_comp(it->first, k))
						break;
					it++;
				}
				return (it);
			};

			const_iterator				lower_bound(const key_type &k)	const
			{
				const_iterator	it = this->begin();

				while (it != this->end())
				{
					if (!this->_comp(it->first, k))
						break;
					it++;
				}
				return (it);
			};

			iterator					upper_bound(const key_type &k)
			{
				iterator	it = this->begin();

				while (it != this->end())
				{
					if (this->_comp(k, it->first))
						break;
					++it;
				}
				return (it);
			};

			const_iterator				upper_bound(const key_type &k)	const
			{
				const_iterator	it = this->begin();

				while (it != this->end())
				{
					if (this->_comp(k, it->first))
						break;
					++it;
				}
				return (it);
			};

			pair<const_iterator, const_iterator>	equal_range(const key_type &k)	const
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			};

			pair<iterator, iterator>		equal_range(const key_type &k)
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			};

			allocator_type				get_allocator()					const
			{
				return (this->_alloc);
			};
	};
};

#endif