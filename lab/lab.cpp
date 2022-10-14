
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class node {
public:
  node(char c) : right(NULL), left(NULL) {
    root->charac = 'c';
    root->parent = NULL;
  };
  node* add_left(node* start, char c) {
    if (!root)
      return NULL;
    node* tmp = root;
    node* parent;
    while (tmp != NULL)
    {
      // if (!tmp->left)
        parent = tmp;
      tmp = tmp->left;
    }
    tmp = new node;
    tmp->charac = c;
    tmp->parent = parent;
    return tmp;
  }
  node* add_right(node* start, char c) {
    node* parent;
    if (!start)
      return NULL;
    node* tmp = start;
    while (tmp != NULL)
    {
      if (!tmp->right)
        parent = tmp;
      tmp = tmp->right;
    }
    tmp = new node;
    tmp->charac = c;
    tmp->parent = parent;
    return tmp;
  }

  size_t size(node* start) {
    if (start == NULL) return 0;
    return 1 + size(start->left) + size(start->right);
  }

  void setChar(char c) {
    charac = c;
  }

private:
  char charac;
  node* root;
  node* right;
  node* left;
  node* parent;
};

int main() {
  node* root = new node;
  root->setChar('1');

  root->add_left(root, '2');
  root->add_right(root, '3');
  root->add_left(root, '4');
  root->add_right(root, '5');
  root->add_left(root, '6');
  std::cout << root->size(root) << std::endl;
  root->size(root);
  return 0;
}
