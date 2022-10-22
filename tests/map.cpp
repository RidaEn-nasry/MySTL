/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:15:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/21 21:50:45 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.hpp>


void ft_map_tests_suite() {



  // let's see
  ft::map<int, int> map;
  
  map.insert(ft::pair<int, int>(1, 1));
  // map[1] = 1; 
  INFO_OK("ft::map let's see ");
}