#include "binarySearchTree.hpp"

using namespace std;
namespace tree {

template<typename T>
BinarySearchTree<T>::BinarySearchTree(): root(nullptr) {}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  if(root)
    delete root;
}

template<typename T>
void BinarySearchTree<T>::inOrederWalk(const TreeNode<T> *node) const {
  if(node != nullptr) {
    inOrederWalk(node->left);
    cout << node->key << ' ';
    inOrederWalk(node->right);
  }
}

template<typename T>
void BinarySearchTree<T>::print() const {
  cout << "BinarySearchTree: ";
  inOrederWalk(root);
  cout << endl;
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::search(const T key) const {
  TreeNode<T> *node = root;
  while(node && node->key != key) {
    if(key < node->key)
      node = node->left;
    else
      node = node->right;
  }
  return node;
}

template<typename T>
void BinarySearchTree<T>::insert(T val) {
  TreeNode<T> *newNode = new TreeNode<T>(val);
  TreeNode<T> *node = root;
  TreeNode<T> *lastNode = nullptr;

  while(node != nullptr) {
    lastNode = node;
    if(newNode->key < node->key)
      node = node->left;
    else
      node = node->right;
  }
  newNode->parent = lastNode;
  if(lastNode == nullptr)
    root = newNode;
  else if(newNode->key < lastNode->key)
    lastNode->left = newNode;
  else
    lastNode->right = newNode;
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::maximum(
    TreeNode<T> *subRoot) const {
  TreeNode<T> *node = subRoot == nullptr? root: subRoot;
  while(node && node->right) node = node->right;
  return node;
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::minimum(
    TreeNode<T> *subRoot) const {
  TreeNode<T> *node = subRoot == nullptr? root: subRoot;
  while(node && node->left) node = node->left;
  return node;
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::successor(
    const TreeNode<T> *node) const {
  if(node && node->right)
    return minimum(node->right);
  
  TreeNode<T> *parent = node->parent;
  while(parent && parent->left != node) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::predecessor(
    const TreeNode<T> *node) const {
  if(node && node->left)
    return maximum(node->left);
  
  TreeNode<T> *parent = node->parent;
  while(parent && parent->right != node) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}

template<typename T>
void BinarySearchTree<T>::transplant(
    TreeNode<T> *originNode, TreeNode<T> *newNode) {
  // if(originNode->parent == nullptr)
  if(originNode == root)
    root = newNode;
  else if(originNode == originNode->parent->left)
    originNode->parent->left = newNode;
  else
    originNode->parent->right = newNode;

  if(newNode)
    newNode->parent = originNode->parent;
}

template<typename T>
void BinarySearchTree<T>::remove(TreeNode<T> *node) {
  if(!node->left)
    transplant(node, node->right);
  else if(!node->right)
    transplant(node, node->left);
  else {
    TreeNode<T> *successNode = minimum(node->right);
    if(successNode->parent != node) {
      transplant(successNode, successNode->right);
      successNode->right = node->right;
      successNode->right->parent = successNode;
    }
    transplant(node, successNode);
    successNode->left = node->left;
    successNode->left->parent = successNode;
  }
}

void activateBinarySearchTree() {
  BinarySearchTree<int> bst;
  bst.insert(10);
  bst.search(10);
  bst.minimum();
  bst.maximum();

  auto node = bst.search(10);
  bst.predecessor(node);
  bst.successor(node);
  bst.remove(node);
  bst.print();
}
}
