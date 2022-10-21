/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_type.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:00:37 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/21 09:55:59 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHOOSE_TYPE_HPP
#define CHOOSE_TYPE_HPP

namespace ft {
  

  template <bool Cond, class T, class U>
  struct choose_type {};

  template <class T, class U>
  struct choose_type<true, T, U> {
    typedef T type;
  };

  template <class T, class U>
  struct choose_type<false, T, U> {
    typedef U type;
  };
}

  #endif