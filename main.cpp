/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:46:15 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/21 16:51:29 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/vector.hpp"
#include "incs/map.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>

template <typename T>
void    print_vector(T& cont)
{
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << "[" << *it << "] | ";
	std::cout << std::endl;
}

template <class Container, class T>
void vect_push_back_one_element(Container c, T toInsert)
{
	std::cout << "push_back one element:" << toInsert << std::endl;
	int start_s = clock();
	c.push_back(toInsert);
	int stop_s = clock();
	std::cout << "vector content : " << std::endl;
	print_vector(c);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void vect_push_back_many_elements_int(Container c, int number)
{
	std::cout << "push_back " << number << " elements" << std::endl;
	int start_s = clock();
	for (int i = 0; i < number; i++)
		c.push_back(rand() % 1000);
	int stop_s = clock();
	std::cout << "size after push_back: " << c.size() << std::endl;
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void vect_pop_back_one_element(Container c)
{
	std::cout << "pop_back one element" << std::endl;
	c.push_back(42);
	c.push_back(10);
	std::cout << "vector content before pop_back : " << std::endl;
	print_vector(c);
	int start_s = clock();
	c.pop_back();
	int stop_s = clock();
	std::cout << "vector content after pop_back: " << std::endl;
	print_vector(c);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

void	insert_one_elem_int()
{
	
}

template <typename T>
void    print_map(T& cont)
{
	for (typename T::const_iterator it = cont.beg in(); it != cont.end(); ++it)
		std::cout << "[" << it->first << "][" << it->second << "] | ";
	std::cout << std::endl;
}

void    vectors_test_int()
{
	std::vector<int>    std_vector;
	ft::vector<int>     ft_vector;
	std::cout << "--------------------VECTORS TEST---------------------" << std::endl;

	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_push_back_one_element<std::vector<int>, int>(std_vector, 42);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_push_back_one_element<ft::vector<int>, int>(ft_vector, 42);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_push_back_many_elements_int<std::vector<int> >(std_vector, 100);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_push_back_many_elements_int<ft::vector<int> >(ft_vector, 100);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_push_back_many_elements_int<std::vector<int> >(std_vector, 100000);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_push_back_many_elements_int<ft::vector<int> >(ft_vector, 100000);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_pop_back_one_element<std::vector<int> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_pop_back_one_element<ft::vector<int> >(ft_vector);
}

int     main()
{
	std::map<int, std::string>  std_map;
	ft::map<int, std::string>   ft_map;

	srand((unsigned int)time(0));
	std::cout << "================FT_CONTAINERS TESTER=================" << std::endl;
	vectors_test_int();


	return (0);
}