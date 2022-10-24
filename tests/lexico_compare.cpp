/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexico_compare.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:48:04 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/24 20:47:38 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void ft_lexico_compare_tests_suite()
{
    /**************************************************/
    /*              default                            */
    /**************************************************/

    {
        std::string test_name("ft::lexicographical_compare tests (1) default ");
        ft::vector<int> a(10);
        ft::vector<int> b(10);
        for (size_t i = 0; i < a.capacity(); i++)
        {
            a[i] = i;
            b[i] = i;
        }
        REQUIRE_EQ(ft::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()), false, test_name, "lexicographical_compare should return false if the two sequences are equal");
        a[5] = 4;
        REQUIRE_EQ(ft::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()), true, test_name, "lexicographical_compare should return true if the first sequence is less than the second");
        INFO_OK(test_name);
        //sleep(1);
    };
    
    /*********************************************************/
    /*              custom predicate                         */
    /*********************************************************/
    
    {
        
        std::string test_name("ft::lexicographical_compare tests (2) custom predicate ");
        ft::vector<int> a(10);
        ft::vector<int> b(10);
        for (size_t i = 0; i < a.capacity(); i++)
        {
            a[i] = i;
            b[i] = i;
        }
        REQUIRE_EQ(ft::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), ft::less<int>()), false, test_name, "lexicographical_compare should return false if the two sequences are equal");
        a[5] = 4;
        REQUIRE_EQ(ft::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), ft::less<int>()), true, test_name, "lexicographical_compare should return true if the first sequence is less than the second");
        INFO_OK(test_name);
        //sleep(1);
    };

};