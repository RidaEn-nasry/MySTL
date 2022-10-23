/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:13:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/23 12:30:19 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
#define LESS_HPP

namespace ft {

  template < class T>
  struct less {
    /** member types **/
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;

    /** member functions **/
    bool operator()(const T& x, const T& y) const { return x < y; }

  }; // less struct
} // namespace ft
#endif