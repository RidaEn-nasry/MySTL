/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:12:40 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/16 10:53:12 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implementation of AVL tree as a templated class. */

// should the avl class be implmented as node or a class wrapper that manages
// the node

// balancing will happen when we try to insert a node in the tree

#ifndef AVL_HPP
#define AVL_HPPavlnode

#include <less.hpp>

#include "avlnode.hpp"

namespace ft {

	template < class T >
	class AVLTree {
	public:
		/** member types **/
		typedef T value_type;
		typedef AVLNode< T > node_type;

		// default constructor
		AVLTree() : _root(NULL), _size(0) { }

		// initializing constructor
		explicit AVLTree(const value_type& data) {
			_root = new node_type;
			_root->setData(data);
			_root->setParent(NULL);
			_root->setLeft(NULL);
			_root->setRight(NULL);
			_size = 1;
		}

		AVLTree(const AVLTree< T >& other) { *this = other; }

		AVLTree<T>& operator=(const AVLTree<T>& other) {
			// clear the tree and then copy the other tree
			clear();
			_root = copy(other._root);
			_size = other._size;
			return *this;
		}

		void clear() {
			// delete the tree
			
			

		}
 
		
	private:
		node_type* _root;
		size_t _size;
	};
}  // namespace ft
#endif
