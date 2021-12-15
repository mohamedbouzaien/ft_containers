/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:27:11 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/15 01:21:05 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STL_TREE_HPP

# define STL_TREE_HPP

# include "iterator.hpp"
# include "functional.hpp"
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
	};

	template<class T>
	struct node : public node_base
	{
		typedef		node<T>*	link_type;
		T			value;
		rb_color	color;
		link_type	parent;
		link_type	left;
		link_type	right;

 		bool	is_on_left()
		{
			 return (this->parent && this == parent->left);
		};

		node*	sibling()
		{
			if (this->parent == 0)
				return (0);
			if (this->is_on_left())
				return (this->parent->right);
			return (this->parent->left);
		}
	};

	template <class T>
	class rb_tree_iterator : public ft::iterator<bidirectional_iterator_tag, T>
	{
		public:
			typedef	T					value_type;
			typedef	T&					reference;
			typedef	T*					pointer;
			typedef	rb_tree_iterator<T>	self;
			typedef	node_base::pointer	base_pointer;
			typedef	ptrdiff_t			difference_type;
			typedef	node<T>*			link_type;
			link_type	_node;

			rb_tree_iterator() : _node()
			{
				
			};

			rb_tree_iterator(link_type node) : _node(node)
			{

			};

			rb_tree_iterator(self const &copy) : _node(copy._node)
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
					link_type	tmp = this->_node->parent;
					while (this->_node == tmp->right)
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
				link_type	tmp;

				if (this->_node->color == red && this->_node->parent->parent == this->_node)
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
					tmp = this->_node->parent;
					while (tmp && this->_node == tmp->left)
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
				return (this->_node != rhs._node);
			};
	};

	template <class T>
	class rb_tree_const_iterator : public ft::iterator<bidirectional_iterator_tag, T>
	{
		public:
			typedef	T					value_type;
			typedef	T&					reference;
			typedef	T*					pointer;
			typedef	rb_tree_const_iterator<T>	self;
			typedef	node_base::const_pointer	base_pointer;
			typedef	ptrdiff_t			difference_type;
			typedef	node<T>*			link_type;

			link_type	_node;
			
			rb_tree_const_iterator() : _node()
			{
				
			};

			rb_tree_const_iterator(link_type node) : _node(node)
			{

			};

			rb_tree_const_iterator(rb_tree_const_iterator const &copy) : _node(copy._node)
			{

			};

			rb_tree_const_iterator(rb_tree_iterator<T> const &copy) : _node(copy._node)
			{

			};

			rb_tree_const_iterator	&operator=(rb_tree_const_iterator const &other)
			{
				if (this == &other)
					return (*this);
				this->_node = other._node;
				return (*this);
			};

			virtual					~rb_tree_const_iterator()
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
					link_type	tmp = this->_node->parent;
					while (this->_node == tmp->right)
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
				link_type	tmp;

				if (this->_node->color == red && this->_node->parent->parent == this->_node)
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
					tmp = this->_node->parent;
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
			
			difference_type			operator==(const rb_tree_const_iterator &rhs)
			{
				return (this->_node == rhs._node);
			};

			difference_type			operator!=(const rb_tree_const_iterator &rhs)
			{
				return (this->_node != rhs._node);
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
	
	template <class T, class Compare, class Alloc = std::allocator<T> >
	class rb_tree
	{
		public:
			typedef	typename	Alloc::template rebind< node<T> >::other node_allocator;
			typedef				node_base::pointer			base_pointer;
			typedef				node_base::const_pointer	const_base_pointer;
			typedef				T							value_type;
			typedef				value_type*					pointer;
			typedef				const value_type*			const_pointer;
			typedef				value_type&					reference;
			typedef				const value_type&			const_reference;
			typedef				node<value_type>			tree_node;
			typedef				tree_node*					link_type;
			typedef				const tree_node*			const_link_type;
			typedef				Alloc						allocator_type;
			typedef	typename	allocator_type::size_type	size_type;
			typedef				ft::rb_tree_iterator<value_type>				iterator;
			typedef				ft::rb_tree_const_iterator<value_type>			const_iterator;
			typedef				ft::reverse_iterator<iterator>					reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef 			ptrdiff_t										difference_type;
		
		private:

			Compare			_comp;
			link_type		_header;
			size_type		_count;
			node_allocator	_nalloc;
			allocator_type	_palloc;

			link_type	createNode(value_type val)
			{
				link_type	new_node;

				new_node = _nalloc.allocate(1);
				new_node->color = red;
				this->_palloc.construct(&new_node->value, val);
				new_node->parent = 0;
				new_node->left = 0;
				new_node->right= 0;
				return (new_node);
			};

			link_type	rotate_left(link_type	node)
			{
				link_type	x;
				link_type	y;

				x = node->right;
				y = x->left;
				x->left = node;
				node->right = y;
				x->parent = node->parent;
				node->parent = x;
				if (y != 0)
					y->parent = node;
				return (x);
			};

			link_type	rotate_right(link_type node)
			{
				link_type	x;
				link_type	y;

				x = node->left;
				y = x->right;
				x->right = node;
				node->left = y;
				x->parent = node->parent;
				node->parent = x;
				if (y != 0)
					y->parent = node;
				return (x);
			};

			link_type	left_left_rotation(link_type node)
			{
				node = this->rotate_left(node);
				node->color = black;
				node->left->color = red;
				return (node);
			};

			link_type	right_right_rotation(link_type node)
			{
				node = this->rotate_right(node);
				node->color = black;
				node->right->color = red;
				return (node);
			};

			link_type	right_left_rotation(link_type node)
			{
				node->right = this->rotate_right(node->right);
				node->right->parent = node;
				node = this->rotate_left(node);
				node->color = black;
				node->left->color = red;
				return (node);
			};

			link_type	left_right_rotation(link_type node)
			{
				node->left = this->rotate_left(node->left);
				node->left->parent = node;
				node = this->rotate_right(node);
				node->color = black;
				node->right->color = red;
				return (node);
			};

			void	handle_double_black_rotation(link_type node)
			{
				if (node == this->_header)
					return;
				link_type	sibling = node->sibling();
				link_type	parent = node->parent;
				if (sibling == 0)
					handle_double_black_rotation(parent);
				else
				{
					if (sibling->color == red)
					{
						parent->color = red;
						sibling->color = black;
						if (sibling->is_on_left())
							rotate_right(parent);
						else
							rotate_left(parent);
					handle_double_black_rotation(node);	
					}
					else
					{
						if ((sibling->left != 0 && sibling->left->color == red) ||
							(sibling->right != 0 && sibling->right->color == red))
						{
							if (sibling->left != 0 && sibling->left->color == red)
							{
								if (sibling->is_on_left())
									left_left_rotation(parent);
								else
									right_left_rotation(parent);
							}
							else
							{
								if (sibling->is_on_left())
									left_right_rotation(parent);
								else
									right_right_rotation(parent);
							}
						}
						else
						{
							sibling->color = red;
							if (parent->color == black)
								handle_double_black_rotation(parent);
							else
								parent->color = black;
						}
					}
				}
			}

			link_type	handle_double_red_roation(link_type node)
			{
				if (node->parent->right == node)
				{
					if (node->parent->left == 0 || node->parent->left->color == black)
					{
						if (node->left != 0 && node->left->color == red)
							node->parent = right_left_rotation(node->parent);
						else if (node->right != 0 && node->right->color == red)
							node->parent = left_left_rotation(node->parent);
					}
					else
					{
						node->parent->left->color = black;
						node->color = black;
						if (node->parent != this->_header)
							node->parent->color = red;
					}
				}
				else
				{
					if (node->parent->right == 0 || node->parent->right->color == black)
					{
						if (node->left != 0 && node->left->color == red)
							node->parent = right_right_rotation(node->parent);
						else if (node->right != 0 && node->right->color == red)
							node->parent = left_right_rotation(node->parent);
					}
					else
					{
						node->parent->right->color = black;
						node->color = black;
						if (node->parent != this->_header)
							node->parent->color = red;
					}
				}
				return (node);
			}
			
			void			swapValues(link_type u, link_type v)
			{
				value_type 	tmp;
				this->_palloc.construct(&tmp,u->value);
				this->_palloc.destroy(&u->value);
				this->_palloc.construct(&u->value, v->value);
				this->_palloc.destroy(&v->value);
				this->_palloc.construct(&v->value, tmp);
				this->_palloc.destroy(&tmp);
			}

			link_type	insert_and_rebalance(value_type val)
			{
				link_type	header;
				link_type	parent;
				bool		pos;

				header = this->_header;
				parent = this->_header->parent;
				while (header != 0)
				{
					pos = false;
					parent = header;
					if (val.first > header->value.first)
					{
						header = header->right;
						pos = true;
					}
					else
						header = header->left;
				}
				header = this->createNode(val);
				header->parent = parent;
				if (pos)
					header->parent->right = header;
				else
					header->parent->left = header;
				this->_count++;
				if (header->color == red && header->parent->color == red)
					handle_double_red_roation(header);
				return (header);
			}

			void	handle_erase(link_type v)
			{
				link_type	u;
				link_type	parent = v->parent;

				if (v->left != 0 && v->right != 0)
				{
					u = v->right;
					while (u->left != 0)
						u = u->left;
				}
				else if (v->left == 0 && v->right == 0)
					u = 0;
				else if (v->left != 0)
					u = v->left;
				else
					u = v->right;
				if (u == 0)
				{
					if (v == this->_header)
						this->_header = 0;
					else
					{
						if ((u == 0 || u->color == black) && (v->color == black))
							handle_double_black_rotation(v);
						else
						{
							if (v->sibling() != 0)
								v->sibling()->color = red;
						}
						if (v->is_on_left())
							parent->left = 0;
						else if (v->parent != 0)
							parent->right = 0;
					}
					this->_nalloc.deallocate(v, 1);
					this->_count--;
					return;
				}
				if (v->left == 0 || v->right == 0)
				{
					if (v == this->_header)
					{
						this->_nalloc.deallocate(v, 1);
						this->_header = u;
						this->_header->parent = 0;
					}
					else
					{
						if (v->is_on_left())
							parent->left = u;
						else
							parent->right = u;
						this->_nalloc.deallocate(v, 1);
						u->parent = parent;
						if ((u == 0 || u->color == black) && (v->color == black))
							handle_double_black_rotation(u);
						else
							u->color = black;
					}
					this->_count--;
					return;
				}
				this->swapValues(u, v);
				this->handle_erase(u);
			}

			void		handle_dummy_r()
			{
				link_type	tmp;

				tmp = this->_header;
				if (tmp != 0)
				{
					while (tmp->right)
						tmp = tmp->right;
					tmp->right = this->_nalloc.allocate(1);
					this->_palloc.construct(&tmp->right->value, ft::pair<typename T::first_type, typename T::second_type>());
					tmp->right->parent = tmp;
					tmp->right->right = 0;
					tmp->right->left = 0;
				}
			};

			void		delete_dummy()
			{
				if (this->_header != 0)
				{
					link_type	dummy_r;
					dummy_r = this->_header;
					while (dummy_r->right && dummy_r->right->right)
						dummy_r = dummy_r->right;
					if (this->_header == dummy_r && !(dummy_r->right))
					{
						this->_header = 0;
						this->_nalloc.deallocate(dummy_r, 1);
					}
					else
					{
						this->_nalloc.deallocate(dummy_r->right, 1);
						dummy_r->right = 0;
					}
				}
			}
		
		public:

			rb_tree() : _header(0), _count(0)
			{

			};

			rb_tree(const Compare comp, const allocator_type& alloc = allocator_type()) :
					_comp(comp), _header(0), _count(0), _palloc(alloc)
			{

			};

			rb_tree(const rb_tree& tree) : _comp(tree._comp), _count(tree._count), _palloc(tree._palloc)
			{

			};

			~rb_tree()
			{

			};

			rb_tree		&operator=(const rb_tree &tree)
			{
				if (this == &tree)
					return (*this);
				this->_header = tree._header;
				this->_comp = tree._comp;
				this->_count = tree._count;
				this->_nalloc = tree._nalloc;
				this->_palloc = tree._palloc;
				return (*this);
			};

			iterator	insert(value_type val)
			{
				link_type	node;

				if (this->_header == 0)
				{
					this->_header = this->createNode(val);
					this->_header->right = this->_nalloc.allocate(1);
					this->_palloc.construct(&this->_header->right->value, ft::pair<typename T::first_type, typename T::second_type>());
					this->_header->right->parent = this->_header;
					this->_header->right->right = 0;
					this->_header->right->left = 0;
					this->_header->color = black;
					this->_count++;
					node = this->_header;
				}
				else
				{
					delete_dummy();
					node = insert_and_rebalance(val);
					handle_dummy_r();
				}
				return (iterator(node));
			};

			difference_type		erase(value_type val)
			{
				link_type	v = find(val);
				if (v != 0 && v != this->end())
				{
					handle_erase(v);
					if (!this->size())
						this->delete_dummy();
					return (true);
				}
				return false;
			}

			link_type		begin()
			{
				link_type	tmp;

				tmp = this->_header;
				if (!tmp || (!(this->_header->right && this->_header->right != this->end()) && !this->_header->left))
					return (tmp);
				while (tmp->left)
					tmp = tmp->left;
				return (tmp);
			};

			link_type		begin()	const
			{
				link_type	tmp;

				tmp = this->_header;
				if (!tmp || (!(this->_header->right && this->_header->right != this->end()) && !this->_header->left))
					return (tmp);
				while (tmp->left)
					tmp = tmp->left;
				return (tmp);
			};

			link_type		end()
			{
				link_type	tmp;

				tmp = this->_header;
				if (!tmp || (!this->_header->right && !this->_header->left))
					return (tmp);
				if (!this->_header->right && this->_header->left)
					tmp = tmp->left;
				while (tmp->right)
					tmp = tmp->right;
				return (tmp);
			};

			link_type		end()	const
			{
				link_type	tmp;

				tmp = this->_header;
				if (!tmp || (!this->_header->right && !this->_header->left))
					return (tmp);
				if (!this->_header->right && this->_header->left)
					tmp = tmp->left;
				while (tmp->right)
					tmp = tmp->right;
				return (tmp);
			};

			difference_type	empty()	const
			{
				return (this->_count == 0);
			};

			size_type		size()	 const
			{
				return (this->_count);
			};

			size_type		max_size()	const
			{
				return (this->_nalloc->max_size());
			};

			size_type		count(value_type val)	const
			{
				if (this->_header != 0)
				{
					iterator 	it = iterator(this->_header);
					while (it != iterator(this->end()) && (*it).first != val.first)
						it++;
					if ((*it).first == val.first && it != iterator(this->end()))
						return (1);
				}
				return (0);
			};

			link_type		find(value_type val)
			{
				link_type	tmp = this->_header;

				while (tmp != 0)
				{
					if (val.first < tmp->value.first)
					{
						if (tmp->left == 0)
							tmp = 0;
						else
							tmp = tmp->left;
					}
					else if (val.first == tmp->value.first)
						break;
					else
					{
						if (tmp->right == 0)
							tmp = 0;
						else
							tmp = tmp->right;
					}
				}
				if (tmp == 0)
					return (this->end());
				return (tmp);
			}

			link_type		find(value_type val)	const
			{
				link_type	tmp = this->_header;
				while (tmp != 0)
				{
					if (val.first < tmp->value.first)
					{
						if (tmp->left == 0)
							tmp = 0;
						else
							tmp = tmp->left;
					}
					else if (val.first == tmp->value.first)
						break;
					else
					{
						if (tmp->right == 0)
							tmp = 0;
						else
							tmp = tmp->right;
					}
				}
				if (tmp == 0)
					return (this->end());
				return (tmp);
			}
	};
};

#endif