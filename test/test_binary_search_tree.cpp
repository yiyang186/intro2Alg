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

  auto node = bst.search(20);
  ASSERT_EQ(20, node->key);
  ASSERT_EQ(-25, bst.minimum()->key);
  ASSERT_EQ(20, bst.maximum()->key);

  auto xnode = bst.search(15);
  ASSERT_EQ(10, bst.predecessor(xnode)->key);
  ASSERT_EQ(20, bst.successor(xnode)->key);

  bst.remove(xnode);
  bst.print();
}
