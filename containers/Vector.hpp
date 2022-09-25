/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:56:03 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/09/24 17:26:24 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @file Vector.hpp
 * @author rida ennasry
 * @brief Vector container re-implementation.
 * @date 2022/09/20
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft {
template <typename T, typename Alloc = std::allocator<T> >

class vector {

public:
  
  /*************** Member types ***************/

  /* elements type */
  typedef T value_type;

  /* allocater type */
  typedef Alloc allocator_type;

  /* reference */
  typedef typename allocator_type::reference reference;

  /* const reference to chunk of memory allocated by allocater */
  typedef typename allocator_type::const_reference const_reference;
 
  /* pointer to memory allocater by std::allocater */
  typedef typename allocator_type::pointer pointer;

  /* const pointer to chunk of memory allocated by allocater */
  typedef typename allocator_type::const_pointer const_pointer;

  /* difference type */ 
  typedef typename allocator_type::difference_type difference_type;

  /* size type */
  typedef typename allocator_type::size_type size_type;
 
  /* iterator */
  
  /****************** iterator interface ********************/

  struct iterator {
	iterator() {
	  
	};
	/* copy constructible */
	iterator(const iterator& other) {
	};
	/* copy assingable */
	iterator& operator=(const iterator& rhs) {
	  return *this; 
	};
	/* destructible */
	~iterator(){
	  
	};
	
  };
  /************* Constructors **************/

  /* default constructor */

  /* fill constructor */

  /* range constructor */

  /* copy constructor */

  // capacity member functions
  bool empty() const { return (this->_size == 0); }

private:
  /* allocater */
  allocator_type _allocater;

};
  
} // namespace ft
#endif
