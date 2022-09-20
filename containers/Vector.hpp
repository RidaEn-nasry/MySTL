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

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

/* The vector conatainer is implemented i
 * 
 *
 */

namespace ft
{
  template <class T, class Alloc = std::allocator<T> >
  class vector {
  public:
	// iterator class
	class iterator {
	public:
	  typedef T value_type;
	  
	private:
	  T* _ptr;
	  
	}
  private:
	
  }
}

#endif


