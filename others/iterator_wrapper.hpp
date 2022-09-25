/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_wrapper.hpp                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:20:12 by ren-nasr         	 #+#   #+#            */
/*   Updated: 2022/09/25 18:20:12 by ren-nasr          	 ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_WRAP_HPP
#define ITERATOR_WRAP_HPP

#include <iterator_traits.hpp>

namespace ft {
  template <class Iter>
  class iterator_wrap {
  public:
	typedef Iter iterator_type;
	typedef typename iterator_traits<iterator_type>::value_type value_type;
	typedef typename iterator_traits<iterator_type>::difference_type difference_type;
	typedef typename iterator_traits<iterator_type>::pointer pointer;
	typedef typename iterator_traits<iterator_type>::reference reference;
	typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
  };
};

#endif

