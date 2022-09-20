	
# Overview of STL Components 
Stl Consist of six major components : <br>
 - containers 
 - generic algorithms
 - iterators 
 - function objects
 - adaptor
 - allocators



* vectors are implemented using **arrays[]**, lists are implemented using **doubly-linked lists** and deques are implemented using **two dimensional arrays**.

 * Sorted associative containers provide an ability for fast retrieval of objects from a collection based on keys.
 
 * There are five types of iterators: (listed from the most to the least powerful)
  * Random access iterator
  * Bidirectional iterator
  * Forward iterator
  * input iterator
  * output iterator
 
 ![Hierarchial structure of iterators](https://i.postimg.cc/Tw0HnPqZ/Screen-Shot-2022-09-16-at-11-21-48.png)
 
 
* Specific generic algorithms works with specific iterators, for example the sort algorithm works with random access iterators only and cannot be used for example with lists which use bidirectional iterators. list container has its own implementation of the sort algorithm which plays well with it's own iterators. these limitations are imposed intentionally by STL for performance sake. you know the drill it's a feature not a bug. said it best the god father of STL himself.

> Performance constraints are good for creativity
> 
> <cite>alexander stepanov, from 'mathematics to generic programming'</cite>


## Function Objects

* formally function objects (also called a functor) are any type that define the
``operator()``. 
* the core idea of functors is using an instance of class as if it was a function.

* A functor once said : 
 > Anything that behaves like a function is a function. even though it's a class.
 
 * a bug from noweher replied: And why in the fuck would we need a another way to represent a function. you're just a useless syntactical sugar , like the sprinkeles i asked the ice cream man to add to my gelato yesterday.
 
 
 
## Adapters

* adapters components modifies the interface of another components , they're can be used either on containers or functions.

For example:

* A stack adapter transform a sequence container into a more of a stack-like restricted container with the last-in first-out interface.

* A queue adapter transform into a first-in first-out queue.


## Allocaters: 
 * these are classes that defines the memory model used by a specific container , how memory will be obtained from the from the os.
 
 
 
 
# Iterators
 This is an interface implemented by containers as a consistent manner to allow access and manipulations of it's elements.

An iterator should be designed as to provide wasy to: 
* Move to the beginning of the range of elements.
* Advance to the next elements.
* Return the value refereed to.
* Query it to see if it is at the end of the range.

* **iterators are categorized by the operations that they must support** , so one can use a pointer, an integer or class as long as it support *,++,=,==.

Their capabilities ranges from Random access iterators that has all of the power of a regular c++ pointer, to the input and output iterators that can only go forward in a collection either reading or writing. In between are the bi-directional, reverse , insertion, stream and forward iterators, Each is a class with it's own member. functions, overloaded operators and data.


**All STL iterators for the very least support the following operation:**
 * *it . able to dereference value for set/get sake.
 * ++it . able to point to the next element. value after update.
 * it++ . able to point to the next element. value before update.
 * it1 = it2 . able to assign
 * it1 == it2 . able to compare equality
 * it1 != it2 . able to compare inaquality
 
 for bidrectional operators they also support: 
 * --it . able to pre-decrement.
 * it-- . able to post-decrement.
 
 and for random access iteratos these operations are also supported :
  * it += i . able to increment by i positions.
  * it -= i . able to decrement by i positions.
  * it2 + I . same for increment. 
  * it2 - I . same for decrement.
  * it[i] . returns a reference to the ith element.
  * it1 < it2 comparison 
  * it1 <= it2 comparison 
  * it1 > it2 comparison 
  * it1 <= it2 comparison 
   
 * The definitions of STL iterator categories are encouraged by considering the needs of a certain algorithm. 
 
 
 
	 * The meaning is : that iterators categorization is motivated by certain aglorithms requirements and properties. practicaly there are algorithms which only need to read or write or both, move forward or backward or both, and so on. the different nature of these algorithms motivated the implementation of different iterator categories with different capabilities.
	
 * **All operations must in constant time O(1)**.
 
* each iterator category is defined depending on the operations that it supports. 
 * Input Iterator: 
  - 
## Input Iterators: 
 * Input iterators used to read values from a sequence they support at least the following operations: 
   - copy-assignable, copy-construcable, destructable. (A = B, A(B), ~A())
   - dereferenceable as an rvalue ( *A ).
   - pre/post incrementable ( ++A, A++ ).
   - equality/inequality comparable ( A == B, A != B ).
   
## Output Iterators: 
	* Output iterators used to write values to a sequence they should support at least the following operations: 
		 - copy-assignable, copy-construcable, destructable. (A = B, A(B), ~A())
		 - dereferenceable as an lvalue ( *A ).
		 - pre/post incrementable ( ++A, A++ ).
	 
## Forward Iterators:
    * Forward iterators are used to read and write values in a sequence in a forward direction only they combine the capabilities of input and output iterators.
	
## Bidirectional Iterators:
    * Bidirectional iterators are used to read and write values in a sequence in both directions they combine the capabilities of forward iterators plus the ability to move backward. ( --A, A-- ).
	
## Random Access Iterators:

* Random access iterators are used to access value in a sequence in a random fashion they at least support the following properties: 
  * copy-assignable, copy-construcable, destructable. (A = B, A(B), ~A())
  * dereferenceable as an lvalue ( *A ).
  * dereferenceable as an rvalue ( *A ).
  * pre/post incrementable ( ++A, A++ ).
  * can be compared for equality/inequality ( A == B, A != B ).
  * support arithmetic operations ( A + B, A - B, A - B, B + A).
  * support comparison operations ( A < B, A <= B, A > B, A >= B).
  * support compound assignment operations ( A += B, A -= B).
  * support array subscripting ( A[B] ).



## Summary : 
 * Iterators are used to access the elements of a container. 
 * Iterators are categorized by the operations that they must support.
 * They can be summarized as follows: 
   * read and traversed in one direction only. (input iterators)
   * write and traversed in one direction only. (output iterators)
   * read and write and traversed in one direction only. (forward iterators)
   * read and write and traversed in both directions. (bidirectional iterators)
   * read and write and traversed in random fashion. (random access iterators) 
 

# The STL iterator hierarchy, combining algorithms and containers efficiently. 

 * The STL iterator classification is hierarchical. 