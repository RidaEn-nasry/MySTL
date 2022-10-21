/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlnode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:03:35 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/21 10:30:58 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLNODE_HPP
#define AVLNODE_HPP

#include <stdio.h>
#include <less.hpp>

namespace ft
{
  template <class T, class Compare = less<T> >
  class AVLNode
  {
  public:
    /** Member types **/
    typedef T value_type;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef Compare key_compare;
    typedef AVLNode<T, key_compare> self;
    /** Member functions **/

    // (1) default constructor
    AVLNode()
    {
      _right = NULL;
      _left = NULL;
      _parent = NULL;
      _data = value_type();
      _comp = key_compare();
    };

    // (2) constructor with data and optional parent
    AVLNode(value_type data, self *parent = NULL)
    {
      _right = NULL;
      _left = NULL;
      _data = data;
      _parent = parent;
      _comp = key_compare();
    } 

    // getters
    inline reference data() { return _data; }

    inline pointer data_ptr() { return &_data; }

    inline self *right() const { return _right; }

    inline self *left() { return _left; }

    inline self *parent() { return _parent; }

    inline int height() const
    {
      // calculate the height of the node
      // if the node is a leaf then the height is 0
      // if the node has only one child then the height is 1
      // if the node has two children then the height is the max height of the two children + 1
      int left_height = 0;
      int right_height = 0;
      if (_left != NULL)
      {
        left_height = _left->height();
      }
      if (_right != NULL)
      {
        right_height = _right->height();
      }
      return (left_height > right_height ? left_height : right_height) + 1;
    }

    // setters
    void setData(reference data) { _data = data; }
    void setRight(self *right) { _right = right; }
    void setLeft(self *left) { _left = left; }
    void setParent(self *parent) { _parent = parent; }

    // calculate the balance of the node
    int balance() const
    {
      // the balance is the height of the left subtree - the height of the right subtree
      int left_height = _left == NULL ? 0 : _left->height();
      int right_height = _right == NULL ? 0 : _right->height();
      return left_height - right_height;
    }

    /** non-member functions **/
    // equality / inequality operators
    inline friend bool operator==(const self &lhs, const self &rhs)
    {
      return !(lhs._comp(lhs._data, rhs._data)) && !(lhs._comp(rhs._data, lhs._data));
    }

    inline friend bool operator!=(const self &lhs, const self &rhs)
    {
      return !(lhs == rhs);
    }

    inline friend bool operator<(const self &lhs, const self &rhs)
    {
      return lhs._comp(lhs._data, rhs._data);
    }

    inline friend bool operator>(const self &lhs, const self &rhs)
    {
      return rhs < lhs;
    };

    inline friend bool operator<=(const self &lhs, const self &rhs)
    {
      return !(lhs > rhs);
    }

    inline friend bool operator>=(const self &lhs, const self &rhs)
    {
      return !(lhs < rhs);
    }

    // next
    inline self *next()
    {
      // if the node has a right child then the next node is the leftmost node of the right subtree
      if (right() != NULL)
      {
        self *node = right();
        while (node->left() != NULL)
        {
          node = node->left();
        }
        return node;
      }
      self *node = this;
      // else if node if left child of it's parent next node is node's parent
      if (node->parent()->left() == node)
        return node->parent();
      // else if node is right child of it's parent then the next node is the parent of the first left child of the parent
      while (node->parent()->right() == node)
      {
        node = node->parent();
      }
      return node->parent();
    };

    // prev
    inline self *prev()
    {
      // if the node has a left child then the prev node is the rightmost node of the left subtree
      if (left() != NULL)
      {
        self *node = left();
        while (node->right() != NULL)
        {
          node = node->right();
        }
        return node;
      }
      self *node = this;
      // else if node if right child of it's parent prev node is node's parent
      if (node->parent()->right() == node)
        return node->parent();
      // else if node is left child of it's parent then the prev node is the parent of the first right child of the parent
      while (node->parent()->left() == node)
      {
        node = node->parent();
      }
      return node->parent();
    };

  private:
    value_type _data;
    self *_right;
    self *_left;
    self *_parent;
    key_compare _comp;
  };

};
#endif