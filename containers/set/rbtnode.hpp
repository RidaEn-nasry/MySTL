/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtnode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:19:57 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/24 17:22:42 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTNODE_HPP
#define RBTNODE_HPP


// red-black tree node

template <class T, class Compare>
class RBTNode
{
public:
  typedef RBTNode<T, Compare> self;
  typedef T value_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef Compare key_compare;


  // (1) default constructor
  RBTNode(key_compare& comp) : _comp(comp), _right(NULL), _left(NULL), _parent(NULL), _data(value_type()) {}


  // (3) constructor with data and compare and optional parent
  RBTNode(value_type data, key_compare& comp, self* parent = NULL) : _data(data), _right(NULL), _left(NULL), _parent(parent), _comp(comp) {}

  // getters
  inline reference data() { return _data; }

  inline pointer data_ptr() { return &_data; }

  inline self* right() const { return _right; }

  inline self* left() { return _left; }

  inline self* parent() { return _parent; }



private:
  value_type _data;
  self* _right;
  self* _left;
  self* _parent;
  bool _color;
  key_compare _comp;
};

#endif