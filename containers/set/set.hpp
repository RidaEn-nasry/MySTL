/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:07:39 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/24 16:52:45 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SET_HPP
#define SET_HPP


#include <memory>
#include <less.hpp>


namespace ft {
  template <class key, class Compare = ft::less<key>, class Alloc = std::allocator<key> >
  class set {
      
  };
}

#endif
