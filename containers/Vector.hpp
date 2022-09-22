/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:56:03 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/09/21 20:34:06 by ren-nasr         ###   ########.fr       */
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
  template <typename T, typename Alloc = std::allocator<T>>

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
	
    /* iterator class */
	class	iterator {
	  
		// TODO	
	};
	
	/************* Constructors **************/
	
	/* default constructor */
	explicit vector(const allocator_type& alloc = allocator_type()){
	  this->_array = alloc.allocate(0);
	  this->_size = 0;
	  this->_capacity = 0;
	}
	
  
	/* fill constructor */
	explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()){

	}
		
	/* range constructor */
	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
		   const allocator_type& alloc = allocator_type()) {
	}

	/* copy constructor */
	vector(const vector& x) {

	}


	// capacity member functions
	bool empty() const {
	  return (this->_size == 0);
	}
	
			  

	
  private:
    /* underlying array */
    T* _array;
    /* size of the vector */
    size_t _size;
    /* capacity of the vector */
    size_t _capacity;
  };
} 
#endif



