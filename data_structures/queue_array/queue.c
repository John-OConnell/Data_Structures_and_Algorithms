//
// queue.c - A simple queue data structure using an array
//
// Implementation by John O'Connell
// Email: jpoconnell24(@t)gmail(d 0 t)com
//
//

#include <stdio.h>
#include "queue.h"

int arr[MAXSIZE];
int size = 0;

/*
 * Checks whether the queue is empty.
 * 
 * @return: 1 if queue is empty
 *          0 if queue is not empty
 * 
 */
int isEmpty(){   
    return size == 0;
}

/*
 * Checks whether the queue is full.
 * 
 * @return: 1 if queue is full
 *          0 if queue is not full
 * 
 */
int isFull(){
    return size == MAXSIZE;
}

/*
 * Get the data at the front of the queue
 * 
 * @return peekVal: data at the front of the queue or -1 if queue is empty
 * 
 */
int peek(){
    if(isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int peekVal = arr[0];
    return peekVal;
}

/*
 * Inserts elements onto the queue
 *
 * @param data: element to the add to the queue
 * 
 */
void enqueue(int data){
    if(isFull())
    {
	    printf("Queue is full.\n");
	    return;
    }
    arr[size] = data;
    printf("Enqueued data is: %d\n", arr[size]);
    size++;
}

/*
 * Removes an elements from the queue
 *
 * @return data: element removed from the queue
 * 
 */
int dequeue(){  
    if(isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int data  = arr[0];
    for(int i = 0; i < size - 1; i++)
    {
	    arr[i] = arr[i+1];
    }
    size--;
    return data;
}

/*
 * Displays the elements in the queue
 * 
 */
void printQueue()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/*-----Main program-----*/
int main(){
    /* insert 10 items */
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    printQueue();
    enqueue(11);
    printf("\n");

    for(int i=0; i<MAXSIZE-1; i++)
    {
        printf("Dequeued element is: %d\n",dequeue()); 
    }

    printQueue();
    printf("The element at the front of the queue is: %d\n",peek());
    return 0;
}
