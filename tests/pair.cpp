/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:31:19 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/08 18:23:05 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <test.hpp>

void ft_pair_tests_suite() {

  /* ************************************************************************** */
  /*                           Member types                                     */
  /* ************************************************************************** */

  {
    std::string test_name("ft::pair member types ");
    ft::pair<int, char>::first_type a = 1;
    ft::pair<int, char>::second_type b = 'a';
    REQUIRE_STREQ(typeid(a).name(), typeid(int).name(), test_name, "first_type should be of type int");
    REQUIRE_STREQ(typeid(b).name(), typeid(char).name(), test_name, "second_type should be of type char");
    INFO_OK(test_name);
  }

  /* ************************************************************************** */
  /*                           Member functions                                 */
  /* ************************************************************************** */

  {

    // constructors
    // default constructor
    {
      std::string test_name("ft::pair constructors ");
      ft::pair<int, char> two;
      REQUIRE_EQ(two.first, 0, test_name, "default constructor should initialize first to `T1()` `T2()`");
      REQUIRE_EQ(two.second, 0, test_name, "default constructor should initialize second to `T1()` `T2()`");
      // constructor with value
      ft::pair<int, char> a(1, 'a');
      REQUIRE_EQ(a.first, 1, test_name, "initialization constructor  should initialize first to value, `T1(value)`");
      REQUIRE_EQ(a.second, 'a', test_name, "initialization constructor should initialize second to value, `T2(value)`");

      // copy constructor
      ft::pair<int, char> b(a);
      REQUIRE_EQ(b.first, 1, test_name, "copy constructor should initialize first to other.first, `T1(other.first)`");
      REQUIRE_EQ(b.second, 'a', test_name, "copy constructor should initialize second to other.second, `T2(other.second)`");

      // operator=
      ft::pair<int, char> c;
      c = a;
      REQUIRE_EQ(c.first, 1, test_name, "operator= should initialize first to other.first, `first = other.first`");
      REQUIRE_EQ(c.second, 'a', test_name, "operator= should initialize second to other.second, `second = other.second`");
      INFO_OK(test_name);
    }
    // free(test_name);
  // relational operators
    {
      std::string test_name("ft::pair relational operators ");
      ft::pair<int, char> a(1, 'a');
      ft::pair<int, char> b(1, 'a');
      ft::pair<int, char> c(2, 'a');

      REQUIRE_EQ(a, b, test_name, "operator== should return true if both `first` and `second` are equal");
      REQUIRE_NEQ(a, c, test_name, "operator!= should return false if both `first` and `second` are equal");
      REQUIRE_GT(c, a, test_name, "operator> should return true if `first` is greater than `first` of other");
      REQUIRE_LT(a, c, test_name, "operator< should return true if `first` is less than `first` of other");

      REQUIRE_GE(a, b, test_name, "operator>= should return true if `first` is greater than `first` of other");
      REQUIRE_LE(a, b, test_name, "operator<= should return true if `first` is less than `first` of other");
      INFO_OK(test_name);
    }


  }



}


