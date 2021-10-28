/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:46:15 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/10/27 13:03:06 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/vector.hpp"
#include "incs/map.hpp"
# include "incs/stl_tree.hpp"
#include <iostream>
#include <vector>
#include <map>

template <typename T>
void    vectorTest_Resize(T& cont)
{
    std::string name("resize:");
    std::cout << "\n---------------------";

    T tmp = cont;

	std::cout << "size of tmp = " << tmp.size();

    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();

    tmp.resize(3, *x);
	std::cout << "size of tmp after resize = " << tmp.size();
        
    delete x;
}

template <typename T>
void    vectorTest_AssignNElem(T& cont)
{
    std::string name("assign n elems:");
    std::cout << "\n---------------------";

    T tmp = cont;
	std::cout << "size of tmp = " << tmp.size();

    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();
        
    tmp.resize(3, *x);

    T tmp2 = cont;
    tmp2.assign(tmp.size(), tmp.front());

	std::cout << "size after assign = " << tmp2.size();
        
    delete x;
}

template <typename T>
void    vectorTest_PushBack(T& cont)
{
    //std::string name("push_back:");
    //std::cout << "\n---------------------";
        
    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();
    T tmp = cont;
    tmp.push_back(*x);
	for(ft::vector<int>::const_iterator it = tmp.begin(); it != tmp.end(); it++)
		std::cout << *it << " | " ;
    delete x;
}

template <typename T>
void    vectorTest_AssignRange(T& cont)
{
    std::string name("assign iterator range:");
    std::cout << "\n---------------------";

    T tmp = cont;
    std::cout << "size of tmp = " << tmp.size();

    // Allows to value initialize (case size is 0, we can't assign cont.front())
    typename T::value_type* x = new typename T::value_type ();
    if (cont.size())
        *x = cont.front();

    T tmp2 = cont;
    tmp.resize(3, *x);
    tmp2.assign(tmp.begin(), tmp.end());

	std::cout << "size after assign = " << tmp2.size();

    delete x;
}

template <typename T>
inline void printMapContainer(T& cont)
{
    for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
        std::cout << "[" << it->first << "][" << it->second << "] | ";
}

int     main()
{
    /*
	ft::vector<int> v;

	v.push_back(10);
	v.push_back(20);

	//ft::vector<int> v1(v.begin(), v.end());

	ft::vector<int> v2(2, 100);

	std::vector<int> v3(3, 100);
	
	ft::vector<int> v4;
	std::cout<< v[0] << " " << v[1] << std::endl;
	//std::cout<< v1[0] << " " << v1[1] << std::endl;
	std::cout<< v2[0] << " " << v2[1] << std::endl;
	std::cout << v2.size() << " " << v3.size() << std::endl;
	vectorTest_Resize(v4);
	v4.clear();
	//vectorTest_AssignNElem(v4);
	//vectorTest_AssignRange(v4);
	v4.push_back(10);
	v4.push_back(20);
    std::cout << std::endl;
    std::cout << v4.size() << std::endl;
	vectorTest_PushBack(v4);
    */

    ft::map<int, std::string> map1;
    std::map<int, std::string> map2;
    ft::rb_tree<ft::pair<int, std::string>, ft::less<int> > tree;
    int arr[] = {1,4,6,3,5,7,8,2,9};
    for(int i=0;i<9;i++)
    {
        ft::pair<int, std::string> p(arr[i], "aaaa");
        map1.insert(p);
        //tree.insert(p);

        //map2.insert(p);
        std::cout << std::endl;
        //map1.inorderTraversal();
    }
    //ft::map<int, std::string> map3(++map1.begin(), map1.end());
    //map3.insert(--map3.end(), *map1.begin());
    printMapContainer(map1);
    //printMapContainer(map3);
    //map1.printTree();
	return (0);
}