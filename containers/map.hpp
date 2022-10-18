/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:48:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/10/18 14:34:48 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/* associative container that contains a sorted set of key-value pairs,       */
/* with unique keys. the sorting criteria is defined by the Compare class,    */
/* which defaults to less<Key>.                                               */
/* map is allocator-aware, and reversible.                                    */
/*****************************************************************************/


/// TODO:
 // think about how the copy constructor of the iterator should work



namespace ft {

#include <less.hpp>
#include <memory>
#include <pair.hpp>
#include <choose_type.hpp>
#include <reverse_iterator.hpp>
#include <avlnode.hpp>

#ifndef MAP_HPP
#define MAP_HPP

  template < class key, class T, class Compare = ft::less<key>, class Alloc = std::allocator<ft::pair<const key, T> > >
  class map {
  public:
    /************** Member types **************/
    typedef key key_type;
    typedef T mapped_type;
    typedef ft::pair<const key, T> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::pointer pointer;
    typedef typename Alloc::const_pointer const_pointer;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

    // making whatever functor compares the keys only.
    class value_compare {
    public:
      typedef bool result_type;
      typedef value_type first_argument_type;
      typedef value_type second_argument_type;
      value_compare(Compare c) : comp(c) {}
      bool operator()(const value_type& x, const value_type& y) const {
        return comp(x.first, y.first);
      }
    protected:
      Compare comp;
    };


    // iterator
    template <bool Const = false>
    class iterator_base {
    public:
      /* iterator traits */
      typedef std::bidirectional_iterator_tag iterator_category;
      typedef T value_type;
      typedef std::ptrdiff_t difference_type;
      typedef typename ft::choose_type<Const, const T*, T*>::type pointer;
      typedef typename ft::choose_type<Const, const T&, T&>::type reference;

      /* constructor */
      iterator_base() : _root(NULL), _current(NULL), _end(NULL) {}

      iterator_base(AVLNode<value_type>* root, AVLNode<value_type>* current, AVLNode<value_type>* end) : _root(root), _current(current), _end(end) {}


      //
      // iterator_base(const iterator_base& other) : _root(other._root), _current(other._current), _end(other._end) {}

      // iterator_base& operator=(const iterator_base& other) {
      //   _root = other._root;
      //   _current = other._current;
      //   _end = other._end;
      //   return *this;
      // }

      /* destructor */
      ~iterator_base() {}

      /* operators */

    private:
      AVLNode<value_type>* _root;
      AVLNode<value_type>* _current;
      AVLNode<value_type>* _end;
    };

    typedef iterator_base<false> iterator;
    typedef iterator_base<true> const_iterator;

    typedef reverse_iterator<iterator> reverse_iterator;
    typedef reverse_iterator<const_iterator> const_reverse_iterator;



    /************** Member functions **************/

    /* constructors */


    // (1) empty container constructor (default constructor)
    explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(NULL), _size(0), _comp(comp), _alloc(alloc) {}

    // (2) range constructor
    template <class InputIterator>
    map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(NULL), _size(0), _comp(comp), _alloc(alloc) {
      // insert(first, last);
    }

    // (3) copy constructor
    map(const map& x) : _tree(NULL), _size(0), _comp(x._comp), _alloc(x._alloc) {
      // insert(x.begin(), x.end());
    }

    /* destructor */
    ~map() {
      clear();
    }

    /* operator= */
    map& operator= (const map& x) {
      clear();
      insert(x.begin(), x.end());
      return *this;
    }

    /* iterators */
    iterator begin() {
      return iterator(_tree->root(), _tree->min(), _tree->max());
    }
    const_iterator begin() const {
      return const_iterator(_tree->root(), _tree->min(), _tree->max());
    }


    iterator end() {
      return iterator(_tree->root(), _tree->max(), _tree->max());
    }

    const_iterator end() const {
      return const_iterator(_tree->root(), _tree->max(), _tree->max());
    }

    reverse_iterator rbegin() {
      return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const {
      return const_reverse_iterator(end());
    }

    reverse_iterator rend() {
      return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const {
      return const_reverse_iterator(begin());
    }

    /* capacity */
    bool empty() const {
      return _size == 0;
    }

    size_type size() const {
      return _size;
    }

    size_type max_size() const {
      return _alloc.max_size();
    }

    /* element access */
    mapped_type& operator[] (const key_type& k) {
      // intresting stuff here
    }

    // at 
    mapped_type& at(const key_type& k) {
      // intresting stuff here
    }

    const mapped_type& at(const key_type& k) const {
      // intresting stuff here
    }

    /* modifiers */

    // insert single element (1)
    ft::pair<iterator, bool> insert(const value_type& val) {
      // implementing insert

      if (_tree != NULL) {
        AVLNode<value_type>* node = _tree->insert(val);
        if (node->data)
      }

    }
    // insert witih hint (2)
    iterator insert(iterator position, const value_type& val) {
      // intresting stuff here
    }

    // insert range (3)
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
      // intresting stuff here
    }





  private:
    allocator_type _alloc;
    key_compare _comp;
    size_type _size;
    AVLTree<value_type, value_compare, allocator_type> _tree;

  }; // map class 

#endif
}; // ft namespace

