/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:42:52 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/24 20:48:11 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// testing enable_if
#include <test.hpp>
void ft_enable_if_tests_suite()
{

  /**** testing enable_if ****/
  {
    std::string test_name("ft::enable_if tests ");
    ft::enable_if<true, int>::type a = 1;
    REQUIRE_EQ(a, 1, test_name, "enable_if<true, int>::type should be int");
    REQUIRE_STREQ(typeid(ft::enable_if<true, int>::type).name(), typeid(int).name(), test_name, "enable_if<true, int>::type should be of type int");
    INFO_OK(test_name);
    //sleep(1);
  }
}
