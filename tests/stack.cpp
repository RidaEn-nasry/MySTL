/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:55:26 by ren-nasr         	 #+#   #+#            */
/*   Updated: 2022/10/02 18:55:26 by ren-nasr          	 ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */



#include <test.hpp>


void ft_stack_tests_suite() {


  /*****************************************************************************/
  /*                   Member types test                                      */
  /*****************************************************************************/

  {
    char* test_name = strdup("stack: default member types test");

    // stack using vector as underlying container
    ft::stack<int> ft_stack;
    // getting values
    ft::stack<int>::container_type ft_container;
    ft::stack<int>::size_type ft_size;
    ft::stack<int>::value_type ft_value;

    REQUIRE_STREQ(typeid(ft_container).name(), typeid(ft::vector<int>).name(), test_name, "`ft::stack` should use `ft::vector` as default container");
    REQUIRE_STREQ(typeid(ft_size).name(), typeid(size_t).name(), test_name, "`ft::stack` should use `size_t` as default size type");
    REQUIRE_STREQ(typeid(ft_value).name(), typeid(int).name(), test_name, "`ft::stack` should use `T` as default value type");
    INFO_OK(test_name);
  }

  /*****************************************************************************/
  /*                   Member functions test                                   */
  /****************************************************************************/

  {
    char* test_name = strdup("stack: member functions test");

    ft::stack<std::string> ft_stack;

    // empty
    REQUIRE(ft_stack.empty(), test_name, "empty() should return true if the stack is empty");
    ft_stack.push("hello");
    REQUIRE(!ft_stack.empty(), test_name, "empty() should return false if the stack is not empty");
    ft_stack.pop();
    REQUIRE(ft_stack.empty(), test_name, "empty() should return true if the stack is empty");

    // size
    REQUIRE_EQ(ft_stack.size(), (size_t)0, test_name, "size() should return 0 if the stack is empty");
    ft_stack.push("hello");
    REQUIRE_EQ(ft_stack.size(), (size_t)1, test_name, "size() should return `size` if the stack is not empty");

    // top
    ft_stack.push("world");
    REQUIRE_STREQ(ft_stack.top().c_str(), "world", test_name, "top() should return the top element of the stack");
    ft_stack.pop();
    REQUIRE_STREQ(ft_stack.top().c_str(), "hello", test_name, "top() should return the top element of the stack");

    // const top  
    const ft::stack<int> ft_stack_const;
    REQUIRE_STREQ(typeid(ft_stack_const.top()).name(), typeid(int).name(), test_name, "top() should return the top element of the stack");



    // push
    ft_stack.push("world");
    REQUIRE_STREQ(ft_stack.top().c_str(), "world", test_name, "push() should add an element to the top of the stack");
    ft_stack.push("!");
    REQUIRE_STREQ(ft_stack.top().c_str(), "!", test_name, "push() should add an element to the top of the stack");


    // pop
    ft_stack.pop();
    REQUIRE_STREQ(ft_stack.top().c_str(), "world", test_name, "pop() should remove the top element of the stack");
    ft_stack.pop();
    REQUIRE_STREQ(ft_stack.top().c_str(), "hello", test_name, "pop() should remove the top element of the stack");
    ft_stack.pop();
    REQUIRE(ft_stack.empty(), test_name, "pop() should remove the top element of the stack");

    INFO_OK(test_name);
  }

};