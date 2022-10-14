/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:12:40 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/14 14:13:48 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implementation of AVL tree as a templated class. */

// should the avl class be implmented as node or a class wrapper that manages the node

// balancing will happen when we try to insert a node in the tree

#ifndef AVL_HPP
#define AVL_HPP

#include <less.hpp>

template <class T>
struct AVLNode
{
  T data;
  struct AVLNode *left;
  struct AVLNode *right;
  struct AVLNode *parent;
  int balance;
};

/************************************************************************************************/
/* true that a recursive version of some member functions could result in a much smaller and    */
/* maybe elegant code, still if the BST is huge that would result in many recursive calls which */
/*  could potentially lead to stack overflow, thus non-recursive implementations is preferable  */
/***********************************************************************************************/

template <class T>
class AVL
{
public:
  /** member types **/
  typedef AVLNode<T> node_type;
  typedef size_t size_type;
  typedef T value_type;

  /** member functions **/
  AVL() : _root(NULL), _size(0) {}
  ~AVL() {}
  // AVL(const AVL& avl) : _root(NULL), _size(0) { *this = avl; }

  // size
  const size_type size() const { return _size; }

  /********* searching *********/
  // search for node x in the tree, if found return it otherwise return the closest node z to x.
  const value_type &find(const value_type &data) const
  {
    node_type *u = _root;
    node_type *z = NULL;
    while (u != NULL)
    {
      if (data < u->data)
      {
        z = u;
        u = u->left;
      }
      else if (data > u->data)
      {
        z = u;
        u = u->right;
      }
      else
        return u->data;
    }
    return z->data;
  }

  /********* adding **********/
  void add(const value_type &data)
  {
    // if tree is empty
    if (_root == NULL)
      _init(data);
    node_type *node = _find(data);
    if (node->data == data)
      return;
    ++_size;
    _new_node(data, node);
  }

  /*********** removing **********/
  void remove(value_type &data)
  {
    node_type *u = _find(data);
    node_type *w = NULL;
    if (u->data != data)
      return;
    // if u is a leaf or a node with exactly child detach it.
    if (u->left == NULL || u->right == NULL)
    {
      _remove_node(u);
      return;
    }
    // else find the smallest value that's greater than
    w = u->right;
    while (w->left != NULL)
      w = w->left;
    u.data = w.data;
    _remove_node(w);
  }

private:
  node_type *_root;
  size_type _size;

  /** private member functions */
  size_type _depth(const node_type *node) const
  {
    size_type dist = 0;
    node_type *tmp_node = node;
    while (tmp_node != _root)
    {
      tmp_node = tmp_node->parent;
      dist += 1;
    }
    return dist;
  }

  // a version of find that returns an address instead of value_type
  node_type *_find(const value_type &data)
  {
    node_type *u = _root;
    node_type *z = NULL;
    while (u != NULL)
    {
      if (data < u->data)
      {
        z = u;
        u = u->left;
      }
      else if (data > u->data)
      {
        z = u;
        u = u->right;
      }
      else
        return u;
    }
    return z;
  }

  void _new_node(const value_type &data, node_type *node)
  {
    node_type *baby_node = new node_type;
    baby_node->data = data;
    baby_node->parent = node;
    baby_node->right = NULL;
    baby_node->left = NULL;
    if (baby_node->data > node->data)
      node->right = baby_node;
    else if (baby_node->data < node->data)
      node->left = baby_node;
  }

  void _init(const value_type &data)
  {
    _root = new node_type;
    _root->data = data;
    _root->parent = NULL;
    _root->left = NULL;
    _root->right = NULL;
    ++_size;
  }

  size_type _sizee() const
  {
    node_type *u = _root;
    node_type *prev = NULL;
    size_type s = 0;
    node_type *nxt = NULL;

    while (u != NULL)
    {
      // if we come from parent of node we move left
      if (prev == u->parent)
      {
        s += 1;
        if (u->left != NULL)
          nxt = u->left;
        else if (u->right != NULL)
        {
          nxt = u->right;
        }
        else
          nxt = u->parent;
      }
      // else if we come from left move right
      else if (prev == u->left)
      {
        if (u->right != NULL)
          nxt = u->right;
        else
          nxt = u->right;
      }
      else
        nxt = u->parent;

      prev = u;
      u = nxt;
    }
    return s;
  }

  // removing a leaf or a node with 1 child
  void _remove_node(node_type *u)
  {
    node_type *s = NULL;
    node_type *p = NULL;
    if (u->data != data)
      return;
    if (u->left != NULL)
      s = u->left;
    else
      s = u->right;
    if (u == _root)
      s = _root;
    else
    {
      p = u->parent;
      if (p->left == u)
        p->left = s;
      else
        p->right = s;
    }
    if (s != NULL)
      s->parent = p;
  };

#endif
