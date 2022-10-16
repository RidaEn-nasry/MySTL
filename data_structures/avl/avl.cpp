

#include <iostream>
#include "avl.hpp"


int main() {
  ft::AVLTree<int> tree;

  tree.insert(10);
  tree.insert(5);
  tree.insert(11);
  tree.insert(6);
  tree.insert(7);
  return 0;
};
