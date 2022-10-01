/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:45:19 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/01 18:47:48 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


namespace ft {
#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

template <bool B, class T = void>
struct enable_if {};

#endif
} // namespace ft
