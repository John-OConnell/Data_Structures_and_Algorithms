//
// stack.h - A simple stack data structure
//
// Implementation by John O'Connell
// Email: jpoconnell24(@t)gmail(d 0 t)com
//
//

#define MAXSIZE 100

bool isEmpty (int* s, int t);

bool isFull (int* s, int t);

int push (int v, int* s, int* tp);

int pop (int* s, int* tp);