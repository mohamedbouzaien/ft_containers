/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:46:15 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/08 21:49:19 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "incs/vector_tests.hpp"
# include "incs/stack_tests.hpp"
# include "incs/map_tests.hpp"

void	map_tests()
{
	std::map<int, int>			std_map_int;
	std::map<int, std::string>	std_map_str;
	ft::map<int, int>			ft_map_int;
	ft::map<int, std::string>	ft_map_str;

	ft_map_int.insert(ft::make_pair<int, int>(10, 42));
	ft_map_int.insert(ft::make_pair<int, int>(2, -42));
	ft_map_int.insert(ft::make_pair<int, int>(52, 2555));
	ft_map_int.insert(ft::make_pair<int, int>(100, 800));
	std_map_int.insert(std::make_pair<int, int>(10, 42));
	std_map_int.insert(std::make_pair<int, int>(2, -42));
	std_map_int.insert(std::make_pair<int, int>(52, 2555));
	std_map_int.insert(std::make_pair<int, int>(100, 800));
	ft_map_str.insert(ft::make_pair<int, std::string>(10, "Hello"));
	ft_map_str.insert(ft::make_pair<int, std::string>(2, "is it me"));
	ft_map_str.insert(ft::make_pair<int, std::string>(52, "you re looking for!"));
	ft_map_str.insert(ft::make_pair<int, std::string>(100, "i can see it in your eyes!"));
	std_map_str.insert(std::make_pair<int, std::string>(10, "Hello"));
	std_map_str.insert(std::make_pair<int, std::string>(2, "is it me"));
	std_map_str.insert(std::make_pair<int, std::string>(52, "you re looking for!"));
	std_map_str.insert(std::make_pair<int, std::string>(100, "i can see it in your eyes!"));

	ft::pair<int, int>			ft_first_int(52, 2555);
	ft::pair<int, int>			ft_second_int(-5, 8000);
	ft::pair<int, std::string>	ft_first_str(52, "you re looking for!");
	ft::pair<int, std::string>	ft_second_str(-5, "i can see it in your smile!");
	std::pair<int, int>			std_first_int(52, 2555);
	std::pair<int, int>			std_second_int(-5, 8000);
	std::pair<int, std::string>	std_first_str(52, "you re looking for!");
	std::pair<int, std::string>	std_second_str(-5, "i can see it in your smile!");

	std::cout << "---------------------MAP TEST------------------------" << std::endl;

	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	map_insert_one_elem_int<std::map<int, int>, std::pair<int, int> >(std_map_int, std_first_int, std_second_int);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	map_insert_one_elem_int<ft::map<int, int>, ft::pair<int, int> >(ft_map_int, ft_first_int, ft_second_int);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	map_insert_one_elem_str<std::map<int, std::string>, std::pair<int, std::string> >(std_map_str, std_first_str, std_second_str);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	map_insert_one_elem_str<ft::map<int, std::string>, ft::pair<int, std::string> >(ft_map_str, ft_first_str, ft_second_str);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	map_insert_range_int<std::map<int, int> >(std_map_int);	
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	map_insert_range_int<ft::map<int, int> >(ft_map_int);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	map_insert_range_str<std::map<int, std::string> >(std_map_str);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	map_insert_range_str<ft::map<int, std::string> >(ft_map_str);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	map_erase_range_int<std::map<int, int> >(std_map_int);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	map_erase_range_int<ft::map<int, int> >(ft_map_int);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	map_erase_range_str<std::map<int, int> >(std_map_int);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	map_erase_range_str<ft::map<int, int> >(ft_map_int);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	map_erase_one_elem_int<std::map<int, int>, std::pair<int, int> >(std_map_int, std_first_int);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	map_erase_one_elem_int<ft::map<int, int>, ft::pair<int, int> >(ft_map_int, ft_first_int);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	map_erase_one_elem_str<std::map<int, std::string>, std::pair<int, std::string> >(std_map_str, std_first_str);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	map_erase_one_elem_str<ft::map<int, std::string>, ft::pair<int, std::string> >(ft_map_str, ft_first_str);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	map_reverse_iterators_and_bracks<std::map<int, int> >(std_map_int);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	map_reverse_iterators_and_bracks<ft::map<int, int> >(ft_map_int);
}

void	stack_tests()
{
	std::stack<int>			std_stack_int;
	std::stack<std::string>	std_stack_str;
	ft::stack<int>			ft_stack_int;
	ft::stack<std::string>	ft_stack_str;
	std::cout << "---------------------STACK TEST----------------------" << std::endl;

	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	stack_push<std::stack<int>, int>(std_stack_int, 10, 20, 42);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	stack_push<ft::stack<int>, int>(ft_stack_int, 10, 20, 42);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	stack_push<std::stack<std::string>, std::string>(std_stack_str, "Hola", "Habibi", "Miao");
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	stack_push<ft::stack<std::string>, std::string>(ft_stack_str, "Hola", "Habibi", "Miao");
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	stack_pop_int<std::stack<int> >(std_stack_int);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	stack_pop_int<ft::stack<int> >(ft_stack_int);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	stack_pop_int<std::stack<int> >(std_stack_int);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	stack_pop_int<ft::stack<int> >(ft_stack_int);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	stack_pop_str<std::stack<std::string> >(std_stack_str);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	stack_pop_str<ft::stack<std::string> >(ft_stack_str);
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	stack_non_member_operators<std::stack<int> >(std_stack_int);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	stack_non_member_operators<ft::stack<int> >(ft_stack_int);
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
	std::cout << "+++++++++++++++++++++++STD+++++++++++++++++++++++++++" << std::endl;
	vector_non_member_operators<std::vector<int> >(std_vector);
	std::cout << "+++++++++++++++++++++++FT++++++++++++++++++++++++++++" << std::endl;
	vector_non_member_operators<ft::vector<int> >(ft_vector);
}

void	vectors_test_str()
{
	std::vector<std::string>	std_vector;
	ft::vector<std::string>		ft_vector;

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
	srand((unsigned int)time(0));
	std::cout << "================FT_CONTAINERS TESTER=================" << std::endl;
	vectors_test_int();
	vectors_test_str();
	stack_tests();
	map_tests();
	return (0);
}
