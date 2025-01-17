#include "tests/base/utils.h"

#include "bn.h"

int t1() {
  bn_node_t n1 = bn_create_node();
  bn_node_t n2 = bn_create_node();
  bn_node_t n3 = bn_create_node();
  bn_node_t n4 = bn_create_node();
  bn_node_t n5 = bn_create_node();
  /*
         n3
    n1       n5
      n2   n4
  */
  bn_tree_t t = bn_create_tree(NULL_PTR);
  bn_insert(n3, (&(t->root)), NULL_PTR);
  bn_insert(n1, (&(n3->left)), n3);
  bn_insert(n2, (&(n1->right)), n1);
  bn_insert(n5, (&(n3->right)), n3);
  bn_insert(n4, (&(n5->left)), n5);

  ASSERT(t->root == n3, "root n3");
  ASSERT(t->root->left == n1, "root left n1");
  ASSERT(t->root->right == n5, "root right n5");
  ASSERT(t->root->left->right == n2, "root left right n2");
  ASSERT(t->root->right->left == n4, "root right left n4");
  bn_free_tree(t);
  return 0;
}

int main() {
  ASSERT(t1() == 0, "t1");
  TEST_OK();
}