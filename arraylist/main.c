#include <stdio.h>
#include "arraylist.h"


/**
 ** Missing operations: delete(index), add(index), delete_end(), delete_front()
 **/
int main(){
  struct ArrayList* arraylist = create_arraylist();
  add_end(arraylist, 11);
  add_end(arraylist, 12);
  add_end(arraylist, 13);
  add_end(arraylist, 14);
  add_end(arraylist, 15);
  add_end(arraylist, 16);
  add_front(arraylist, 20);
  
  print_arraylist(arraylist);

  free_arraylist(arraylist);
  printf("All done\n");

  return 0;
}
