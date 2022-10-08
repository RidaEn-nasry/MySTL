/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:48:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/08 16:43:55 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/* associative container that contains a sorted set of key-value pairs,       */
/* with unique keys. the sorting criteria is defined by the Compare class,    */
/* which defaults to less<Key>.                                               */
/* map is allocator-aware, and reversible.                                    */
/*****************************************************************************/

namespace ft {

#include <less.hpp>
#include <memory>
#include <pair.hpp>

#ifndef MAP_HPP
#define MAP_HPP

  template < class key, class T, class Compare = ft::less<key>, class Alloc = std::allocator<ft::pair<const key, T> > >
  class map {

  }; // map class


  
#endif
}; // ft namespace

