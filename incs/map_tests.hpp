/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:50:10 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/15 21:54:59 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_TESTS_HPP
# define MAP_TESTS_HPP

#include "map.hpp"
#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>

template <typename T>
void    print_map(T& cont)
{
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << "[" << it->first << "][" << it->second << "] | ";
	std::cout << std::endl;
}

template <class Container, class Pair>
void	map_insert_one_elem_int(Container c, Pair first, Pair second)
{
	std::cout << "Map elements before insert:" << std::endl;
	print_map(c);
	Container tmp = c;
	std::cout << "insert one elem that exits" << std::endl;
	int start_s = clock();
	c.insert(first);
	int stop_s = clock();
	std::cout << "Map elements after insert:" << std::endl;
	print_map(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	std::cout << "insert new element: " << std::endl;
	start_s = clock();
	c.insert(second);
	stop_s = clock();
	std::cout << "Map elements after insert:" << std::endl;
	print_map(tmp1);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container, class Pair>
void	map_insert_one_elem_str(Container c, Pair first, Pair second)
{
	std::cout << "Map elements before insert:" << std::endl;
	print_map(c);
	Container tmp = c;
	std::cout << "insert one elem that exits" << std::endl;
	int start_s = clock();
	c.insert(first);
	int stop_s = clock();
	std::cout << "Map elements after insert:" << std::endl;
	print_map(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	std::cout << "insert new element: " << std::endl;
	start_s = clock();
	c.insert(second);
	stop_s = clock();
	std::cout << "Map elements after insert:" << std::endl;
	print_map(tmp1);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	map_insert_range_int(Container c)
{
	std::cout << "Map elements before insert:" << std::endl;
	print_map(c);
	Container tmp = c;
	std::cout << "Reinsert map elements in an other map using insert with iterators range at beginning:" << std::endl;
	int start_s = clock();
	tmp.insert(c.begin(), c.end());
	int stop_s = clock();
	std::cout << "map elements after insert:" << std::endl;
	print_map(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	map_insert_range_str(Container c)
{
	std::cout << "Map elements before insert:" << std::endl;
	print_map(c);
	Container tmp = c;
	std::cout << "Reinsert map elements in an other map using insert with iterators range at beginning:" << std::endl;
	int start_s = clock();
	tmp.insert(c.begin(), c.end());
	int stop_s = clock();
	std::cout << "map elements after insert:" << std::endl;
	print_map(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	map_erase_range_str(Container c)
{
	std::cout << "Map elements before erase:" << std::endl;
	print_map(c);
	Container tmp = c;
	std::cout << "Erase all elements:" << std::endl;
	int start_s = clock();
	tmp.erase(tmp.begin(), tmp.end());
	int stop_s = clock();
	std::cout << "Map elements after erase:" << std::endl;
	print_map(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	std::cout << "Erase one element in the beginning:" << std::endl;
	start_s = clock();
	tmp1.erase(tmp1.begin(), tmp1.begin()++);
	stop_s = clock();
	std::cout << "Map elements after erase:" << std::endl;
	print_map(tmp1);
		std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp2 = c;
	std::cout << "Erase one element at the end:" << std::endl;
	start_s = clock();
	tmp2.erase(tmp2.end()--, tmp2.end());
	stop_s = clock();
	std::cout << "Map elements after erase:" << std::endl;
	print_map(tmp2);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	map_erase_range_int(Container c)
{
	std::cout << "Map elements before erase:" << std::endl;
	print_map(c);
	Container tmp = c;
	std::cout << "Erase all elements:" << std::endl;
	int start_s = clock();
	tmp.erase(tmp.begin(), tmp.end());
	int stop_s = clock();
	std::cout << "Map elements after erase:" << std::endl;
	print_map(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	std::cout << "Erase one element in the beginning:" << std::endl;
	start_s = clock();
	tmp1.erase(tmp1.begin(), tmp1.begin()++);
	stop_s = clock();
	std::cout << "Map elements after erase:" << std::endl;
	print_map(tmp1);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp2 = c;
	std::cout << "Erase one element at the end:" << std::endl;
	start_s = clock();
	tmp2.erase(tmp2.end()--, tmp2.end());
	stop_s = clock();
	std::cout << "Map elements after erase:" << std::endl;
	print_map(tmp2);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container, class Pair>
void	map_erase_one_elem_str(Container c, Pair pair)
{
	std::cout << "Map elements before erase:" << std::endl;
	print_map(c);
	Container tmp1 = c;
	std::cout << "Erase one element" << std::endl;
	int	start_s = clock();
	tmp1.erase(pair.first);
	int	stop_s = clock();
	std::cout << "Map elements after erase:" << std::endl;
	print_map(tmp1);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container, class Pair>
void	map_erase_one_elem_int(Container c, Pair pair)
{
	std::cout << "Map elements before erase:" << std::endl;
	print_map(c);
	Container tmp1 = c;
	std::cout << "Erase one element:" << std::endl;
	int	start_s = clock();
	tmp1.erase(pair.first);
	int	stop_s = clock();
	std::cout << "Map elements after erase:" << std::endl;
	print_map(tmp1);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	map_reverse_iterators_and_bracks(Container c)
{
	std::cout << "Showing maps content using reverse iterator: " << std::endl;
	for (typename Container::reverse_iterator it = c.rbegin(); it != c.rend(); ++it)
		std::cout << "[" << it->first << "][" << it->second << "] | ";
	std:: cout << std::endl;
	std::cout << "Showing content using brackets: " << std::endl;
	std::cout << "[" << c[2] << "] | " << std::endl;
	std::cout << "Showing unknown content (3) using brackets: " << std::endl;
	std::cout << "[" << c[3] << "] | " << std::endl;
	std::cout << "map elements after that" << std::endl;
	print_map(c); 
}

#endif
