/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:21:26 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/08 18:44:16 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TESTS_HPP
# define STACK_TESTS_HPP

#include "stack.hpp"
#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>

template <class Container, class T>
void	stack_push(Container c, T first, T second, T third)
{
	std::cout << "push three elements:" << first << " " << second << " " << third << std::endl;
	int start_s = clock();
	c.push(first);
	c.push(second);
	c.push(third);
	int stop_s = clock();
	std::cout << "Stack content : " << std::endl;
	while (c.size() > 0)
	{
		std::cout << c.top() << " |";
		c.pop();
	}
	std::cout << std::endl;
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	stack_pop_int(Container c)
{
	std::cout << "pop_back one element" << std::endl;
	c.push(42);
	c.push(10);
	Container   tmp = c;
	std::cout << "stack content before pop : " << std::endl;
	while (c.size() > 0)
	{
		std::cout << c.top() << " |";
		c.pop();
	}
	std::cout << std::endl;
	int start_s = clock();
	tmp.pop();
	int stop_s = clock();
	std::cout << "vector content after pop_back: " << std::endl;
	while (tmp.size() > 0)
	{
		std::cout << tmp.top() << " |";
		tmp.pop();
	}
	std::cout << std::endl;
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	stack_pop_str(Container c)
{
	std::cout << "pop_back one element" << std::endl;
	c.push("Hello");
	c.push("Can you hear me!");
	Container   tmp = c;
	std::cout << "stack content before pop : " << std::endl;
	while (c.size() > 0)
	{
		std::cout << c.top() << " |";
		c.pop();
	}
	std::cout << std::endl;
	int start_s = clock();
	tmp.pop();
	int stop_s = clock();
	std::cout << "stack content after pop_back: " << std::endl;
	while (tmp.size() > 0)
	{
		std::cout << tmp.top() << " |";
		tmp.pop();
	}
	std::cout << std::endl;
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	stack_non_member_operators(Container c)
{
	c.push(10);
	c.push(42);
	c.push(44);
	Container	tmp = c;
	
	std::cout << "Test when container 1 == container 2" << std::endl;
	std::cout << "container 1 != container 2 : " << (c != tmp) << std::endl;
	std::cout << "container 1 == container 2 : " << (c == tmp) << std::endl;
	std::cout << "container 1 <= container 2 : " << (c <= tmp) << std::endl;
	std::cout << "container 1 < container 2 : " << (c < tmp) << std::endl;
	std::cout << "container 1 >= container 2 : " << (c >= tmp) << std::endl;
	std::cout << "container 1 > container 2 : " << (c > tmp) << std::endl;
	c.push(2);
	std::cout << "Test when container 1 > container 2" << std::endl;
	std::cout << "container 1 != container 2 : " << (c != tmp) << std::endl;
	std::cout << "container 1 == container 2 : " << (c == tmp) << std::endl;
	std::cout << "container 1 <= container 2 : " << (c <= tmp) << std::endl;
	std::cout << "container 1 < container 2 : " << (c < tmp) << std::endl;
	std::cout << "container 1 >= container 2 : " << (c >= tmp) << std::endl;
	std::cout << "container 1 > container 2 : " << (c > tmp) << std::endl;
	c.pop();
	c.pop();
	std::cout << "Test when container 1 < container 2" << std::endl;
	std::cout << "container 1 != container 2 : " << (c != tmp) << std::endl;
	std::cout << "container 1 == container 2 : " << (c == tmp) << std::endl;
	std::cout << "container 1 <= container 2 : " << (c <= tmp) << std::endl;
	std::cout << "container 1 < container 2 : " << (c < tmp) << std::endl;
	std::cout << "container 1 >= container 2 : " << (c >= tmp) << std::endl;
	std::cout << "container 1 > container 2 : " << (c > tmp) << std::endl;
}

#endif