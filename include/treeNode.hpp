#ifndef _TREE_NODE_HPP_
#define _TREE_NODE_HPP_

namespace tree {

template<typename T>
struct TreeNode {
  TreeNode(T val);
  ~TreeNode();

  T key;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;
};

}

#endif
