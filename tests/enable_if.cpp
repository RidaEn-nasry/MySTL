/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:42:52 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/06 12:20:25 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// testing enable_if
#include <test.hpp>
void ft_enabe_if_tests_suite() {


  char* test_name = strdup("enable_if tests ");
  /**** testing enable_if ****/
  {
    ft::enable_if<true, int>::type a = 1;
    ft::enable_if<false, int>::type b = 1;
    REQUIRE_EQ(a, 1, test_name, "enable_if<true, int>::type should be int");
    REQUIRE_EQ(b, 1, test_name, "enable_if<false, int>::type should be int");

    // RUN_TEST(a == 1, test_name, "enable_if<true, int>::type a = 1");


    // REQUIRE_STREQ(typeid(ft::enable_if<true, int>::type).name(), typeid(int).name(), test_name, "enable_if<true, int>::type should be of type int");
  }

  INFO_OK(test_name);

}
