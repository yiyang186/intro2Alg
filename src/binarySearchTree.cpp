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
    cout << node->key;
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

void activateBinarySearchTree() {
  BinarySearchTree<int> bst;
  bst.insert(10);
  bst.print();
}
}
