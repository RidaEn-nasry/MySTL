/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:15:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/22 12:06:53 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// create a map of NULL, NULL
// create a map of NULL, data, data, NULL.
#include <test.hpp>

void ft_map_tests_suite()
{

  /******************************************************************************/
  /*                                  Member types                              */
  /******************************************************************************/

  {
    ft::map<int, int> map;
    map.insert(ft::make_pair(1, 1));
    // std::string test_name("ft::map member types tests ");
    // REQUIRE_EQ(typeid(ft::map<int, int>::key_type), typeid(int), test_name, "`key_type` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<int, std::string>::mapped_type), typeid(std::string), test_name, "`mapped_type` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<int, int>::value_type), typeid(ft::pair<const int, int>), test_name, "`value_type` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<int, int>::key_compare), typeid(ft::less<int>), test_name, "`key_compare` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<int, int>::allocator_type), typeid(std::allocator<ft::pair<const int, int> >), test_name, "`allocator_type` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<int, int>::reference), typeid(ft::pair<const int, int> &), test_name, "`reference` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<int, int>::const_reference), typeid(const ft::pair<const int, int> &), test_name, "`const_reference` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<int, int>::pointer), typeid(ft::pair<const int, int> *), test_name, "`pointer` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<int, int>::const_pointer), typeid(const ft::pair<const int, int> *), test_name, "`const_pointer` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<std::vector<char>, std::string>::difference_type), typeid(std::ptrdiff_t), test_name, "`difference_type` member types is missing or invalid");
    // REQUIRE_EQ(typeid(ft::map<std::vector<char>, std::string>::size_type), typeid(std::size_t), test_name, "`size_type` member types is missing or invalid");
    // INFO_OK(test_name);
  }

  /******************************************************************************/
  /*                                  Constructors                               */
  /******************************************************************************/

  {
    // std::string test_name("ft::map constructors tests ");
    
    // // (1) default constructor
    // ft::map<int, int> m1;
    // REQUIRE_EQ(m1.size(), 0, test_name, "`size()` member function should return 0 when map if default constructed");
    // REQUIRE_EQ(m1.empty(), true, test_name, "`empty()` member function should return true when map if default constructed");
    // REQUIRE_EQ(m1.begin(), m1.end(), test_name, "`begin()` and `end()` member functions should return the same iterator when map if default constructed");
    // REQUIRE_EQ(m1.rbegin(), m1.rend(), test_name, "`rbegin()` and `rend()` member functions should return the same iterator when map if default constructed");
    
    // // (2) range constructor 
    // ft::map<int, int> m2(m1.begin(), m1.end());
    // REQUIRE_EQ(m2.size(), 0, test_name, "`size()` member function should return 0 when map if range constructed with empty map");
    // REQUIRE_EQ(m2.empty(), true, test_name, "`empty()` member function should return true when map if range constructed with empty map");
    // REQUIRE_EQ(m2.begin(), m2.end(), test_name, "`begin()` and `end()` member functions should return the same iterator when map if range constructed with empty map");
    // REQUIRE_EQ(m2.rbegin(), m2.rend(), test_name, "`rbegin()` and `rend()` member functions should return the same iterator when map if range constructed with empty map"); 
  
    // m1.insert(ft::make_pair(1, 1));
    // ft::map<int, int> m3(m1.begin(), m1.end());
    // std::cout << m3.size() << std::endl;
    // REQUIRE_EQ(m3.size(), 1, test_name, "`size()` member function should return 1 when map if range constructed with non empty map");
    // REQUIRE_EQ(m3.empty(), false, test_name, "`empty()` member function should return false when map if range constructed with non empty map");
    // REQUIRE_EQ(m3.begin()->first, 1, test_name, "`begin()` member function should return the first element when map if range constructed with non empty map");
    // REQUIRE_EQ(m3.rbegin()->first, 1, test_name, "`rbegin()` member function should return the last element when map if range constructed with non empty map");
    // REQUIRE_EQ(m3.begin()->second, 1, test_name, "`begin()` member function should return the first element when map if range constructed with non empty map");
    // REQUIRE_EQ(m3.rbegin()->second, 1, test_name, "`rbegin()` member function should return the last element when map if range constructed with non empty map");
    
    // INFO_OK(test_name);
  }
}