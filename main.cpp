/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:46:15 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/06 20:39:50 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "incs/vector_tests.hpp"

template <typename T>
void    print_map(T& cont)
{
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << "[" << it->first << "][" << it->second << "] | ";
	std::cout << std::endl;
}

void	vectors_test_int()
{
	std::vector<int>	std_vector;
	ft::vector<int>		ft_vector;
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
	vect_pop_back_one_element_int<std::vector<int> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_pop_back_one_element_int<ft::vector<int> >(ft_vector);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_insert_one_elem_int<std::vector<int> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_insert_one_elem_int<ft::vector<int> >(ft_vector);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_insert_many_elems_int<std::vector<int> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_insert_many_elems_int<ft::vector<int> >(ft_vector);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_insert_range_int<std::vector<int> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_insert_range_int<ft::vector<int> >(ft_vector);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_erase_one_elem_int<std::vector<int> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_erase_one_elem_int<ft::vector<int> >(ft_vector);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_reverse_iterators_and_bracks<std::vector<int> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_reverse_iterators_and_bracks<ft::vector<int> >(ft_vector);
}

void	vectors_test_str()
{
	std::vector<std::string>	std_vector;
	ft::vector<std::string>		ft_vector;
	std::cout << "--------------------VECTORS TEST---------------------" << std::endl;

	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_push_back_one_element<std::vector<std::string>, std::string>(std_vector, "Hello");
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_push_back_one_element<ft::vector<std::string>, std::string>(ft_vector, "Hello world");
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_push_back_many_elements_str<std::vector<std::string> >(std_vector, 1000);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_push_back_many_elements_str<ft::vector<std::string> >(ft_vector, 1000);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_push_back_many_elements_str<std::vector<std::string> >(std_vector, 100000);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_push_back_many_elements_str<ft::vector<std::string> >(ft_vector, 100000);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_pop_back_one_element_str<std::vector<std::string> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_pop_back_one_element_str<ft::vector<std::string> >(ft_vector);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_insert_one_elem_str<std::vector<std::string> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_insert_one_elem_str<ft::vector<std::string> >(ft_vector);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_insert_many_elems_str<std::vector<std::string> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_insert_many_elems_str<ft::vector<std::string> >(ft_vector);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_insert_range_str<std::vector<std::string> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_insert_range_str<ft::vector<std::string> >(ft_vector);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vect_erase_one_elem_str<std::vector<std::string> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vect_erase_one_elem_str<ft::vector<std::string> >(ft_vector);
}

int     main()
{
	std::map<int, std::string>  std_map;
	ft::map<int, std::string>   ft_map;

	srand((unsigned int)time(0));
	std::cout << "================FT_CONTAINERS TESTER=================" << std::endl;
	vectors_test_int();
	vectors_test_str();
	return (0);
}
