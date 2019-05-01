#include <stdio.h>
#include "arraylist.h"

int main(){
  struct ArrayList* arraylist = create_arraylist();
  add(arraylist, 11);
  add(arraylist, 12);
  add(arraylist, 13);
  add(arraylist, 14);
  add(arraylist, 15);
  add(arraylist, 16);
  printf("getting index %d value = %d\n", 3, get(arraylist, 3));
  printf("getting index %d value = %d\n", 0, get(arraylist, 0));

  printf("adding at index %d value %d\n", 3, 1000);
  addAt(arraylist, 3, 1000);

  
  print_arraylist(arraylist);
  printf("size %d\n", arraylist->currentSize);

  printf("removing element at index %d\n", 5);
  remov(arraylist, 5);
  print_arraylist(arraylist);
  printf("size %d\n", arraylist->currentSize);

  printf("appending %d\n", 455);
  add(arraylist, 455);
  print_arraylist(arraylist);
  printf("size %d\n", arraylist->currentSize);

  printf("indexOf(%d) = %d\n", 14, indexOf(arraylist, 14));

  printf("removing %d\n", 16);
  remov_value(arraylist, 16);
  print_arraylist(arraylist);
  printf("size %d\n", arraylist->currentSize);

  free_arraylist(arraylist);
  printf("All done\n");

  return 0;
}
