/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:42:45 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/02 23:50:03 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




namespace ft {
#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

  template <class T>
  struct is_integral {

	/******************** member types ********************/
    typedef T value_type;
   
	/********************* member constants **********************/
    static const bool value = false;

	/********************* member functions **********************/
	operator bool() const { return value; };

	
	
  };
  
#endif
} // namespace ft
