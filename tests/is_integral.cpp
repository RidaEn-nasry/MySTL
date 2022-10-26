/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:11:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/25 12:18:02 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "test.hpp"


void ft_is_integral_tests_suite() {
    
    {
        
        std::string test_name("ft::is_integral tests ");
        
        REQUIRE_EQ(ft::is_integral<int>::value, true, test_name, "is_integral<int>::value should be true");
        REQUIRE_EQ(ft::is_integral<float>::value, false, test_name, "is_integral<float>::value should be false");
        REQUIRE_EQ(ft::is_integral<char>::value, true, test_name, "is_integral<char>::value should be true");
        REQUIRE_EQ(ft::is_integral<char*>::value, false, test_name, "is_integral<char*>::value should be false");
        REQUIRE_EQ(ft::is_integral<std::string>::value, false, test_name, "is_integral<std::string>::value should be false");
        REQUIRE_EQ(ft::is_integral<std::string*>::value, false, test_name, "is_integral<std::string*>::value should be false");
        REQUIRE_EQ(ft::is_integral<std::string&>::value, false, test_name, "is_integral<std::string&>::value should be false");
        REQUIRE_EQ(ft::is_integral<bool>::value, true, test_name, "is_integral<bool>::value should be true");
        REQUIRE_EQ(ft::is_integral<short>::value, true, test_name, "is_integral<short>::value should be true");
        REQUIRE_EQ(ft::is_integral<long>::value, true, test_name, "is_integral<long>::value should be true");
        // wcahr_t char16_t char32_t
        REQUIRE_EQ(ft::is_integral<wchar_t>::value, true, test_name, "is_integral<wchar_t>::value should be true");
        REQUIRE_EQ(ft::is_integral<char16_t>::value, true, test_name, "is_integral<char16_t>::value should be true");
        REQUIRE_EQ(ft::is_integral<char32_t>::value, true, test_name, "is_integral<char32_t>::value should be true");
        REQUIRE_EQ(ft::is_integral<unsigned int>::value, true, test_name, "is_integral<unsigned int>::value should be true");
        // signed char, long long , unsigned char , unsigend shor int, unsigned int, unsigedn long long int,
        REQUIRE_EQ(ft::is_integral<signed char>::value, true, test_name, "is_integral<signed char>::value should be true");
        REQUIRE_EQ(ft::is_integral<long long>::value, true, test_name, "is_integral<long long>::value should be true");
        REQUIRE_EQ(ft::is_integral<unsigned char>::value, true, test_name, "is_integral<unsigned char>::value should be true");
        REQUIRE_EQ(ft::is_integral<unsigned short int>::value, true, test_name, "is_integral<unsigned short int>::value should be true");
        REQUIRE_EQ(ft::is_integral<unsigned int>::value, true, test_name, "is_integral<unsigned int>::value should be true");
        REQUIRE_EQ(ft::is_integral<unsigned long long int>::value, true, test_name, "is_integral<unsigned long long int>::value should be true");
        INFO_OK(test_name);
        sleep(1);
    }

};
