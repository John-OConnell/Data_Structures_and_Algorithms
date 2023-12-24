//
// circular_queue.h - A circular queue data structure
//
// Implementation by John O'Connell
// Email: jpoconnell24(@t)gmail(d 0 t)com
//
//

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

// The main data structure for the queue
typedef struct queue{
    unsigned int back;     // The next free position in the queue
    unsigned int front;    // Current 'head' of the queue
    unsigned int size;     // How many total elements we currently have enqueued.
    unsigned int capacity; // Maximum number of items the queue can hold
    int* data;             // The 'integer' data our queue holds
}queue_t;

queue_t *create_queue(unsigned int capacity);

int isEmpty(queue_t *q);

int isFull(queue_t *q);

int peek(queue_t *q);

int enqueue(queue_t *q, int item);

int dequeue(queue_t *q);

unsigned int queue_size(queue_t *q);

void free_queue(queue_t *q);

#endif
