/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:56:03 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/09/26 17:26:27 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @file Vector.hpp
 * @author rida ennasry
 * @brief Vector container re-implementation.
 * @date 2022/09/20
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
//#include <iterator_traits.hpp>

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
	inline friend iterator operator+(difference_type n, const iterator& it){
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
	inline friend const_iterator operator+(difference_type n, const const_iterator& it){
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
	
  /************* Constructors **************/

  /* default constructor */
  explicit vector (const allocator_type& alloc = allocator_type()){
	this->_alloc = alloc;
	this->_size = 0;
	this->_capacity = 0;
	this->_vector = NULL;
  }
  
  /* fill constructor */
  explicit vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
	this->_alloc = alloc;
	this->_size = n;
	this->_capacity = n;
	this->_vector = this->_alloc.allocate(n);
 	for (size_type i = 0; i < n; i++)
	  		this->_alloc.construct(this->_vector + i, val);
	}
  
  /* range constructor */

  template <class InputIterator>
  vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {

  }
  /* copy constructor */

  vector (const vector& x )  {
	// calling assignment operator
	*this = x;
  };

  
  // capacity member functions
  bool empty() const { return (this->_size == 0); }


private:
  
  pointer _vector;
  size_type _size;
  size_type _capacity;
  allocator_type _alloc;
  
  
};

} // namespace ft
#endif
