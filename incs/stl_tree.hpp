/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:27:11 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/10/16 14:34:32 by mbouzaie         ###   ########.fr       */
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
		rb_color	color;
		link_type	parent;
		link_type	left;
		link_type	right;
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
			typedef	ptrdiff_t			difference_type;
			typedef	node<T>*			link_type;
			base_pointer	_node;

			rb_tree_iterator() : _node(0)
			{
				
			};

			rb_tree_iterator(pointer node) : _node(node)
			{

			};

			rb_tree_iterator(rb_tree_iterator const &copy) : _node(copy._node)
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
			typedef	ptrdiff_t			difference_type;
			typedef	node<T>*			link_type;
			base_pointer	_node;
			
			rb_tree_const_iterator() : _node(0)
			{
				
			};

			rb_tree_const_iterator(pointer node) : _node(node)
			{

			};

			rb_tree_const_iterator(rb_tree_const_iterator const &copy) : _node(copy._node)
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
			
			difference_type			operator==(const rb_tree_const_iterator &rhs)	const
			{
				return (this->_node == rhs._node);
			};

			difference_type			operator!=(const rb_tree_const_iterator &rhs)	const
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
			node_allocator	_alloc;
			bool			_left_left;
			bool			_right_right;
			bool			_right_left;
			bool			_left_right;

			link_type	createNode(const_reference val)
			{
				link_type	new_node;

				new_node = _alloc.allocate(1);
				new_node->color = red;
				new_node->value = val;
				new_node->parent = 0;
				new_node->right = 0;
				new_node->left = 0;
				return (new_node);
			};

			link_type	rotate_left(link_type	node)
			{
				link_type	x;
				link_type	y;

				x = node->right;
				y = node->left;
				x->left = node;
				node->right = y;
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

			link_type	handle_roation(link_type node)
			{
				if (node->parent->right == node)
				{
					if (node->parent->left == 0 || node->parent->left->color == black)
					{
						if (node->left != 0 && node->left->color == red)
							_right_left = true;
						else if (node->right != 0 && node->right->color == red)
							_left_left = true;
				
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
							_right_right = true;
						else if (node->right != 0 && node->right->color == red)
							_left_right = true;
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

			link_type	insert_and_rebalance(link_type header, const_reference val)
			{
				bool	rotate;

				rotate = false;
				if (header == 0)
				{
					header = this->createNode(val);
					this->_count++;
					return (header);
				}
				if (val > header->value)
				{
					header->right = insert_and_rebalance(header->right, val);
					header->right->parent = header;
					if (header != this->_header)
						if (header->color == red && header->right->color == red)
							rotate = true;
				}
				else
				{
					header->left = insert_and_rebalance(header->left, val);
					header->left->parent = header;
					if (header != this->_header)
						if (header->color == red && header->left->color == red)
							rotate = true;
				}
				if (_left_left)
				{
					header = left_left_rotation(header);
					_left_left = false;
				}
				else if (_right_right)
				{
					header = right_right_rotation(header);
					_right_right = false;
				}
				else if (_right_left)
				{
					header = right_left_rotation(header);
					_right_left = false;
				}
				else if (_left_right)
				{
					header = left_right_rotation(header);
					_left_right = false;
				}
				if (rotate)
				{
					header =  handle_roation(header);
				}
				return (header);
			};
		
		public:

			rb_tree() : _header(0), _count(0), _left_left(false), _right_right(false), _right_left(false), _left_right(false)
			{

			};

			rb_tree(const Compare& comp) : _comp(comp), _header(0), _count(0)
			{

			};

			rb_tree(const Compare comp, const allocator_type& alloc) :
					_comp(comp), _alloc(alloc), _header(0), _count(0)
			{

			};

			rb_tree(const rb_tree& tree) : _alloc(tree._alloc), _comp(tree), _count(tree._count)
			{

			};

			~rb_tree()
			{

			};

			rb_tree		&operator=(const rb_tree &tree)
			{
				return (tree);
			};

			iterator	insert(const_reference val)
			{
				if (this->_header == 0)
				{
					this->_header = this->createNode(val);
					this->_header->color = black;
				}
				else
					this->_header = insert_and_rebalance(this->_header, val);
				return (iterator(this->_header));
			};

			link_type		getHeader()
			{
				return (this->_header);
			};

			link_type		begin()
			{
				return (this->_header->parent);
			};

			const_link_type	begin()		const
			{
				return (this->_header->parent);
			}

			link_type		end()
			{
				return (this->_header);
			};

			const_link_type	end()	const
			{
				return (this->_header);
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
				return (this->_alloc->max_size());
			};
//ALL CONTENT HERE IS COPIED FOR TESTS
			 // helper function to print inorder traversal
			void inorderTraversalHelper(link_type n)
			{
				if(n != 0)
				{
					inorderTraversalHelper(n->left);
					std::cout << n->value;
					inorderTraversalHelper(n->right);
				}
			}
			//function to print inorder traversal
			void inorderTraversal()
			{
				inorderTraversalHelper(this->_header);
			}
			// helper function to print the tree.
			void printTreeHelper(link_type root, int space)
			{
				int i;
				if(root != 0)
				{
					space = space + 10;
					printTreeHelper(root->right, space);
					std::cout << std::endl;
					for ( i = 10; i < space; i++)
					{
						std::cout << " ";
					}
					std::cout << root->value;
					std::cout << std::endl;
					printTreeHelper(root->left, space);
				}
			}
			// function to print the tree.
			void printTree()
			{
				printTreeHelper(this->_header, 4);
			}
	};
};

#endif