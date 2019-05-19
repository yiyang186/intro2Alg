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
  TreeNode<T>* search(const T key) const;
  TreeNode<T>* minimum(TreeNode<T> *subRoot=nullptr) const;
  TreeNode<T>* maximum(TreeNode<T> *subRoot=nullptr) const;
  TreeNode<T>* successor(const TreeNode<T> *node) const;
  TreeNode<T>* predecessor(const TreeNode<T> *node) const;
  void remove(TreeNode<T> *node);
private:
  void inOrederWalk(const TreeNode<T> *node) const;
  void transplant(TreeNode<T> *originNode, TreeNode<T> *newNode);
  TreeNode<T> *root;
};

}

#endif
