//
// linked_list.h - A linked list data structure
//
// Implementation by John O'Connell
// Email: jpoconnell24(@t)gmail(d 0 t)com
//
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

typedef struct list{
    struct node* head;
    int size;
}list_t;

node_t* create_node(int num);

list_t* create_LL();

void insert_first(list_t* l, int data);

void insert_last(list_t* l, int data);

void insert_pos(list_t* l, int data, int pos);

void remove_first(list_t* l);

void remove_last(list_t* l);

void remove_pos(list_t* l, int pos);

bool search_list(list_t* l, int data);

void print_list(list_t* l);

void reverse_list(list_t* l);

void free_list(list_t* l);

#endif
