/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:12:40 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/13 14:50:34 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implementation of AVL tree as a templated class. */


#ifndef AVL_HPP
#define AVL_HPP

#include <less.hpp>

template <class T>
struct AVLNode {
  T data;
  struct AVLNode* left;
  struct AVLNode* right;
  struct AVLNode* parent;
  int balance;
};

template <class T, class Compare = ft::less<T> >
class AVL {
public:
  AVL() : _root(NULL), _size(0) {}
  ~AVL() {}
  AVL(const AVL& avl) : _root(NULL), _size(0) { *this = avl; }
  
  // AVL& operator=(const AVL& avl) {
    
  // }
  
  

private:
  AVLNode<T>* _root;
  size_t _size;
  Compare _comp;

}



#endif
