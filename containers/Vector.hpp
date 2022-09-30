/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:56:03 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/09/30 15:58:06 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @file Vector.hpp
 * @author rida ennasry
 * @brief Vector container re-implementation.
 * @date 2022/09/20
 */

 // TODO : implment reverse_iterator and const_reverse_iterator
 // add correstponding member types and functions
 // addd a lot of tests, i mean a lot of tests.
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>

namespace ft {
  template <typename T, typename Alloc = std::allocator<T> >

  class vector {
  public:
    /*************** Member types ***************/

    /* elements type */
    typedef T value_type;

    /* allocator type */
    typedef Alloc allocator_type;

    /* reference to chunk of memory allocated by allocator */
    typedef typename allocator_type::reference reference;

    /* const reference to chunk of memory allocated by allocator */
    typedef typename allocator_type::const_reference const_reference;

    /* pointer to memory allocated by std::allocater */
    typedef typename allocator_type::pointer pointer;

    /* const pointer to chunk of memory allocated by allocator */
    typedef typename allocator_type::const_pointer const_pointer;

    /* difference type */
    typedef typename allocator_type::difference_type difference_type;

    /* size type */
    typedef typename allocator_type::size_type size_type;

    /******************** Iterators ********************/

    /* iterator implementation */
    class iterator {
    public:
      /* iterator traits */
      typedef std::random_access_iterator_tag iterator_category;
      typedef T value_type;
      typedef std::ptrdiff_t difference_type;
      typedef T* pointer;
      typedef T& reference;

      /* constructors & destcructors */

      /* default constructible */
      iterator() : _ptr(NULL) {};
      /* copy constructible */
      iterator(const iterator& other) : _ptr(other._ptr) {};
      /* copy assignable */
      iterator& operator=(const iterator& other) {
        _ptr = other._ptr;
        return *this;
      };

      /* constructible from pointer */
      iterator(pointer ptr) : _ptr(ptr) {};

      /* destructible */
      ~iterator() {};

      /* member functions */

      /* equality operators */
      bool operator==(const iterator& other) const { return _ptr == other._ptr; };
      bool operator!=(const iterator& other) const { return _ptr != other._ptr; };

      /* increment operators */

      /* prefix */
      inline iterator& operator++() {
        _ptr++;
        return *this;
      };
      /* postfix */
      inline iterator operator++(int) {
        iterator tmp(*this);
        operator++();
        return tmp;
      };

      /* dereferenceable */
      inline reference operator*() const { return *_ptr; };

      /* decrement operators */

      /* prefix */
      inline iterator& operator--() {
        _ptr--;
        return *this;
      };

      /* postfix */
      inline iterator operator--(int) {
        iterator tmp(*this);
        operator--();
        return tmp;
      };

      /* arithmetic operators */

      /* addition iterator + n */
      inline iterator operator+(difference_type n) const {
        return iterator(_ptr + n);
      };

      /* addition n + iterator */
      inline friend iterator operator+(difference_type n, const iterator& it) {
        return iterator(it._ptr + n);
      };

      /* subtraction iterator - n */
      inline iterator operator-(difference_type n) const {
        return iterator(_ptr - n);
      };

      /* subtraction iterator - iterator */
      inline difference_type operator-(const iterator& other) const {
        return _ptr - other._ptr;
      };

      /* equality relational operators */
      bool operator<(const iterator& other) const { return _ptr < other._ptr; };
      bool operator>(const iterator& other) const { return _ptr > other._ptr; };
      bool operator<=(const iterator& other) const { return _ptr <= other._ptr; };
      bool operator>=(const iterator& other) const { return _ptr >= other._ptr; };

      /* compound assignment operators */

      inline iterator& operator+=(difference_type n) {
        _ptr += n;
        return *this;
      };
      inline iterator& operator-=(difference_type n) {
        _ptr -= n;
        return *this;
      };

      /* subscript operator */
      inline reference operator[](difference_type n) const { return _ptr[n]; };

    private:
      pointer _ptr;
    };

    /* const iterator implementation */
    class const_iterator {
    public:
      /* iterator traits */
      typedef std::random_access_iterator_tag iterator_category;
      typedef T value_type;
      typedef std::ptrdiff_t difference_type;
      typedef const T* pointer;
      typedef const T& reference;

      /* constructors & destcructors */
      inline const_iterator() : _ptr(NULL) {};
      inline const_iterator(const const_iterator& other) : _ptr(other._ptr) {};
      inline const_iterator& operator=(const const_iterator& other) {
        _ptr = other._ptr;
        return *this;
      };
      inline const_iterator(pointer ptr) : _ptr(ptr) {};
      inline ~const_iterator() {};

      /* member functions */

      /* equality operators */
      inline bool operator==(const const_iterator& other) const {
        return _ptr == other._ptr;
      };
      inline bool operator!=(const const_iterator& other) const {
        return _ptr != other._ptr;
      };

      /* increment operators */

      /* prefix */
      inline const_iterator& operator++() {
        _ptr++;
        return *this;
      };

      /* postfix */
      inline const_iterator operator++(int) {
        const_iterator tmp(*this);
        operator++();
        return tmp;
      };

      /* dereferenceable */
      inline reference operator*() const { return *_ptr; };

      /* decrement operators */

      /* prefix */
      inline const_iterator& operator--() {
        _ptr--;
        return *this;
      };

      /* postfix */
      inline const_iterator operator--(int) {
        const_iterator tmp(*this);
        operator--();
        return tmp;
      };

      /* arithmetic operators */

      /* addition iterator + n */
      inline const_iterator operator+(difference_type n) const {
        return const_iterator(_ptr + n);
      };

      /* addition n + iterator */
      inline friend const_iterator operator+(difference_type n,
        const const_iterator& it) {
        return const_iterator(it._ptr + n);
      };

      /* subtraction iterator - n */
      inline const_iterator operator-(difference_type n) const {
        return const_iterator(_ptr - n);
      };

      /* subtraction iterator - iterator */
      inline difference_type operator-(const const_iterator& other) const {
        return _ptr - other._ptr;
      };

      /* equality relational operators */
      inline bool operator<(const const_iterator& other) const {
        return _ptr < other._ptr;
      };
      inline bool operator>(const const_iterator& other) const {
        return _ptr > other._ptr;
      };
      inline bool operator<=(const const_iterator& other) const {
        return _ptr <= other._ptr;
      };
      inline bool operator>=(const const_iterator& other) const {
        return _ptr >= other._ptr;
      };

      /* compound assignment operators */

      inline const_iterator& operator+=(difference_type n) {
        _ptr += n;
        return *this;
      };

      inline const_iterator& operator-=(difference_type n) {
        _ptr -= n;
        return *this;
      };

      /* subscript operator */
      inline reference operator[](difference_type n) const { return _ptr[n]; };

    private:
      pointer _ptr;
    };

    /* reverse iterator implementation */
    // later on...

    /************* Constructors **************/

    /* default constructor */
    explicit vector(const allocator_type& alloc = allocator_type()) {
      this->_alloc = alloc;
      this->_size = 0;
      this->_capacity = 0;
      this->_vector = NULL;
    }

    /* fill constructor */
    explicit vector(size_type n, const value_type& val = value_type(),
      const allocator_type& alloc = allocator_type()) {
      this->_alloc = alloc;
      this->_size = n;
      this->_capacity = n;
      this->_vector = this->_alloc.allocate(n);
      for (size_type i = 0; i < n; i++)
        this->_alloc.construct(this->_vector + i, val);
    }

    /* range constructor */
    template <class InputIterator>
    vector(InputIterator first, InputIterator last,
      const allocator_type& alloc = allocator_type()) {
      this->_alloc = alloc;
      this->_size = 0;
      this->_capacity = 0;
      this->_vector = NULL;
      this->assign(first, last);
    };

    /* copy constructor */
    vector(const vector& x) {
      this->_alloc = x._alloc;
      this->_size = 0;
      this->_capacity = 0;
      this->assign(x.begin(), x.end());
    };

    /************** Member functions *************/

    /* iterator member functions */

    iterator begin() { return iterator(this->_vector); };
    iterator end() { return iterator(this->_vector + this->_size); };

    const_iterator cbegin() const { return const_iterator(this->_vector); };
    const_iterator cend() const {
      return const_iterator(this->_vector + this->_size);
    };

    // reverse iterator todo..

    /* capacity member functions */

    // reserve
    void reserve(size_type n) {
      if (n > this->_capacity) {
        size_type new_capacity = n * 1.5;
        this->realocate(new_capacity);
      }
      else
        return;
    };

    // resize
    void resize(size_type n, value_type val = value_type()) {
      if (n > this->_size)
        insert(this->end(), n - this->_size, val);
      else if (n < this->_size) {
        erase(this->begin() + n, this->end());
      }
      else
        return;
    };

    size_type size() const { return this->_size; };
    size_type capacity() const { return this->_capacity; };
    bool empty() const { return this->_size == 0; };

    /* element access member functions */
    reference front() { return this->_vector[0]; };
    const_reference front() const { return this->_vector[0]; };
    reference back() { return this->_vector[this->_size - 1]; };
    const_reference back() const { return this->_vector[this->_size - 1]; };
    reference operator[](size_type n) { return this->_vector[n]; };
    const_reference operator[](size_type n) const { return this->_vector[n]; };

    value_type* data() { return this->_vector; };
    const value_type* data() const { return this->_vector; };

    reference at(size_type n) {
      if (n >= this->_size)
        throw std::out_of_range("vector::at");
      return this->_vector[n];
    };

    const_reference at(size_type n) const {
      if (n >= this->_size)
        throw std::out_of_range("vector::at");
      return this->_vector[n];
    };

    /* modifiers member functions */

    // range assign
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last) {
      clear();
      insert(this->begin(), first, last);
    };

    // fill assign
    void assign(size_type n, const value_type& val) {
      clear();
      insert(this->begin(), n, val);
    };

    // clear
    void clear() { erase(this->begin(), this->end()); };

    // erase 
    iterator erase(iterator position) {
      iterator ret = position + 1;
      // moving elements starting from position one element to the left.
      for (iterator it = position; it != this->end() - 1; it++)
        *it = *(it + 1);
      this->_alloc.destroy(this->_vector + this->_size - 1);
      this->_size--;
      return ret;
    };

    // erase range
    iterator erase(iterator first, iterator last) {
      for (iterator it = first; it != last; it++)
        erase(it);
      return first;
    };

    // insert single element
    iterator insert(iterator position, const value_type& val) {
      // if the vector is full, realocate it
      iterator ret = position - 1;
      if (this->_size == this->_capacity)
        this->reallocate(this->_capacity * 1.5);
      ++this->_size;
      position = position - 1;
      value_type tmp = *position;
      *position = val;
      for (iterator it = position + 1; it != this->end(); it++) {
        value_type tmp2 = *it;
        *it = tmp;
        tmp = tmp2;
      }
      return ret;
    };

    // insert fill
    void insert(iterator position, size_type n, const value_type& val) {
      for (size_type i = 0; i < n; i++)
        insert(position, val);
    };

    // range insert
    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last) {
      for (InputIterator it = first; it != last; it++)
        insert(position, *it);
    };

    /*** allocator member functions ***/
    allocator_type get_allocator() const {
      return this->_alloc;
    };

  private:
    allocator_type _alloc;
    size_type _size;
    size_type _capacity;
    pointer _vector;
    // a reallocation method
    void reallocate(size_type new_capacity) {
      // allocate new memory
      pointer new_vec = this->_alloc.allocate(new_capacity);
      // copy old memory to new memory
      for (size_type i = 0; i < this->_size; i++)
        this->_alloc.construct(new_vec + i, this->_vector[i]);
      // deallocate old memory
      this->_alloc.deallocate(this->_vector, this->_capacity);
      // set new memory
      this->_vector = new_vec;
      this->_capacity = new_capacity;
    }
  };

} // namespace ft

#endif
