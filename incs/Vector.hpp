/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:48:08 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/09/21 18:13:29 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP
# define _VECTOR_HPP
# include <memory>
# include "Iterator.hpp"
# include "type_traits.hpp"
# include "algorithm.hpp"
namespace ft
{
	

	template <bool, typename T = void>
	struct enable_if
	{

	};

	template <typename T		>
	struct enable_if<true, T>
	{
		typedef T type;
	};
	
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::random_access_iterator<value_type>		iterator;
			typedef ft::random_access_iterator<value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;
		
		private:
			allocator_type	_alloc;
			pointer			_front;
			pointer			_back;
			pointer			_capacity;

		public:
			explicit	vector(const allocator_type& alloc = allocator_type())
			:	_alloc(alloc), _front(0), _back(0), _capacity(0)
			{

			};

			explicit	vector(size_type n, const value_type &val = value_type(),
								const allocator_type& alloc = allocator_type())
			:	_alloc(alloc)
			{
				this->_front = this->_alloc.allocate(n);
				this->_capacity = this->_front + n;
				this->_back = this->_front;
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_back, val);
					this->_back++;
				}
			};

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc= allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			: _alloc(alloc)
			{
				size_type	n = last - first;
				this->_front = this->_alloc.allocate(n);
				this->_capacity = this->_front + n;
				this->_back = this->_front;
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_back, *first++);
					this->_back++;
				}
			};
			
			vector(const vector &x): _alloc(x._alloc), _front(0), _back(0), _capacity(0)
			{
				size_type	n;

				n = x._back - x._front;
				if (n > 0)
				{
					this->_front = this->_alloc.allocate(n);
					this->_capacity = this->_front + n;
					this->_back = this->_front;
					for (size_type i = 0; i < n; i++)
					{
						this->_alloc.construct(this->_back, x[i]);
						this->_back++;
					}
				}
			};

			virtual ~vector()
			{
				//return later
				this->clear();
				_alloc.deallocate(this->_front, this->capacity());
			};

			vector					&operator=(const vector &x)
			{
				if (&x == this)
					return (*this);
				this->clear();
				this->_front = this->_alloc.allocate(x.size());
				this->_capacity = this->_front + x.size();
				this->_back = this->_front;
				for (size_type i = 0; i < x.size(); i++)
				{
					this->_alloc.construct(this->_back, x[i]);
					this->_back++;
				}
				return (*this);
			};

			iterator				begin()
			{
				return (this->_front);
			};

			const_iterator			begin()		const
			{
				return (this->_front);
			};

			iterator				end()
			{
				return (this->_back);
			};

			const_iterator			end()		const
			{
				return (this->_back);
			};

			reverse_iterator		rbegin()
			{
				return (reverse_iterator(this->end()));
			};

			const_reverse_iterator	rbegin()	const
			{
				return (reverse_iterator(this->end()));
			};

			reverse_iterator		rend()
			{
				return (reverse_iterator(this->begin()));
			};

			const_reverse_iterator	rend()		const
			{
				return (reverse_iterator(this->begin()));
			};

			size_type				size()		const
			{
				return (this->_back - this->_front);
			};

			size_type				max_size()	const
			{
				return (allocator_type().max_size());
			};

			void					resize(size_type n, value_type val = value_type())
			{
				size_type	size;

				size = this->size();
				if (n > this->max_size())
					throw std::length_error("vector::_M_resize");
				if (n < size)
				{
					while (n < this->size())
					{
						--this->_back;
						this->_alloc.destroy(this->_back);
					}
				}
				else if ( n > size)
				{
					if (n > this->capacity())
						this->reserve(n);
					for (size_type i = 0; i < n - size ; i++)
					{
						this->_alloc.construct(this->_back, val);
						this->_back++;
					}
				}
			};

			size_type				capacity()	const
			{
				return (this->_capacity - this->_front);
			};

			bool					empty()		const
			{
				return ((this->_back - this->_front) == 0 ? true : false);
			};

			void					reserve(size_type n)
			{
				pointer		prev_front;
				pointer		prev_back;
				size_type	prev_size;
				size_type	prev_capacity;
			
				if (n >  this->max_size())
					throw std::length_error("vector::_M_reserve");
				if (n > this->capacity())
				{
					prev_front = this->_front;
					prev_back = this->_back;
					prev_size = this->size();
					prev_capacity = this->capacity();
					this->_front = this->_alloc.allocate(n);
					this->_back = this->_front;
					for (size_type i = 0; i < prev_size; i++)
					{
						this->_alloc.construct(this->_back, *prev_front++);
						this->_back++;
					}
					this->_alloc.deallocate(prev_front - prev_size, prev_capacity);
					this->_capacity = this->_front + n;
				}
			};

			reference				operator[](size_type n)
			{
				return (*(this->_front + n));
			};

			const_reference			operator[](size_type n)	const
			{
				return (*(this->_front + n));
			};

			reference				at(size_type n)
			{
				if (n >= this->size())
					throw std::out_of_range("vector::_M_range_check");
				return (*(this->_front + n));
			};

			const_reference			at(size_type n)			const
			{
				if (n >= this->size())
					throw std::out_of_range("vector::_M_range_check");
				return (*(this->_front + n));
			}

			reference				front()
			{
				return (*(this->_front));
			};

			const_reference			front()					const
			{
				return (*(this->_front));
			};
					
			reference				back()
			{
				return (*(this->_back - 1));
			};

			const_reference			back()					const
			{
				return (*(this->_back - 1));
			};

			template<class InputIterator>
			void					assign(InputIterator first, InputIterator last,
									typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				size_type		distance;
				this->clear();
				distance = static_cast<size_type>(last - first);
				if (distance > this->capacity())
					this->reserve(distance);
				for (size_type i = 0; i < distance; i++)
				{
					this->_alloc.construct(this->_back, *first++);
					this->_back++;
				}
			};

			void					assign(size_type n, const value_type &val)
			{
				this->clear();
				if (n > this->capacity())
					this->reserve(n);
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_back, val);
					this->_back++;
				}
			};

			void					push_back(const value_type &val)
			{
				if (this->size() == 0)
					this->reserve(1);
				else if (this->_back == this->_capacity)
					this->reserve(this->size() * 2);
				this->_alloc.construct(this->_back, val);
				this->_back++;
			};

			void					pop_back()
			{
				this->_alloc.destroy(this->_back - 1);
				this->_back--;
			};

			iterator				insert(iterator position, const value_type &val)
			{
				//work
				this->_alloc.construct(&(*position), val);
				return (position);
			};

			void					insert(iterator position, size_type n, const value_type &val)
			{
				//work
				this->_alloc.construct(&(*position), val);
				(void)n;
			};

			template<class InputIterator>
			void					insert(iterator position, InputIterator first, InputIterator last)
			{
				//work
				(void)first;
				(void)last;
				(void)position;
			};

			iterator				erase(iterator position)
			{
				//work
				return (position);
			};

			iterator				erase(iterator first, iterator last)
			{
				//work
				return (first);
				(void)last;
			};

			void					swap(vector &x)
			{
				//work
				(void)x;
			};

			void					clear()
			{
				while (this->size())
					this->pop_back();
			};

			allocator_type			get_allocator()			const
			{
				return (this->_alloc);
			}
	};

	template<class T, class Alloc>
	bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	};

	template<class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	};

		template<class T, class Alloc>
	bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template<class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (lhs < rhs || lhs == rhs);
	};

	template<class T, class Alloc>
	bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	};

	template<class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs || lhs == rhs);
	};

	template<class T, class Alloc>
	void	swap(vector<T, Alloc> &x, vector<T,Alloc> &y)
	{
		x.swap(y);
	};
}
#endif