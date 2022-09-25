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

/*
  exceptions which handeled by the vector class

  std::length_error (if the vector size exceeds max_size())
  std::bad_alloc (if memory allocation fails)
  std::out_of_range (if the index is out of range)
  std::invalid_argument (if the index is not valid)
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
//#include <iterator_traits.hpp>
#include <iterator_wrapper.hpp>

namespace ft {
template <typename T, typename Alloc = std::allocator<T> >

class vector {

public:
  /*************** Member types ***************/

  /* elements type */
  typedef T value_type;

  /* allocator type */
  typedef Alloc allocator_type;

  /* reference */
  typedef typename allocator_type::reference reference;

  /* const reference to chunk of memory allocated by allocator */
  typedef typename allocator_type::const_reference const_reference;

  /* pointer to memory allocator by std::allocater */
  typedef typename allocator_type::pointer pointer;

  /* const pointer to chunk of memory allocated by allocator */
  typedef typename allocator_type::const_pointer const_pointer;

  /* difference type */
  typedef typename allocator_type::difference_type difference_type;

  /* size type */
  typedef typename allocator_type::size_type size_type;

  /* iterator type */
  typedef ft::iterator_wrapper<pointer> iterator;
  typedef ft::iterator_wrapper<const_pointer> const_iterator;


  /* reverse iterator type */
  // later ...

  
  	
  /************* Constructors **************/

  /* default constructor */
  explicit vector (const allocator_type& alloc = allocator_type()){
	this->_alloc = alloc;
	this->_size = 0;
	this->_capacity = 0;
	this->_vector = NULL;
  }
  
  /* fill constructor */
  explicit vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
	this->_alloc = alloc;
	this->_size = n;
	this->_capacity = n;

   	
  } 
  /* range constructor */

  /* copy constructor */

  // capacity member functions
  bool empty() const { return (this->_size == 0); }


private:
  pointer _vector;
  size_type _size;
  size_type _capacity;
  allocator_type _alloc;
  
  
};

} // namespace ft
#endif
