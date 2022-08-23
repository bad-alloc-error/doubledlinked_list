#include "include/linked.h"
#include <stdlib.h>
#include <stdio.h>
int main(){

    linked_list_t* ll = init();
    insert(ll, 638);
    insert(ll, 250);
    insert(ll, 1000);
    insert(ll, 475);
    insert(ll, 600);
    insert(ll, 4535);
    insert(ll, 344);
    insert(ll, 1);
    // insert_at_any_point(ll, 636, 250);
    print(ll);
    remove_node(ll,638);
    remove_last(ll);
    print(ll);
    // remove_node(ll, 344);
    // print(ll);
    // remove_node(ll, 1);
    // print(ll);
    // node_t* removido4 = remove_node(ll, 4535);
    // free(removido4);
    // print(ll);


}