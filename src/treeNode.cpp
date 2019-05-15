#include "treeNode.hpp"

namespace tree {

template<typename T>
TreeNode<T>::TreeNode(T val): key(val), left(nullptr), right(nullptr), parent(nullptr) {}

template<typename T>
TreeNode<T>::~TreeNode() {
  if(left)
    delete left;
  if(right)
    delete right;
}

void activateTreeNode() {
  TreeNode<int> node(4);
}
}
