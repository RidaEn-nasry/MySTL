

#include <iostream>
#include "avl.hpp"


int main() {

  ft::AVLTree<int> tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.print();
  ft::AVLTree<int> tree2(tree);
  std::cout << "tree2" << std::endl;
  tree2.print();

  return 0;
};
