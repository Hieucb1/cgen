#include "OOP/Sll.c"

int print_i(gtype value) {
  printf("%ld\n", value.i);
  return 0;
}

int main() {
  SllGt list = New(SllGt);
  list->PushBack(list, gtype_i(100));
  list->PushBack(list, gtype_i(1));
  list->PushBack(list, gtype_i(200));
  list->PushFront(list, gtype_i(30));
  list->PushBack(list, gtype_i(1000));
  list->Foreach(list, print_i);
  Delete(SllGt, list);
  return 0;
}