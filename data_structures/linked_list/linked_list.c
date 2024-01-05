//
// linked_list.c - A linked list data structure
//
// Implementation by John O'Connell
// Email: jpoconnell24(@t)gmail(d 0 t)com
//
//

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
 * Creates a node of a linked list
 * 
 * @param num: value for the node to store
 * 
 * @return newNode: an instance of a node or NULL if operation fails
 * 
 */
node_t* create_node(int num){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL)
    {
	    return NULL;
    }
    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

/*
 * Creates an instance of a linked list
 * 
 * @return l: an instance of a linked list or NULL if operation fails
 * 
 */
list_t* create_LL(){
    list_t* l = (list_t*)malloc(sizeof(list_t));
    if(l == NULL)
    {
	    return NULL;
    }
    l->head = NULL;
    l->size = 0;
    return l;
}

/*
 * Inserts a node at the beginning of the list
 * 
 * @param l: an instance of a linked list
 * @param data: value for the new node to store
 * 
 */
void insert_first(list_t* l, int data){
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    node_t* newNode = create_node(data);
    if(l->head == NULL)
    {
	    l->head = newNode;
        l->size++;
	    return;
    }
    newNode->next = l->head;
    l->head = newNode;
    l->size++;
    return;
}

/*
 * Inserts a node at the end of the list
 * 
 * @param l: an instance of a linked list
 * @param data: value for the new node to store
 * 
 */
void insert_last(list_t* l, int data){
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    node_t* newNode = create_node(data);
    if(l->head == NULL)
    {
        l->head = newNode;
        l->size++;
        return;
    }

    node_t* temp = l->head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    l->size++;
    return;
}

/*
 * Inserts a node at a specified position
 * 
 * @param l: an instance of a linked list
 * @param data: value for the new node to store
 * @param pos: position to insert the node
 * 
 */
void insert_pos(list_t* l, int data, int pos){
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    if(pos < 0 || pos > l->size)
    {
        printf("Position out of list range.\n");
        return;
    }
    else if(pos == 0)
    {
        insert_first(l, data);
        return;
    }
    else if(pos == l->size)
    {
        insert_last(l, data);
        return;
    }
    else
    {
        node_t* newNode = create_node(data);
        node_t* temp = l->head;
        for(int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        l->size++;
        return;
    }
}

/*
 * Removes the node at the beginning of the list
 * 
 * @param l: an instance of a linked list
 * 
 */
void remove_first(list_t* l){
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    if(l->head == NULL)
    {
	    return;
    }
    node_t* temp = l->head;
    l->head = l->head->next;
    free(temp);
    l->size--;
    return;
}

/*
 * Removes the node at the end of the list
 * 
 * @param l: an instance of a linked list
 * 
 */
void remove_last(list_t* l){
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    if(l->head == NULL)
    {
        return;
    }
    else if(l->head->next == NULL)
    {
        remove_first(l);
        return;
    }
    else{
        node_t* temp = l->head->next;
        node_t* prev = l->head;
        while(temp->next != NULL)
        {
            temp = temp->next;
            prev = prev->next;
        }
        prev->next = NULL;
        free(temp);
        l->size--;
        return;
    }
}

/*
 * Removes a node at a specified position
 * 
 * @param l: an instance of a linked list
 * @param pos: position to remove the node
 * 
 */
void remove_pos(list_t* l, int pos){
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    if(pos < 0 || pos >= l->size)
    {
        printf("Position out of list range.\n");
        return;
    }
    else if(pos == 0)
    {
        remove_first(l);
        return;
    }
    else if(pos == l->size - 1)
    {
        remove_last(l);
        return;
    }
    else
    {
        node_t* temp = l->head->next;
        node_t* prev = l->head;
        for(int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
            prev = prev->next;
        }
        prev->next = temp->next;
        free(temp);
        l->size--;
        return;
    }
}

/*
 * Searches for a node in the list
 * 
 * @param l: an instance of a linked list
 * @param data: value to search for in the list
 * 
 */
bool search_list(list_t* l, int data){
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return false;
    }

    if(l->head == NULL)
    {
        return false;
    }

    node_t* temp = l->head;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}


/*
 * Prints a linked list
 * 
 * @param l: an instance of a linked list
 * 
 */
void print_list(list_t* l)
{
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    node_t* temp = l->head;

    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*
 * Reverses a linked list
 * 
 * @param l: an instance of a linked list
 * 
 */
void reverse_list(list_t* l)
{
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return;
    }
    else
    {
        node_t* prev = NULL;
        node_t* curr = l->head;
        node_t* next = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l->head = prev;
        return;
    }  
}

/*
 * Frees a linked list
 * 
 * @param l: an instance of a linked list
 * 
 */
void free_list(list_t* l){
    if(l == NULL)
    {
        fprintf(stderr, "List is NULL.\n");
        return;
    }

    node_t* temp;
    while(l->head)
    {
        temp = l->head->next;
        free(l->head);
        l->head = temp;
    }
    free(l);
    return;
}
