#ifndef _LINKED_H_
#define _LINKED_H_
#include<stdbool.h>

typedef struct node_t node_t;
typedef struct linked_list_t linked_list_t;

bool is_empty(const linked_list_t* list);
linked_list_t* init(void);
void root_node(linked_list_t* list, int value);
void insert(linked_list_t* list, int value);
void insert_at_head(linked_list_t* list, int value);
void ordered_insert(linked_list_t* list, int value);
void print(const linked_list_t* ll);
void insert_at_any_point(linked_list_t* list, int value, int prev);
node_t* head_node(const linked_list_t* list);
node_t* tail_node(const linked_list_t* list);
void remove_node(linked_list_t* list, int value);
void remove_last(linked_list_t* list);
void destroy_list(linked_list_t** list);

#endif