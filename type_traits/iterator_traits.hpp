/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:28:38 by ren-nasr         	 #+#   #+#            */
/*   Updated: 2022/09/25 13:28:38 by ren-nasr          	 ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* iterator_traits.hpp is class template that provide a uniform interface to  */
/* iterator types including non-standard iterators, like pointers.            */
/* ************************************************************************** */



namespace ft {

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

	template  <class Iter >
	struct iterator_traits {
		typedef typename Iter::value_type value_type;
		typedef typename Iter::reference reference;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::iterator_category iterator_category;
	};

#endif
}






