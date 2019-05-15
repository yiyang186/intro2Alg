#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_

#include <iostream>
#include "treeNode.hpp"

namespace tree {

template<typename T>
class BinarySearchTree {
public:
  BinarySearchTree();
  ~BinarySearchTree();
  void print() const;
  void insert(T val);
private:
  void inOrederWalk(const TreeNode<T> *node) const;

  TreeNode<T> *root;
};

}

#endif
