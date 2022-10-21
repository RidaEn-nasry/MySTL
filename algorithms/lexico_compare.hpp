/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexico_compare.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:58:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/21 09:55:01 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP
namespace ft {


  /** default (1) */
  template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2) {
    // loop through the range [first1, last1) and [first2, last2)
    for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
      // if the value of *first1 is less than the value of *first2
      if (*first1 < *first2) {
        return true;
      }
      // if the value of *first2 is less than the value of *first1
      if (*first2 < *first1) {
        return false;
      }
    }
    // if the range [first1, last1) is shorter than the range [first2, last2)
    return (first1 == last1 && first2 != last2);
  };

  /** customized (2) */
  template <class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, Compare comp) {
    // loop through the range [first1, last1) and [first2, last2)
    for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
      // if the value of *first1 is less than the value of *first2
      if (comp(*first1, *first2)) {
        return true;
      }
      // if the value of *first2 is less than the value of *first1
      if (comp(*first2, *first1)) {
        return false;
      }
    }
    // if the range [first1, last1) is shorter than the range [first2, last2)
    return (first1 == last1 && first2 != last2);
  };

} // namespace ft
#endif