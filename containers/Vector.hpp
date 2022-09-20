/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:56:03 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/09/14 22:11:34 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @file Vector.hpp
 * @author rida ennasry
 * @brief Vector container re-implementation.
 * @date 2022/09/20
*/


#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft
{
  template <typename T, typename Alloc = std::allocator<T> >

  class vector {
  public:
	/* value type member type */
	typedef T value_type;
	/* allocator type member type */
	typedef Alloc allocator_type;
	/* reference to allocator type member type */
	typedef typename allocator_type::reference reference;
	/* const reference to allocator type member type */
	typedef typename allocator_type::const_reference const_reference;

	
	
  private:
	/* underlying array */
	T* _array;
	/* size of the vector */
	size_t _size;
	/* capacity of the vector */
	size_t _capacity;
   
	  
   
	  
	}
  private:
	
  }
}

#endif


