/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:36:58 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/19 15:13:41 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/* half-assed implementation of AVL tree as a templated class.               */
/* it takes a key and a value and stores them in a node.                     */
/*****************************************************************************/


namespace ft {
#ifndef AVL_HPP
#define AVL_HPP

#include <less.hpp>
#include "avlnode.hpp"
#include <iostream>

  template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<AVLNode<T> > >
  class AVLTree {
  public:

    /** member types **/
    typedef T value_type;
    typedef AVLNode<T> node_type;

    typedef Compare key_compare;

    typedef typename Alloc::template rebind<node_type>::other allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef AVLTree<T, Compare, Alloc> self_type;

    // default constructor
    AVLTree(const allocator_type& alloc = allocator_type()) {
      _alloc = alloc;
      _comp = Compare();
      _root = NULL;
      _size = 0;
    };

    // initializing constructor
    explicit AVLTree(const value_type& val, const allocator_type& alloc = allocator_type()) {
      _alloc = alloc;
      _comp = Compare();
      _root = _new_node(val, NULL);
      _size = 1;
    };

    AVLTree(const AVLTree<T>& other) { *this = other; }

    self_type& operator=(const AVLTree<T>& other) {
      // if (this != &other) {
      //   if (_root != NULL)
      //     clear();
      //   copy(other._root);
      //   _size = other._size;
      // }
      return *this;
    }

    // ~AVLTree() { clear(); }

    /** member functions **/

    // searching 
    const value_type& find(const value_type& data) const {
      node_type* tmp = _root;
      while (tmp != NULL) {
        // search for the node using compare which takes two T data, in ft::map case it's a "pair<const key, value>"
        if (_comp(pair, tmp->data()))
          tmp = tmp->left();
        else if (_comp(tmp->data(), pair))
          tmp = tmp->right();
        else
          return tmp->data();
      };
      return NULL;
    };


    // inserting 
    value_type& insert(const value_type& data) {
      // if tree is empty set new node as root
      if (!_root)
      {
        _root = _new_node(data, NULL);
        _size++;
        return;
      }
      node_type* node = _root;
      node = _find(data);
      // if data doesn't exist in tree, if it's less then insert it to left.
      if (_comp(data, node->data()))
      {
        node->left() = _new_node(data, node);
        _balance(node);
        _size++;
        return node->left()->data();
      }
      // else if data is greater then insert it to right.
      else if (_comp(node->data(), data)) {
        node->right() = _new_node(data, node);
        _balance(node);
        _size++;
        return node->right()->data();
      }
      // else if found return the data. don't insert.
      else
        return node->data();
    };


    // // inserting with hint
    // value_type& insert(const value_type& data, const node_type* hint) {
    //   while (node_type !
    // };
    // deleting
    value_type& remove(value_type& data) {
      node_type* node = _find(data);
      // returned node is the node following the node that have been deleted
      // node_type* node_ret = NULL;
      // check if node exists using compare
      if (_comp(data, node->data()) || _comp(node->data(), data))
        return NULL;
      // if node has no children, or only one child
      if (node->left() == NULL || node->right == NULL)
        _splice(node);
      else {
        // find the smallest node in the right subtree
        node_type* min = node->right();
        while (min->left() != NULL)
          min = min->left();
        // replace the node with the smallest node in the right subtree
        node->data() = min->data();

        _splice(min);
      }
      // check balance
      _balance();
      return node->data();
    }




    // clearing
    // void clear() {
    //   node_type* current = _root;
    //   node_type* parent = NULL;
    //   while (current != NULL) {
    //     // if the node has a left child, go to it
    //     if (current->left() != NULL)
    //       current = current->left();
    //     else if (current->right() != NULL)
    //       current = current->right();
    //     else {
    //       parent = current->parent();
    //       // if the current node is the left child of its parent , set the parent's left child to NULL
    //       if (parent != NULL && parent->left() == current) {
    //         _alloc.destroy(current);
    //         _alloc.deallocate(current, 1);
    //         parent->left() = NULL;
    //       }
    //       else if (parent != NULL && parent->right() == current) {
    //         _alloc.destroy(current);
    //         _alloc.deallocate(current, 1);
    //         parent->right() = NULL;
    //       }
    //       --_size;
    //       current = parent;
    //     }
    //   }
    // };

    // copy
    void copy(node_type* other) {
      if (other == NULL)
        return;
      insert(other->data());
      copy(other->left());
      copy(other->right());
    }

    // height
    int height() const {
      return _root->height();
    }

    // print 
    void print() const {
      _print(_root);
    };

    // getters 

    // root getter
    node_type* root() const { return _root; }
    // end getter 
    node_type* end() const { return NULL; }
    // minimum 
    node_type* min() const {
      node_type* node = _root;
      while (node->left() != NULL)
        node = node->left();
      return node;
    };

    // maximum
    node_type* max() const {
      node_type* node = _root;
      while (node->right() != NULL)
        node = node->right();
      return node;
    };


    /**************** non member functions ****************/
    // friend bool operator==(const self_type& lhs, const self_type& rhs) {}

  private:
    node_type* _root;
    size_t _size;
    key_compare _comp;
    allocator_type _alloc;


    /* private member functions */

    // create a new node
    node_type* _new_node(const value_type& data, node_type* parent) {
      node_type* node = _alloc.allocate(1);
      _alloc.construct(node, node_type(data));
      node->parent() = parent;
      node->left() = NULL;
      node->right() = NULL;
      return node;
    }

    node_type* _find(const value_type& data) {
      node_type* node = _root;
      node_type* parent = NULL;
      while (node != NULL) {
        // save the parent as the closest node
        parent = node;
        // search for the node using compare
        if (_comp(data, node->data()))
          node = node->left();
        else if (_comp(node->data(), data))
          node = node->right();
        else
          return node;
      }
      return parent;
    };

    // balance the tree
    void _balance() {
      int balance = _root->balance();
      if (balance < 2 && balance > -2)
        return;
      // if left heavy
      if (balance > 1) {
        // if left-right heavy
        if (_root->left()->balance() < 0)
          _rotateLeft(_root->left());
        _rotateRight(_root);
      }
      // if right heavy
      else {
        // if right-left heavy
        if (_root->right()->balance() > 0)
          _rotateRight(_root->right());
        _rotateLeft(_root);
      }
    };

    void _rotateLeft(node_type* node) {
      node_type* right = node->right();
      node_type* parent = node->parent();
      node_type* right_left = right->left();

      // if node is root
      if (!parent)
        // set the right child as root
        _root = right;
      else {
        // if node is left child
        if (parent->left() == node)
          // set the right child as left child
          parent->left() = right;
        else // if node is right child
          // set the right child as right child
          parent->right() = right;
      }
      // set the right child's parent to the node's parent
      right->parent() = parent;
      // set the node's parent to the right child
      node->parent() = right;
      // set the right child's left child to the node
      right->left() = node;
      // set the node's right child to the right child's left child
      node->right() = right_left;
      // if the right child's left child is not null
      if (right_left)
        // set the right child's left child's parent to the node
        right_left->parent() = node;
    };

    void _rotateRight(node_type* node) {
      node_type* left = node->left();
      node_type* parent = node->parent();
      node_type* left_right = left->right();

      // if node is root
      if (!parent)
        // set the left child as root
        _root = left;
      else {
        // if node is left child
        if (parent->left() == node)
          // set the left child as left child
          parent->left() = left;
        else // if node is right child
          // set the left child as right child
          parent->right() = left;
      }
      // set the left child's parent to the node's parent
      left->parent() = parent;
      // set the node's parent to the left child
      node->parent() = left;
      // set the left child's right child to the node
      left->right() = node;
      // set the node's left child to the left child's right child
      node->left() = left_right;
      // if the left child's right child is not null
      if (left_right)
        // set the left child's right child's parent to the node
        left_right->parent() = node;
    };

    // splice a leaf or single-child node
    value_type& _splice(node_type* node) {
      node_type* tmp, parent;
      // if node has left or right child
      if (node->left() != NULL)
        tmp = node->left();
      else
        tmp = node->right();
      // if node is root
      if (node == _root)
        _root = tmp;
      else {
        parent = node->parent();
        // if node is left child of parent
        if (parent->left() == node)
          parent->left() = tmp;
        else // if node is right child of parent
          parent->right() = tmp;
      }
      // if node has a child, set the child's parent to the node's parent
      if (tmp)
        tmp->parent() = node->parent();
      // deallocate the node
      _alloc.destroy(node);
      _alloc.deallocate(node, 1);
      --_size;
      return tmp->data();
    };

    void _print(node_type* node) const {
      if (node == NULL)
        return;
      _print(node->left());
      std::cout << node->data() << std::endl;
      _print(node->right());
    };

  }; // end of AVLTree class

}; // namespace ft
#endif