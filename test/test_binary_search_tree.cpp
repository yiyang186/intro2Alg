#include <gtest/gtest.h>

#include "binarySearchTree.hpp"

using namespace std;
using namespace tree;

TEST(TEST_BINARY_SEARCH_TREE, TestInsert) {
  BinarySearchTree<int> bst;
  bst.insert(15); 
  bst.insert(10); 
  bst.insert(-25); 
  bst.insert(20); 
  bst.insert(5); 
  bst.print();
}
