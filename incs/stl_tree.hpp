/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:27:11 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/10/12 16:13:50 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STL_TREE_HPP

# define STL_TREE_HPP

# include "iterator.hpp"
# include <memory>

namespace ft
{
	enum    rb_color
	{
		red = false,
		black = true
	};

	struct node_base
	{
		typedef			node_base*	pointer;
		typedef	const	node_base*	const_pointer;
		rb_color		color;
		pointer			parent;
		pointer			left;
		pointer			right;

		static			pointer	minimum(pointer	node)
		{
			while (node->left != 0)
				node = node->left;
			return node;
		};

		static	const_pointer	minimum(const_pointer node)
		{
			while (node->left != 0)
				node = node->left;
			return node;
		};

		static			pointer	maximum(pointer	node)
		{
			while (node->right != 0)
				node = node->right;
			return node;
		};

		static	const_pointer	maximum(const_pointer node)
		{
			while (node->right != 0)
				node = node->right;
			return node;
		};		
	};

	template<class T>
	struct node : public node_base
	{
		typedef		node<T>*	link_type;
		T			value;
	};

	template <class T>
	class rb_tree_iterator : iterator<bidirectional_iterator_tag, T>
	{
		public:
			typedef	T					value_type;
			typedef	T&					reference;
			typedef	T*					pointer;
			typedef	rb_tree_iterator<T>	self;
			typedef	node_base::pointer	base_pointer;
			typedef	typename	ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef	node<T>*			link_type;
			base_pointer	_node;

			rb_tree_iterator() : _node(0)
			{
				
			};

			rb_tree_iterator(T* node) : _node(node)
			{

			};

			rb_tree_iterator(rb_tree_iterator const &copy) : _ptr(copy._node)
			{

			};

			rb_tree_iterator	&operator=(rb_tree_iterator const &other)
			{
				if (this == &other)
					return (*this);
				this->_node = other._node;
				return (*this);
			};

			virtual					~rb_tree_iterator()
			{

			};

			reference				operator*()		const
			{
				return (static_cast<link_type>(this->_node)->value);
			};

			pointer						operator->()	const
			{
				return (&static_cast<link_type>(this->_node)->value);
			};

			self&	operator++()
			{
				if (this->_node->right != 0)
				{
					this->_node = this->_node->right;
					while (this->_node->left != 0)
						this->_node = this->_node->left;
				}
				else
				{
					base_pointer	tmp = this->_node->parent;
					while (this->_node == this->_tmp->right)
					{
						this->_node = tmp;
						tmp = tmp->parent;
					}
					if (this->_node->right != tmp)
						this->_node = tmp;
				}
				return (*this);
			};

			self	operator++(int)
			{

				self	it(*this);

				this->operator++();
				return (it);
			};

			self&	operator--()
			{
				base_pointer	tmp;

				if (this->_node->color == rb_color.red && this->_node->parent->parent == this->_node)
					this->_node = this->_node->right;
				else if (this->_node->left != 0)
				{
					tmp = this->_node->left;
					while (tmp->right != 0)
						tmp = tmp->right;
					this->_node = tmp;
				}
				else
				{
					tmp = this->_node->left;
					while (this->_node == tmp->left)
					{
						this->_node = tmp;
						tmp = tmp->parent;
					}
					this->_node = tmp;
				}
				return (*this);
			};

			self	operator--(int)
			{
				self	it(*this);

				this->operator--();
				return (it);
			};
			
			difference_type			operator==(const rb_tree_iterator &rhs)	const
			{
				return (this->_node == rhs._node);
			};

			difference_type			operator!=(const rb_tree_iterator &rhs)	const
			{
				return (this->_node == rhs._node);
			};
	};

	template <class T>
	class rb_tree_const_iterator : iterator<bidirectional_iterator_tag, T>
	{
		public:
			typedef	T					value_type;
			typedef	T&					reference;
			typedef	T*					pointer;
			typedef	rb_tree_const_iterator<T>	self;
			typedef	node_base::const_pointer	base_pointer;
			typedef	typename	ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef	node<T>*			link_type;
			base_pointer	_node;
			
			rb_tree_const_iterator() : _node(0)
			{
				
			};

			rb_tree_const_iterator(T* node) : _node(node)
			{

			};

			rb_tree_const_iterator(rb_tree_iterator const &copy) : _ptr(copy._node)
			{

			};

			rb_tree_const_iterator	&operator=(rb_tree_iterator const &other)
			{
				if (this == &other)
					return (*this);
				this->_node = other._node;
				return (*this);
			};

			virtual					~rb_tree_iterator()
			{

			};

			reference				operator*()		const
			{
				return (static_cast<link_type>(this->_node)->value);
			};

			pointer						operator->()	const
			{
				return (&static_cast<link_type>(this->_node)->value);
			};

			self&	operator++()
			{
				if (this->_node->right != 0)
				{
					this->_node = this->_node->right;
					while (this->_node->left != 0)
						this->_node = this->_node->left;
				}
				else
				{
					base_pointer	tmp = this->_node->parent;
					while (this->_node == this->_tmp->right)
					{
						this->_node = tmp;
						tmp = tmp->parent;
					}
					if (this->_node->right != tmp)
						this->_node = tmp;
				}
				return (*this);
			};

			self	operator++(int)
			{
				self	it(*this);

				this->operator++();
				return (it);
			};

			self&	operator--()
			{
				base_pointer	tmp;

				if (this->_node->color == rb_color.red && this->_node->parent->parent == this->_node)
					this->_node = this->_node->right;
				else if (this->_node->left != 0)
				{
					tmp = this->_node->left;
					while (tmp->right != 0)
						tmp = tmp->right;
					this->_node = tmp;
				}
				else
				{
					tmp = this->_node->left;
					while (this->_node == tmp->left)
					{
						this->_node = tmp;
						tmp = tmp->parent;
					}
					this->_node = tmp;
				}
				return (*this);
			};

			self	operator--(int)
			{
				self	it(*this);

				this->operator--();
				return (it);
			};
			
			difference_type			operator==(const rb_tree_iterator &rhs)	const
			{
				return (this->_node == rhs._node);
			};

			difference_type			operator!=(const rb_tree_iterator &rhs)	const
			{
				return (this->_node == rhs._node);
			};
	};

	template <class T>
	bool	operator==(const rb_tree_iterator<T> &lhs, const rb_tree_const_iterator<T> &rhs)
	{
		return (lhs._node == rhs._node);
	};

	template <class T>
	bool	operator!=(const rb_tree_iterator<T> &lhs, const rb_tree_const_iterator<T> &rhs)
	{
		return (lhs._node != rhs._node);
	};
	
	template <class Key, class T, class Compare, class Alloc = std::allocator<T> >
	class rb_tree
	{
		public:
			typedef	typename	Alloc::template rebind< node<T> >::other node_allocator;
			typedef				node_base::pointer			base_pointer;
			typedef				node_base::const_pointer	const_base_pointer;
			typedef				Key							key_type;
			typedef				T							value_type;
			typedef				value_type*					pointer;
			typedef				const value_type*			const_pointer;
			typedef				value_type&					value_type;
			typedef				const value_type&			const_reference;
			typedef				node<value_type>			tree_node;
			typedef				tree_node*					link_type;
			typedef				const tree_node*			const_link_type;
			typedef				Alloc						allocator_type;
			typedef				allocator_type::size_type	size_type;
			typedef				ft::rb_tree_iterator<value_type>				iterator;
			typedef				ft::rb_tree_const_iterator<value_type>			const_iterator;
			typedef				ft::reverse_iterator<iterator>					reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename	ft::iterator_traits<iterator>::difference_type	difference_type;
		
		private:

			Compare			_comp;
			tree_node		_header;
			size_type		_count;
			node_allocator	_alloc;
		
		public:

			rb_tree()
			{

			};

			rb_tree(const Compare& comp) : _comp(comp)
			{

			};

			rb_tree(const Compare comp, const allocator_type& alloc) :
					_comp(comp), _alloc(alloc)
			{

			};

			rb_tree(const rb_tree& tree) : _alloc(tree._alloc), _comp(tree)
			{

			};

			~rb_tree()
			{

			};

			rb_tree		&operator=(const rb_tree &tree)
			{

			};

			link_type	copy(link_type)
			{
				link_type	top 
			};
	};
};

#endif