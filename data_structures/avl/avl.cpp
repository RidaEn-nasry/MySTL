

#include <iostream>
#include "avl.hpp"
int main() {

  AVL<int> root;
  root.add(12);
  root.add(10);
  root.add(5);
  root.add(6);
  root.dump();

  AVL<int> root2;
  root2 = root;



  return (0);
}
