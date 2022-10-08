/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:42:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/08 14:45:03 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {

#ifndef MAKE_PAIR_HPP
#define MAKE_PAIR_HPP

#include <pair.hpp>

template <class T1, class T2>
ft::pair<T1, T2> make_pair(T1 x, T2 y) {
  return (ft::pair<T1, T2>(x, y));
}
#endif

} // namespace ft