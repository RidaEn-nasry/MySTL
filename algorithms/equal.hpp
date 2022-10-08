/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:11:13 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/08 22:23:37 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

#ifndef EQUAL_HPP
#define EQUAL_HPP
  /************* default *******************/
  template <class InputIterator1, class InputIterator2>
  bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
    // loop through the range [first1, last1)
    for (; first1 != last1; ++first1, ++first2) {
      // if the value of *first1 is not equal to the value of *first2
      if (!(*first1 == *first2)) {
        return false;
      }
    }
    return true;
  };

  /******************* predicate *******************/
  template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
    // loop through the range [first1, last1)
    for (; first1 != last1; ++first1, ++first2) {
      // if the value of *first1 is not equal to the value of *first2
      if (!pred(*first1, *first2)) {
        return false;
      }
    }
    return true;
  };

#endif
}