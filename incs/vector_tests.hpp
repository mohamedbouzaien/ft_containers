/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:14:56 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/06 21:09:00 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
# define VECTOR_TESTS_HPP

#include "vector.hpp"
#include "map.hpp"
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
void vect_push_back_many_elements_str(Container c, int number)
{
	std::cout << "push_back " << number << " elements" << std::endl;
	int start_s = clock();
	for (int i = 0; i < number; i++)
		c.push_back("Cozy");
	int stop_s = clock();
	std::cout << "size after push_back: " << c.size() << std::endl;
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void vect_pop_back_one_element_int(Container c)
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

template <class Container>
void vect_pop_back_one_element_str(Container c)
{
	std::cout << "pop_back one element" << std::endl;
	c.push_back("So now we pop back");
	c.push_back("Yalla lets do it");
	std::cout << "vector content before pop_back : " << std::endl;
	print_vector(c);
	int start_s = clock();
	c.pop_back();
	int stop_s = clock();
	std::cout << "vector content after pop_back: " << std::endl;
	print_vector(c);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_insert_one_elem_int(Container c)
{
	c.push_back(42);
	c.push_back(10);
	c.push_back(63);
	c.push_back(24);
	std::cout << "Vector elements before insert:" << std::endl;
	print_vector(c);
	Container tmp = c;
	typename Container::iterator	it = tmp.begin();
	std::cout << "insert one elem at the beginning" << std::endl;
	int start_s = clock();
	tmp.insert(it, 30);
	int stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	it = tmp1.end();
	std::cout << "insert one elem at the end" << std::endl;
	start_s = clock();
	tmp1.insert(it, 30);
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp1);
		std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp2 = c;
	it = tmp2.begin()++;
	std::cout << "insert one elem in the middle" << std::endl;
	start_s = clock();
	tmp2.insert(it, 30);
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp2);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_insert_one_elem_str(Container c)
{
	c.push_back("Bonjour");
	c.push_back("Je suis le Bonheur");
	c.push_back("Quand le code marche bien");
	c.push_back("Je pete");
	std::cout << "Vector elements before insert:" << std::endl;
	print_vector(c);
	Container tmp = c;
	std::cout << "insert one elem at the beginning" << std::endl;
	int start_s = clock();
	typename Container::iterator	it = tmp.begin();
	tmp.insert(it, "LOL");
	int stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	it = tmp1.end();
	std::cout << "insert one elem at the end" << std::endl;
	start_s = clock();
	tmp1.insert(it, "LOL");
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp1);
		std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp2 = c;
	it = tmp2.begin()++;
	std::cout << "insert one elem in the middle" << std::endl;
	start_s = clock();
	tmp2.insert(it, "LOL");
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp2);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_insert_many_elems_int(Container c)
{
	c.push_back(42);
	c.push_back(10);
	c.push_back(63);
	c.push_back(24);
	std::cout << "Vector elements before insert:" << std::endl;
	print_vector(c);
	Container tmp = c;
	typename Container::iterator	it = tmp.begin();
	std::cout << "insert 5 elems at the beginning" << std::endl;
	int start_s = clock();
	tmp.insert(it, 5, 30);
	int stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	it = tmp1.end();
	std::cout << "insert 5 elems at the end" << std::endl;
	start_s = clock();
	tmp1.insert(it, 5, 30);
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp1);
		std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp2 = c;
	it = tmp2.begin()++;
	std::cout << "insert 5 elems in the middle" << std::endl;
	start_s = clock();
	tmp2.insert(it, 5, 30);
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp2);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_insert_many_elems_str(Container c)
{
	c.push_back("Bonjour");
	c.push_back("Je suis le Bonheur");
	c.push_back("Quand le code marche bien");
	c.push_back("Je pete");
	std::cout << "Vector elements before insert:" << std::endl;
	print_vector(c);
	Container tmp = c;
	typename Container::iterator	it = tmp.begin();
	std::cout << "insert 5 elems at the beginning" << std::endl;
	int start_s = clock();
	tmp.insert(it, 5, "LOL");
	int stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	it = tmp1.end();
	std::cout << "insert 5 elems at the end" << std::endl;
	start_s = clock();
	tmp1.insert(it, 5, "LOL");
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp1);
		std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp2 = c;
	it = tmp2.begin()++;
	std::cout << "insert 5 elems in the middle" << std::endl;
	start_s = clock();
	tmp2.insert(it, 5, "LOL");
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp2);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_insert_range_int(Container c)
{
	c.push_back(42);
	c.push_back(10);
	c.push_back(23);
	c.push_back(-10);
	std::cout << "Vector elements before insert:" << std::endl;
	print_vector(c);
	Container tmp = c;
	std::cout << "Reinsert table elements in it using insert with iterators range at beginning:" << std::endl;
	typename Container::iterator	it = tmp.begin();
	int start_s = clock();
	tmp.insert(it, c.begin(), c.end());
	int stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	it = tmp1.end();
	std::cout << "Reinsert table elements in it using insert with iterators range at end:" << std::endl;
	start_s = clock();
	tmp1.insert(it, c.begin(), c.end());
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp1);
		std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp2 = c;
	it = tmp2.begin()++;
	std::cout << "Reinsert table elements in it using insert with iterators range in the middle:" << std::endl;
	start_s = clock();
	tmp2.insert(it, c.begin(), c.end());
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp2);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_insert_range_str(Container c)
{
	c.push_back("Bonjour");
	c.push_back("Je suis le Bonheur");
	c.push_back("Quand le code marche bien");
	c.push_back("Je pete");
	std::cout << "Vector elements before insert:" << std::endl;
	print_vector(c);
	Container tmp = c;
	std::cout << "Reinsert table elements in it using insert with iterators range at beginning:" << std::endl;
	typename Container::iterator	it = tmp.begin();
	int start_s = clock();
	tmp.insert(it, c.begin(), c.end());
	int stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	it = tmp1.end();
	std::cout << "Reinsert table elements in it using insert with iterators range at end:" << std::endl;
	start_s = clock();
	tmp1.insert(it, c.begin(), c.end());
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp1);
		std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp2 = c;
	it = tmp2.begin() + 2;
	std::cout << "Reinsert table elements in it using insert with iterators range in the middle:" << std::endl;
	start_s = clock();
	tmp2.insert(it, c.begin(), c.end());
	stop_s = clock();
	std::cout << "Vector elements after insert:" << std::endl;
	print_vector(tmp2);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_erase_range_str(Container c)
{
	c.push_back("Bonjour");
	c.push_back("Je suis le Bonheur");
	c.push_back("Quand le code marche bien");
	c.push_back("Je pete");
	std::cout << "Vector elements before erase:" << std::endl;
	print_vector(c);
	Container tmp = c;
	std::cout << "Erase all elements:" << std::endl;
	int start_s = clock();
	tmp.erase(tmp.begin(), tmp.end());
	int stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	std::cout << "Erase one element in the beginning:" << std::endl;
	start_s = clock();
	tmp1.erase(tmp.begin(), tmp.begin()++);
	stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp1);
		std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp2 = c;
	std::cout << "Erase one element at the end:" << std::endl;
	start_s = clock();
	tmp2.erase(c.end()--, c.end());
	stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp2);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_erase_range_int(Container c)
{
	c.push_back(10);
	c.push_back(42);
	c.push_back(-20);
	c.push_back(101);
	std::cout << "Vector elements before erase:" << std::endl;
	print_vector(c);
	Container tmp = c;
	std::cout << "Erase all elements:" << std::endl;
	int start_s = clock();
	tmp.erase(tmp.begin(), tmp.end());
	int stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	std::cout << "Erase one element in the beginning:" << std::endl;
	start_s = clock();
	tmp.erase(tmp.begin(), tmp.begin()++);
	stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	std::cout << "Erase one element at the end:" << std::endl;
	start_s = clock();
	tmp.erase(tmp.end());
	stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_erase_one_elem_str(Container c)
{
	c.push_back("Bonjour");
	c.push_back("Je suis le Bonheur");
	c.push_back("Quand le code marche bien");
	c.push_back("Je pete");
	std::cout << "Vector elements before erase:" << std::endl;
	print_vector(c);
	Container tmp = c;
	std::cout << "Erase one element in the beginning:" << std::endl;
	int	start_s = clock();
	tmp.erase(tmp.begin());
	int	stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	std::cout << "Erase one element at the end:" << std::endl;
	start_s = clock();
	tmp1.erase(--tmp1.end());
	stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp1);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_erase_one_elem_int(Container c)
{
	c.push_back(10);
	c.push_back(42);
	c.push_back(-20);
	c.push_back(101);
	std::cout << "Vector elements before insert:" << std::endl;
	print_vector(c);
	Container tmp = c;
	std::cout << "Erase one element in the beginning:" << std::endl;
	int	start_s = clock();
	tmp.erase(tmp.begin());
	int	stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
	Container tmp1 = c;
	std::cout << "Erase one element at the end:" << std::endl;
	start_s = clock();
	tmp1.erase(--tmp1.end());
	stop_s = clock();
	std::cout << "Vector elements after erase:" << std::endl;
	print_vector(tmp1);
	std::cout << "execution time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

template <class Container>
void	vect_reverse_iterators_and_bracks(Container c)
{
	c.push_back(10);
	c.push_back(42);
	c.push_back(-20);
	c.push_back(101);
	std::cout << "Showing vectors content using reverse iterator: " << std::endl;
	for (typename Container::reverse_iterator it = c.rbegin(); it != c.rend(); ++it)
		std::cout << *it << " |";
	std:: cout << std::endl;
	std::cout << "Showing vectors content using brackets: " << std::endl;
	for (typename Container::size_type i = 0; i < c.size(); i++)
		std::cout << c[i] << " |";
	std:: cout << std::endl;
}

#endif