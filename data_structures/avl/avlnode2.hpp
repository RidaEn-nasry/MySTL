/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlnode2.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:40:39 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/18 15:40:49 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


namespace ft {


#ifndef AVLNODE_HPP
#define AVLNODE_HPP

  template <class T>
  class AVLNode {
  public:
    /** member types **/
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef AVLNode<T> self;

    /** member functions **/

    // (1) default constructor
    AVLNode() : _right(NULL), _left(NULL), _parent(NULL), _data(value_type()) {};
    // (2) initilization constructor 
    AVLNode(const value_type& data, parent* par = NULL) : _right(NULL), _left(NULL), _parent(par), _data(data) {};


    // getters
    self* right() const { return _right; };
    self* left() const { return _left; };
    self* parent() const { return _parent; };
    value_type& data() const { return _data; };


    


    // 
  private:
    // implmenetations here
    self* _right;
    self* _left;
    self* _parent;
    value_data _data;





  };


#endif

};