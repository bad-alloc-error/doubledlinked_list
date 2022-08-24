#include<stdlib.h>
#include<stdio.h>
#include"../include/linked.h"

struct node_t{
    int value;
    struct node_t* prev;
    struct node_t* next;
};


struct linked_list_t{
    struct node_t* head;
    struct node_t* tail;
    unsigned int size;
};


linked_list_t* init(void){

    linked_list_t* list = (linked_list_t *)calloc(1, sizeof(linked_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void ordered_insert(linked_list_t* list, int value){
    node_t* node = (node_t *)calloc(1, sizeof(node_t));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;

    if(is_empty(list)){
        root_node(list, value);
    }else if(node->value < list->head->value){
        node->next = list->head;
        list->head = node;
        list->size++;
    }else{
        node_t* current = list->head;
        while(current->next && node->value > current->next->value){
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
        list->size++;
    }  

    if(node->value > list->tail->value){
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
        return;
    }
}

void insert_at_head(linked_list_t* list, int value){

    node_t* node = (node_t *)calloc(1, sizeof(node_t));
    node->next = NULL;
    node->prev = NULL;

    if(is_empty(list)){
        root_node(list, value);
        return;
    }
    node->value = value;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    list->size++;
}

void insert_at_any_point(linked_list_t* list, int value, int prev){
    node_t* node = (node_t *)calloc(1, sizeof(node_t));
    node->next = NULL;
    node->prev = NULL;
    if(node != NULL){
        node_t* current = list->head;
        node->value = value;
        
        while(current->value != prev && current->next){            
            current = current->next;
        }


        node->next = current->next;
        current->next->prev = node;
        node->prev = current;
        current->next = node;
    }

    list->size++;
}

void insert(linked_list_t* list, int value){
    node_t* node = (node_t *)calloc(1, sizeof(node_t));
    
    node->next = NULL;
    node->prev = NULL;    
    
    if(is_empty(list)){

        root_node(list, value);
        return;
    }

    if(node == NULL){
        exit(1);
    }

    node->value = value;
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
    list->size++;
}

void root_node(linked_list_t* list, int value){

        node_t* root = (node_t *)calloc(1, sizeof(node_t));
        
        if(root == NULL){
            exit(1);
        }

        list->head = root;
        list->tail = root;
        root->next = NULL;
        root->prev = NULL;
        root->value = value;
        list->size++;       
}

void remove_last(linked_list_t* list){

    if(is_empty(list)){
        fprintf(stderr, "Lista vazia!\n");
        exit(-1);
    }

    node_t* last = list->tail;
    last->prev->next = NULL;
    list->tail = last->prev;
    list->size--;
    free(last);
}

void remove_node(linked_list_t* list, int value){
    node_t* deleted_node = NULL;

    if(list->size == 1 && list->head->value == value){
        node_t* h = list->head;
        list->head = NULL;
        list->tail = NULL;
        printf("Valor ** %d ** encontrado...deletando.\n", value);
        free(h);
        list->size--;
        return;    
    }

    if(list->tail->value == value){
        node_t* t = list->tail;
        list->tail->prev->next = NULL;
        list->tail = list->tail->prev;
        free(t);
        list->size--;
        return;
    }

    if(is_empty(list) == false){
        if(list->head->value == value){
            deleted_node = list->head;
            list->head = deleted_node->next;
            deleted_node->next->prev = NULL;
            free(deleted_node);
            list->size--;
        }else{
            
            node_t* current = list->head->next;
            while(current && current->value != value){
                current = current->next;
            }

            deleted_node =  current;            
            /*corrige os ponteiros caso há um nó depois no nó a ser removido*/
            if(current->next){
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(deleted_node);
                list->size--;
            }
        }
    }
}

bool is_empty(const linked_list_t* list){

    if(list->head == NULL && list->tail == NULL){
        return true;
    }

    return false;
}

node_t* head_node(const linked_list_t* list){
    return list->head;
}

node_t* tail_node(const linked_list_t* list){
    return list->tail;
}

void print(const linked_list_t* ll){

    int size = ll->size;
    node_t* current = ll->head;

    if(ll->size == 0){
        printf("Lista Vazia!\n");
        return;
    }

    printf("INICIO -> "); 
    while(current != NULL){
        printf("[%d] -> ", current->value);
        current = current->next;
    }
    printf("FIM\n");
    printf("Tamanho da lista: [%d]\n", size);
}

void destroy_list(linked_list_t** list){

    linked_list_t* l = *list;
    node_t* node = l->head;

    while(node){
        node_t* curr = node;
        node = node->next;
        free(curr);
    }

}


