#include "tests/base/utils.h"
#include "bns.h"

int main() {
  bn_node_t n1 = bn_create_node();
  bn_node_t n2 = bn_create_node();
  bn_node_t n3 = bn_create_node();
  bn_node_t n4 = bn_create_node();
  bn_node_t n5 = bn_create_node();
  n3->left = n2;
  n2->top = n3;
  n3->right = n4;
  n4->top = n3;
  n2->left = n1;
  n1->top = n2;
  n4->right = n5;
  n5->top = n4;
  /*
        n3
      n2  n4
    n1      n5
  */
  CHECK_MSG(bn_next_inorder(n1) == n2, "Failed successof of n1");
  CHECK_MSG(bn_next_inorder(n2) == n3, "Failed successof of n2");
  CHECK_MSG(bn_next_inorder(n3) == n4, "Failed successof of n3");
  CHECK_MSG(bn_next_inorder(n4) == n5, "Failed successof of n4");
  CHECK_MSG(bn_next_inorder(n5) == NULL_PTR, "Failed successof of n5");

  CHECK_MSG(bn_prev_inorder(n1) == NULL_PTR, "Failed predecessor of n1");
  CHECK_MSG(bn_prev_inorder(n2) == n1, "Failed predecessor of n2");
  CHECK_MSG(bn_prev_inorder(n3) == n2, "Failed predecessor of n3");
  CHECK_MSG(bn_prev_inorder(n4) == n3, "Failed predecessor of n4");
  CHECK_MSG(bn_prev_inorder(n5) == n4, "Failed predecessor of n5");
  bn_free_node(n1);
  bn_free_node(n2);
  bn_free_node(n3);
  bn_free_node(n4);
  bn_free_node(n5);
  return 0;
}
