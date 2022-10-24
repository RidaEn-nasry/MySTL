/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:21:47 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/24 20:48:07 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "test.hpp"

void ft_equal_tests_suite() {

    /*** default ***/
    {

        std::string test_name("ft::equal tests (1) default ");
        ft::vector<int> a(10);
        ft::vector<int> b(10);
        for (size_t i = 0; i < a.capacity(); i++)
        {
            a[i] = i;
            b[i] = i;
        }

        REQUIRE_EQ(ft::equal(a.begin(), a.end(), b.begin()), true, test_name, "equal should return true if the two sequences are equal");
        a[5] = 4;
        REQUIRE_EQ(ft::equal(a.begin(), a.end(), b.begin()), false, test_name, "equal should return false if the two sequences are not equal");
        INFO_OK(test_name);
        //sleep(1);
    }

    /*** predicate ***/
    {

        
        std::string test_name("ft::equal tests (2) predicate ");
        ft::vector<int> a(10);
        ft::vector<int> b(10);

        for (size_t i = 0; i < a.capacity(); i++)
        {
            a[i] = i;
            b[i] = i;
        }

        REQUIRE_EQ(ft::equal(a.begin(), a.end(), b.begin(), std::equal_to<int>()), true, test_name, "equal should return true if the two sequences are equal");
        a[5] = 4;
        REQUIRE_EQ(ft::equal(a.begin(), a.end(), b.begin(), std::equal_to<int>()), false, test_name, "equal should return false if the two sequences are not equal");
        INFO_OK(test_name);
        //sleep(1);
    }
    
};