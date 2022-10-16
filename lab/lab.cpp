
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


template < class T>
class LLRoot {

public:
  typedef T value_type;
  typedef LL<value_type> self;

  LLRoot() : data(T()), next(NULL) {}

  LLRoor(value_type& data) {
    this->data = data;
    next = NULL;
  }


  self& find(value_type& data) {
    while (this != NULL) {
      if (data == this->data) {
        return *this;
      }
      this = next;
    }
  }


private:
  self* next;
  T data;

};