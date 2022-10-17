/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:48:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/17 17:40:41 by ren-nasr         ###   ########.fr       */
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
#include <choose_type.hpp>
#include <reverse_iterator.hpp>
#include <avl.hpp>

#ifndef MAP_HPP
#define MAP_HPP

  template < class key, class T, class Compare = ft::less<key>, class Alloc = std::allocator<ft::pair<const key, T> > >
  class map {
  public:
    /************** Member types **************/
    // key type
    typedef key key_type;
    // mapped type
    typedef T mapped_type;
    // value type
    typedef ft::pair<const key, T> value_type;
    // size type
    typedef std::size_t size_type;
    // difference type 
    typedef std::ptrdiff_t difference_type;
    // comparison algorithm 
    typedef Compare key_compare;
    // allocator type
    typedef Alloc allocator_type;
    // reference 
    typedef value_type& reference;
    // const reference
    typedef const value_type& const_reference;
    // pointer
    typedef typename allocator::pointer pointer;
    // const pointer
    typedef typename allocator::const_pointer const_pointer;


    template <bool Const = false>
    class iterator_base {
    public:
      typedef std::bidirectional_iterator iterator_category;
      typedef ft::pair<const key, T> value_type;
      typedef std::ptrdiff_t difference_type;

      typedef typename choose_type<Const, const T*, T*> pointer;
      typedef typename choose_type<Const, const T&, T&> reference;

      // bla bla very intresting stuff very 

    private:
      // bla bla other very intersting stuff 
    };

    // typedef iterator_base<false> iterator;
    // typedef iterator_base<true> const_iterator;

    // typedef reverse_iterator<const_iterator> const_reverse_iterator;
    // typedef reverse_itereror<iterator> reverse_iterator;


       /************** Member classes **************/


       /************** Member functions **************/
      
  private:
    key_compare _comp;
    allocator_type _alloc;
    ft::AVLTree<value_type> _tree;
    
    

    // the map will use an AVL tree to store the data
    
  
  }; // map class 
  
  
#endif
}; // ft namespace

