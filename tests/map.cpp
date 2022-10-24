/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:15:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/24 15:19:07 by ren-nasr         ###   ########.fr       */
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

    std::string test_name("ft::map member types tests ");
    REQUIRE_EQ(typeid(ft::map<int, int>::key_type), typeid(int), test_name, "`key_type` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<int, std::string>::mapped_type), typeid(std::string), test_name, "`mapped_type` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<int, int>::value_type), typeid(ft::pair<const int, int>), test_name, "`value_type` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<int, int>::key_compare), typeid(ft::less<int>), test_name, "`key_compare` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<int, int>::allocator_type), typeid(std::allocator<ft::pair<const int, int> >), test_name, "`allocator_type` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<int, int>::reference), typeid(ft::pair<const int, int> &), test_name, "`reference` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<int, int>::const_reference), typeid(const ft::pair<const int, int> &), test_name, "`const_reference` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<int, int>::pointer), typeid(ft::pair<const int, int> *), test_name, "`pointer` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<int, int>::const_pointer), typeid(const ft::pair<const int, int> *), test_name, "`const_pointer` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<std::vector<char>, std::string>::difference_type), typeid(std::ptrdiff_t), test_name, "`difference_type` member types is missing or invalid");
    REQUIRE_EQ(typeid(ft::map<std::vector<char>, std::string>::size_type), typeid(std::size_t), test_name, "`size_type` member types is missing or invalid");
    INFO_OK(test_name);
  }

  /******************************************************************************/
  /*                                  Constructors                               */
  /******************************************************************************/

  {
    std::string test_name("ft::map constructors tests ");

    // // (1) default constructor
    ft::map<int, int> m1;
    REQUIRE_EQ(m1.size(), 0, test_name, "`size()` member function should return 0 when map if default constructed");
    REQUIRE_EQ(m1.empty(), true, test_name, "`empty()` member function should return true when map if default constructed");
    REQUIRE_EQ(m1.begin(), m1.end(), test_name, "`begin()` and `end()` member functions should return the same iterator when map if default constructed");
    REQUIRE_EQ(m1.rbegin(), m1.rend(), test_name, "`rbegin()` and `rend()` member functions should return the same iterator when map if default constructed");

    // (2) range constructor 
    ft::map<int, int> m2(m1.begin(), m1.end());
    REQUIRE_EQ(m2.size(), 0, test_name, "`size()` member function should return 0 when map if range constructed with empty map");
    REQUIRE_EQ(m2.empty(), true, test_name, "`empty()` member function should return true when map if range constructed with empty map");
    REQUIRE_EQ(m2.begin(), m2.end(), test_name, "`begin()` and `end()` member functions should return the same iterator when map if range constructed with empty map");
    REQUIRE_EQ(m2.rbegin(), m2.rend(), test_name, "`rbegin()` and `rend()` member functions should return the same iterator when map if range constructed with empty map");

    m1.insert(ft::make_pair(1, 1));
    ft::map<int, int> m3(m1.begin(), m1.end());

    // std::cout << m3.size() << std::endl;
    REQUIRE_EQ(m3.size(), 1, test_name, "`size()` member function should return > 0 when map if range constructed with non empty map");
    REQUIRE_EQ(m3.empty(), false, test_name, "`empty()` member function should return false when map if range constructed with non empty map");
    REQUIRE_EQ(m3.begin()->first, 1, test_name, "`begin()` member function should return the first element when map if range constructed with non empty map");
    REQUIRE_EQ(m3.begin()->second, 1, test_name, "`begin()` member function should return the first element when map if range constructed with non empty map");


    // (3) copy constructor
    m1.insert(ft::make_pair(2, 2));
    m1.insert(ft::make_pair(3, 3));
    ft::map<int, int> m4(m1);
    REQUIRE_EQ(m4.size(), m1.size(), test_name, "`size()` member function should return the same value as it's copy ctor");
    ft::map<int, int>::iterator it = m1.begin();
    ft::map<int, int>::iterator ite = m1.end();
    ft::map<int, int>::iterator itm = m4.begin();
    ft::map<int, int>::iterator itme = m4.end();
    while (it != ite && itm != itme)
    {
      REQUIRE_EQ(it->first, itm->first, test_name, "copy constructor should copy all elements");
      REQUIRE_EQ(it->second, itm->second, test_name, "copy constructor should copy all elements");
      ++it;
      ++itm;
    };


    // copy assignment operator
    ft::map<int, int> m5;
    m5 = m1;
    REQUIRE_EQ(m5.size(), m1.size(), test_name, "`size()` member function should return the same value as it's copy ctor");
    it = m1.begin();
    ite = m1.end();
    itm = m5.begin();
    itme = m5.end();
    while (it != ite && itm != itme)
    {
      REQUIRE_EQ(it->first, itm->first, test_name, "copy assignment operator should copy all elements");
      REQUIRE_EQ(it->second, itm->second, test_name, "copy assignment operator should copy all elements");
      ++it;
      ++itm;
    };
    // get allocator 
    ft::map<int, int>::allocator_type a = m5.get_allocator();
    REQUIRE_EQ(a, m5.get_allocator(), test_name, "`get_allocator()` member function should return the same value as it's copy ctor");

    INFO_OK(test_name);
  }


  /******************************************************************************/
  /*                                  Iterators                                 */
  /******************************************************************************/

  {
    std::string test_name("ft::map iterators tests ");

    ft::map<int, int> m1;
    srand(time(NULL));
    for (int i = 0; i < 100; ++i)
    {
      m1.insert(ft::make_pair(i, rand()));
    }
    ft::map<int, int>::iterator it = m1.begin();
    ft::map<int, int>::iterator ite = m1.end();
    REQUIRE_EQ(it->first, 0, test_name, "`begin()` member function should return the first element");
    REQUIRE_EQ((++it)->first, 1, test_name, "`++it` member function should return the next element");
    REQUIRE_EQ((--it)->first, 0, test_name, "`--it` member function should return the previous element");
    REQUIRE_EQ((it++)->first, 0, test_name, "`it++` member function should return the current element");
    REQUIRE_EQ((it--)->first, 1, test_name, "`it--` member function should return the current element");
    for (int i = 0; i < 100; ++i)
    {
      REQUIRE_EQ(it->first, i, test_name, "`it->first` member function should return the current element");
      ++it;
    }
    INFO_OK(test_name);
  }


  /******************************************************************************/
  /*                                  Capacity                                  */
  /******************************************************************************/

  {
    std::string test_name("ft::map capacity member functions tests ");
    ft::map<int, int> m1;
    REQUIRE_EQ(m1.empty(), true, test_name, "`empty()` member function should return true when map is empty");
    REQUIRE_EQ(m1.size(), 0, test_name, "`size()` member function should return 0 when map is empty");
    m1.insert(ft::make_pair(1, 1));
    REQUIRE_EQ(m1.empty(), false, test_name, "`empty()` member function should return false when map is not empty");
    REQUIRE_EQ(m1.size(), 1, test_name, "`size()` member function should return > 0 when map is not empty");
    for (int i = 0; i < 100; ++i)
    {
      m1.insert(ft::make_pair(i, rand()));
    }
    REQUIRE_EQ(m1.size(), 100, test_name, "`size()` member function should return > 0 when map is not empty");
    ft::map<int, int>::size_type max_size = m1.get_allocator().max_size();
    REQUIRE_EQ(max_size, m1.max_size(), test_name, "`max_size()` member function should return the same value as std::map");
    INFO_OK(test_name);
  }

  /******************************************************************************/
  /*                                  Modifiers                                 */
  /******************************************************************************/
  {
    std::string test_name("ft::map modifiers member functions tests ");
    ft::map<int, int> m1;


    // insert with single element 
    ft::pair<ft::map<int, int>::iterator, bool> ret = m1.insert(ft::make_pair(1, 1));
    REQUIRE_EQ(ret.second, true, test_name, "`insert()` member function should return true when inserting a new element");
    REQUIRE_EQ(ret.first->first, 1, test_name, "`insert()` member function should return an iterator to the inserted element");
    REQUIRE_EQ(ret.first->second, 1, test_name, "`insert()` member function should return an iterator to the inserted element");
    ret = m1.insert(ft::make_pair(1, 1));
    REQUIRE_EQ(ret.second, false, test_name, "`insert()` member function should return false when inserting an existing element");
    REQUIRE_EQ(ret.first->first, 1, test_name, "`insert()` member function should return an iterator to the existing element");
    REQUIRE_EQ(ret.first->second, 1, test_name, "`insert()` member function should return an iterator to the existing element");
    for (int i = 0; i < 100; ++i)
    {
      m1.insert(ft::make_pair(i, rand()));
    }
    REQUIRE_EQ(m1.size(), 100, test_name, "`size()` member function should return > 0 when map is not empty");
    // ft::map<int, int>::iterator it = m1.begin();
    // ft::map<int, int>::iterator ite = m1.end();
    ft::map<int, int> m3;
    ft::map<int, int>::iterator it = m3.begin();
    ft::map<int, int>::iterator ite = m3.end();

    std::map<int, int> m2;
    for (int i = 0; i < 100; ++i)
    {
      m2.insert(std::make_pair(i, rand()));
    }
    std::map<int, int>::iterator it2 = m2.begin();
    std::map<int, int>::iterator ite2 = m2.end();
    while (it != ite && it2 != ite2)
    {
      REQUIRE_EQ(it->first, it2->first, test_name, "`insert()` member function should insert all elements");
      REQUIRE_EQ(it->second, it2->second, test_name, "`insert()` member function should insert all elements");
      ++it;
      ++it2;
    };


    // insert with range
    ft::map<int, int> m4;
    std::map<int, int> m5;
    m5.insert(m2.begin(), m2.end());
    m4.insert(m1.begin(), m1.end());

    // m4.insert(m1.begin(), m1.end());
    REQUIRE_EQ(m4.size(), m5.size(), test_name, "`insert()` member function should insert all elements");
    it = m4.begin();
    ite = m4.end();
    for (int i = 0; i < 100; ++i)
    {
      REQUIRE_EQ(it->first, i, test_name, "`insert()` member function should insert all elements");
      ++it;
    }

    // insert with hint
    // work for later  

    // erase with single element
    m4.erase(1);
    m5.erase(1);
    REQUIRE_EQ(m4.size(), m5.size(), test_name, "`erase()` member function should erase the element");
    it = m4.begin();
    ite = m4.end();
    REQUIRE_NEQ(it->first, 1, test_name, "`erase()` member function should erase the element");
    for (int i = 0; i < 100; ++i)
    {
      m4.erase(i);
      m5.erase(i);
    }
    REQUIRE_EQ(m4.size(), m5.size(), test_name, "`erase()` member function should erase all elements");
    REQUIRE_EQ(m4.empty(), m5.empty(), test_name, "`erase()` member function should erase all elements");

    // erase with iterator
    ft::map<int, int> m6;
    std::map<int, int> m7;
    for (int i = 0; i < 100; ++i)
    {
      m6.insert(ft::make_pair(i, rand()));
      m7.insert(std::make_pair(i, rand()));
    }
    it = m6.begin();
    ite = m6.end();
    it2 = m7.begin();
    ite2 = m7.end();
    m7.erase(m7.begin(), m7.end());
    m6.erase(m6.begin(), m6.end());
    REQUIRE_EQ(m6.size(), m7.size(), test_name, "`erase()` member function should erase all elements");
    REQUIRE_EQ(m6.empty(), m7.empty(), test_name, "`erase()` member function should erase all elements");

    // erase with range
    for (int i = 0; i < 100; ++i)
    {
      m6.insert(ft::make_pair(i, rand()));
      m7.insert(std::make_pair(i, rand()));
    }
    it = m6.begin();
    ite = m6.end();
    it2 = m7.begin();
    ite2 = m7.end();
    m7.erase(m7.begin(), m7.end());
    m6.erase(m6.begin(), m6.end());
    REQUIRE_EQ(m6.size(), m7.size(), test_name, "`erase()` member function should erase all elements");
    REQUIRE_EQ(m6.empty(), m7.empty(), test_name, "`erase()` member function should erase all elements");


    // clear
    for (int i = 0; i < 100; ++i)
    {
      m6.insert(ft::make_pair(i, rand()));
      m7.insert(std::make_pair(i, rand()));
    }
    m6.clear();
    m7.clear();
    REQUIRE_EQ(m6.size(), m7.size(), test_name, "`clear()` member function should clear the map");
    REQUIRE_EQ(m6.empty(), m7.empty(), test_name, "`clear()` member function should clear the map");

    // swap
    m6.swap(m4);
    m7.swap(m5);
    REQUIRE_EQ(m6.size(), m7.size(), test_name, "`swap()` member function should swap the map");
    REQUIRE_EQ(m6.empty(), m7.empty(), test_name, "`swap()` member function should swap the map");
    REQUIRE_EQ(m4.size(), m5.size(), test_name, "`swap()` member function should swap the map");
    REQUIRE_EQ(m4.empty(), m5.empty(), test_name, "`swap()` member function should swap the map");

    INFO_OK(test_name);
  }

  /* ************************************************************************** */
  /*                                    Lookup                                  */
  /* ************************************************************************** */

  {
    std::string test_name("ft::map lookup member functions test ");
    ft::map<int, int> m1;
    for (int i = 0; i < 100; ++i)
    {
      m1.insert(ft::make_pair(i, rand()));
    }
    ft::map<int, int>::iterator it = m1.begin();
    ft::map<int, int>::iterator ite = m1.end();
    // count 
    REQUIRE_EQ(m1.count(1), 1, test_name, "`count()` member function should return 1 if the element is found");
    REQUIRE_EQ(m1.count(100), 0, test_name, "`count()` member function should return 0 if the element is not found");


    // find 
    REQUIRE_EQ(m1.find(5)->first, 5, test_name, "`find()` member function should return the iterator to the element if found");
    REQUIRE_EQ(m1.find(100), ite, test_name, "`find()` member function should return the iterator to the end if not found");

    // lower_bound 
    REQUIRE_EQ(m1.lower_bound(31)->first, 31, test_name, "`lower_bound()` member function should return the iterator to the element if found");
    REQUIRE_EQ(m1.lower_bound(100), ite, test_name, "`lower_bound()` member function should return the iterator to the end if not found");


    // upper_bound
    REQUIRE_EQ(m1.upper_bound(31)->first, 32, test_name, "`upper_bound()` member function should return the iterator to the element if found");
    REQUIRE_EQ(m1.upper_bound(100), ite, test_name, "`upper_bound()` member function should return the iterator to the end if not found");

    // equal_range
    ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> p1 = m1.equal_range(31);
    ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> p2 = m1.equal_range(1);
    REQUIRE_EQ(p1.first->first, 31, test_name, "`equal_range()` member function should return the iterator to the element if found");
    REQUIRE_EQ(p1.second->first, 32, test_name, "`equal_range()` member function should return the iterator to the element if found");
    REQUIRE_EQ(p2.first->first, 1, test_name, "`equal_range()` member function should return the iterator to the element if found");
    REQUIRE_EQ(p2.second->first, 2, test_name, "`equal_range()` member function should return the iterator to the element if found");

    INFO_OK(test_name);
  }

  /* ************************************************************************** */
  /*                                       Element access                       */
  /* ************************************************************************** */
  {
    std::string test_name("ft::map element access member functions test ");
    ft::map<int, int> m1;
    // // operator[]
    for (int i = 0; i < 100; ++i)
    {
      m1[i] = i;
    }
    for (int i = 0; i < 100; ++i)
    {
      REQUIRE_EQ(m1[i], i, test_name, "`operator[]` member function should return the value of the element if found");
    }
    REQUIRE_EQ(m1[1], 1, test_name, "`operator[]` member function should return the value of the element if found");
    REQUIRE_EQ(m1[100], 0, test_name, "`operator[]` member function should return the value of the element if found");


    // at 
    for (int i = 0; i < 100; ++i)
    {
      m1.at(i) = i;
    }
    for (int i = 0; i < 100; ++i)
    {
      REQUIRE_EQ(m1.at(i), i, test_name, "`at()` member function should return the value of the element if found");
    }
    try
    {
      m1.at(100);
    }
    catch (std::exception& e)
    {
      REQUIRE_EQ(1, 1, test_name, "`at()` member function should throw an exception if the element is not found");
    }
    catch (...)
    {
      REQUIRE_EQ(1, 0, test_name, "`at()` member function should throw an exception if the element is not found");
    }

    INFO_OK(test_name);
  }

  /* ************************************************************************** */
  /*                                       Observers                            */
  /* ************************************************************************** */
  {

    //key compare
    std::string test_name("ft::map observers member functions test ");
    ft::map<int, int, ft::less<int> > m1;
    REQUIRE_EQ(typeid(m1.key_comp()), typeid(ft::less<int>), test_name, "`key_comp()` member function should return the key comparison object");
    ft::map<int, char, std::greater<int> > m2;
    REQUIRE_EQ(typeid(m2.key_comp()), typeid(std::greater<int>), test_name, "`key_comp()` member function should return the key comparison object");

    // value compare
    ft::map<int, int> m3;
    ft::map<int, int>::value_compare vc = m3.value_comp();
    ft::pair<int, int> p1(1, 1);
    ft::pair<int, int> p2(2, 2);
    REQUIRE_EQ(vc(p1, p2), true, test_name, "`value_comp()` member function should return the value comparison object");
    REQUIRE_EQ(vc(p2, p1), false, test_name, "`value_comp()` member function should return the value comparison object");
    REQUIRE_EQ(vc(p1, p1), false, test_name, "`value_comp()` member function should return the value comparison object");
    REQUIRE_EQ(vc(p2, p2), false, test_name, "`value_comp()` member function should return the value comparison object");

    INFO_OK(test_name);
  }
  /* ************************************************************************** */
  /*                             non-member functions                           */
  /*****************************************************************************/
  {
    std::string test_name("ft::map non-member functions test ");
    ft::map<int, int> m1;
    ft::map<int, int> m2;


    for (int i = 0; i < 100; ++i)
    {
      m1[i] = i;
      m2[i] = i;
    }
    // operator==
    REQUIRE_EQ(m1 == m2, true, test_name, "`operator==` non-member function should return true if the two maps are equal");
    m1[1] = 2;
    REQUIRE_EQ(m1 == m2, false, test_name, "`operator==` non-member function should return false if the two maps are not equal");
    m1[1] = 1;
    REQUIRE_EQ(m1 == m2, true, test_name, "`operator==` non-member function should return true if the two maps are equal");

    // operator!=
    REQUIRE_EQ(m1 != m2, false, test_name, "`operator!=` non-member function should return false if the two maps are equal");
    m1[1] = 2;
    REQUIRE_EQ(m1 != m2, true, test_name, "`operator!=` non-member function should return true if the two maps are not equal");
    m1[1] = 1;
    REQUIRE_EQ(m1 != m2, false, test_name, "`operator!=` non-member function should return false if the two maps are equal");

    // operator<
    REQUIRE_EQ(m1 < m2, false, test_name, "`operator<` non-member function should return false if the first map is not less than the second map");
    m1[1] = 0;
    REQUIRE_EQ(m1 < m2, true, test_name, "`operator<` non-member function should return true if the first map is less than the second map");
    m1[1] = 1;
    REQUIRE_EQ(m1 < m2, false, test_name, "`operator<` non-member function should return false if the first map is not less than the second map");

    // operator<=
    REQUIRE_EQ(m1 <= m2, true, test_name, "`operator<=` non-member function should return true if the first map is less than or equal to the second map");
    m1[1] = 0;
    REQUIRE_EQ(m1 <= m2, true, test_name, "`operator<=` non-member function should return true if the first map is less than or equal to the second map");
    m1[1] = 1;
    REQUIRE_EQ(m1 <= m2, true, test_name, "`operator<=` non-member function should return true if the first map is less than or equal to the second map");

    // operator>
    REQUIRE_EQ(m1 > m2, false, test_name, "`operator>` non-member function should return false if the first map is not greater than the second map");
    m1[1] = 2;
    REQUIRE_EQ(m1 > m2, true, test_name, "`operator>` non-member function should return true if the first map is greater than the second map");
    m1[1] = 1;
    REQUIRE_EQ(m1 > m2, false, test_name, "`operator>` non-member function should return false if the first map is not greater than the second map");

    // operator>=
    REQUIRE_EQ(m1 >= m2, true, test_name, "`operator>=` non-member function should return true if the first map is greater than or equal to the second map");
    m1[1] = 2;
    REQUIRE_EQ(m1 >= m2, true, test_name, "`operator>=` non-member function should return true if the first map is greater than or equal to the second map");
    m1[1] = 1;
    REQUIRE_EQ(m1 >= m2, true, test_name, "`operator>=` non-member function should return true if the first map is greater than or equal to the second map");

    // swap non-member function
    ft::map<int, int> m3;
    ft::map<int, int> m4;
    for (int i = 0; i < 100; ++i)
    {
      m3[i] = i;
      m4[i] = i + 1;
    }
    ft::swap(m3, m4);
    for (int i = 0; i < 100; ++i)
    {
      REQUIRE_EQ(m3[i], i + 1, test_name, "`swap` non-member function should swap the contents of the two maps");
      REQUIRE_EQ(m4[i], i, test_name, "`swap` non-member function should swap the contents of the two maps");
    }
    INFO_OK(test_name);
  }
}