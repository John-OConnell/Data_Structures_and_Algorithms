//
// stack.c - A simple stack data structure
//
// Implementation by John O'Connell
// Email: jpoconnell24(@t)gmail(d 0 t)com
//
//

#include <stdio.h> 
#include <stdbool.h>
#include "stack.h"

/*
 * Checks whether the stack is empty.
 *
 * @param s: pointer to the stack array
 * @param t: top valid location in stack
 * 
 * @return: true if stack is empty
 *          false if stack is not empty
 * 
 */
bool isEmpty (int* s, int t) {
  // returns true if t = -1
  return (t < 0);
}

/*
 * Checks whether the stack is full.
 *
 * @param s: pointer to the stack array
 * @param t: top valid location in stack
 * 
 * @return: true if stack is full
 *          false if stack is not full
 * 
 */
bool isFull (int* s, int t) {
  // returns true if no more room in the stack
  return (t >=  MAXSIZE-1);
}

/*
 * Adds an element to the top of the stack.
 *
 * @param v: element to be added to the stack
 * @param s: pointer to the stack array
 * @param tp: pointer to top valid location in stack
 * 
 * @return: 0 on success
 *          1 on failure
 * 
 */
int push (int v, int* s, int* tp) {
  // put v onto the top of the stack s unless it is already full
  if ( !isFull(s, *tp) )
  {
    (*tp)++;
    s[*tp] = v;
    return 0;
  }
  return 1;
}

/*
 * Removes the topmost element from the stack.
 *
 * @param s: pointer to the stack array
 * @param tp: pointer to top valid location in stack
 * 
 * @return returnval: topmost element or -1 on failure
 * 
 */
int pop (int* s, int* tp) {
  // return the top entry in the stack unless stack is empty
  // update s and *tp -- requires top to be passed by reference!
  int returnval = -1;
  if (!isEmpty(s, *tp))
  {
	  returnval = s[*tp];
	  (*tp)--;
  }
  return returnval;
}

int main () {

  int stack1[MAXSIZE]; // array in which stack will live
  int top1 = -1;       // top valid location in stack, -1 == empty
  int stack2[MAXSIZE]; // array in which stack will live
  int top2 = -1;       // top valid location in stack, -1 == empty
  
  printf("pushing: 1, 2, 3, 4, 5 onto first stack\n");
  printf("pushing: 100, 200, 300, 400, 500 onto second stack\n\n");
  push(1, stack1, &top1);
  push(2, stack1, &top1);
  push(3, stack1, &top1);
  push(4, stack1, &top1);
  push(5, stack1, &top1);
  push(100, stack2, &top2);
  push(200, stack2, &top2);
  push(300, stack2, &top2);
  push(400, stack2, &top2);
  push(500, stack2, &top2);

  printf("popping alternating stacks:\n");
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  return 0;
}
