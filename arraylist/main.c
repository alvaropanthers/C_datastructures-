#include <stdio.h>
#include "arraylist.h"

int main(){
  struct ArrayList* arraylist = ArrayList_create_arraylist();
  ArrayList_add(arraylist, 11);
  ArrayList_add(arraylist, 12);
  ArrayList_add(arraylist, 13);
  ArrayList_add(arraylist, 14);
  ArrayList_add(arraylist, 15);
  ArrayList_add(arraylist, 16);
  printf("getting index %d value = %d\n", 3, ArrayList_get(arraylist, 3));
  printf("getting index %d value = %d\n", 0, ArrayList_get(arraylist, 0));

  printf("adding at index %d value %d\n", 3, 1000);
  ArrayList_add_at(arraylist, 3, 1000);

  
  ArrayList_print_arraylist(arraylist);
  printf("size %ld\n", ArrayList_size(arraylist));

  printf("removing element at index %d\n", 5);
  ArrayList_remov(arraylist, 5);
  ArrayList_print_arraylist(arraylist);
  printf("size %ld\n", ArrayList_size(arraylist));

  printf("appending %d\n", 455);
  ArrayList_add(arraylist, 455);
  ArrayList_print_arraylist(arraylist);
  printf("size %ld\n", ArrayList_size(arraylist));

  printf("indexOf(%d) = %d\n", 14, ArrayList_index_of(arraylist, 14));

  printf("removing %d\n", 16);
  ArrayList_remov_value(arraylist, 16);
  ArrayList_print_arraylist(arraylist);
  printf("size %ld\n", ArrayList_size(arraylist));

  ArrayList_free_arraylist(arraylist);
  printf("All done\n");

  return 0;
}
