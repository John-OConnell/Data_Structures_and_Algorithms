//
// circular_queue.c - A circular queue data structure
//
// Implementation by John O'Connell
// Email: jpoconnell24(@t)gmail(d 0 t)com
//
//

#include <stdlib.h>
#include <stdio.h>
#include "circular_queue.h"

/*
 * Creates an instance of a circular queue
 * 
 * @param capacity: the maximum capacity of the queue
 * 
 * @return myQueue: an instance of a circular queue or NULL if operation fails
 * 
 */
queue_t* create_queue(unsigned int capacity){
    // allocation of the queue struct
    queue_t* myQueue = (queue_t*)malloc(sizeof(queue_t));
    if (myQueue == NULL)
    {
        return NULL;
    }
    // initialize the fields of the struct
    myQueue->back = 0;
    myQueue->front = 0;
    myQueue->size = 0;
    myQueue->capacity = capacity;
    myQueue->data = (int*)malloc(capacity * sizeof(int));
    return myQueue;
}

/*
 * Checks whether the queue is empty
 * 
 * @param q: an instance of the queue data structure
 * 
 * @return: 1 if queue is empty
 *          0 if queue is not empty
 *         -1 if the queue is NULL
 * 
 */
int isEmpty(queue_t *q){
    if (q == NULL)
    {
        return -1;
    }

    return q->size == 0;
}

/*
 * Checks whether the queue is full
 * 
 * @param q: an instance of the queue data structure
 * 
 * @return: 1 if queue is full
 *          0 if queue is not full
 *         -1 if the queue is NULL
 * 
 */
int isFull(queue_t *q){
    if (q == NULL)
    {
        return -1;
    }

    return q->size == q->capacity;
}

/*
 * Get the data at the front of the queue
 * 
 * @param q: an instance of the queue data structure
 * 
 * @return: data at the front of the queue or -1 if queue is empty or NULL
 * 
 */
int peek(queue_t *q){
    if (q == NULL || q->size == 0)
    {
        return -1;
    }

    return q->data[q->front];
}

/*
 * Inserts elements onto the queue
 * 
 * @param q: an instance of the queue data structure
 * 
 * @return: 0 on success
 *         -1 on failure
 * 
 */
int enqueue(queue_t *q, int item){
    if (q == NULL || q->size == q->capacity)
    {
        return -1;
    }

    q->data[q->back] = item;
    q->back = (q->back + 1) % q->capacity;
    q->size++;

    return 0;
}

/*
 * Removes an element from the queue
 * 
 * @param q: an instance of the queue data structure
 * 
 * @return result: element removed from the queue or -1 on failure
 * 
 */
int dequeue(queue_t *q){
    if ((q == NULL) || (q->size == 0))
    {
        return -1;
    }

    int result = q->data[q->front];

    q->data[q->front] = 0;
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    return result;
}

/*
 * Queries the size of a queue
 * 
 * @param q: an instance of the queue data structure
 * 
 * @return: the size of the queue or -1 if queue is NULL
 * 
 */
unsigned int queue_size(queue_t *q){
    if (q == NULL)
    {
        return -1;
    }

    return q->size;
}

/*
 * Frees the circular queue data structure
 * 
 * @param q: an instance of the queue data structure
 * 
 */
void free_queue(queue_t *q){
    free(q->data);
    free(q);
}
