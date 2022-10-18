

#include <iostream>
// #include "avl.hpp"
#include <map>


int main() {

  std::map<int, char> map;
  map[1] = 'a';
  map[2] = 'b';
  map[3] = 'c';

  std::map<int, char>::iterator it = map.begin();

  // increment iterator
  it++;
  
  std::cout << it->first << std::endl;
  // std::cout << *it << std::endl;
  // print it
  
  // std::cout << it->second << std::endl;
  // std::cout << map[1] << std::endl;
  return 0;


};
