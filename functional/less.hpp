/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:13:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/08 15:27:23 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
#ifndef LESS_HPP
#define LESS_HPP

  template < class T>
  struct less {
    /** member types **/
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;

    /** member functions **/
    bool operator()(const T& x, const T& y) const { return x < y; }

  }; // less struct
#endif
} // namespace ft