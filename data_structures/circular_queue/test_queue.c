//
// test_queue.c - Tests for the circular queue data structure
//
// Implementation by John O'Connell
// Email: jpoconnell24(@t)gmail(d 0 t)com
//
//

// TODO: Add additional tests

#include <stdio.h>
#include "circular_queue.h"

#define TEST_PASS 1
#define TEST_FAIL 0

// Test that a new queue was created and the capacity was properly set.
int unitTest0()
{
    queue_t *testq = create_queue(30);
    if (30 == testq->capacity)
    {
        return TEST_PASS;
    }

    free_queue(testq);

    return TEST_FAIL;
}

// Test adding multiple items to a queue
int unitTest1()
{
    queue_t *testq = create_queue(10);
    enqueue(testq, 1);
    enqueue(testq, 2);
    enqueue(testq, 3);
    enqueue(testq, 4);
    enqueue(testq, 5);
    enqueue(testq, 6);
    enqueue(testq, 7);
    enqueue(testq, 8);
    enqueue(testq, 9);
    enqueue(testq, 10);
    if (10 == queue_size(testq))
    {
        free_queue(testq);
        return TEST_PASS;
    }

    free_queue(testq);
    return TEST_FAIL;
}

// Test enqueing and dequeing
int unitTest2(int status)
{
    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        dequeue(testq);
    }
    if (0 == queue_size(testq))
    {
        free_queue(testq);
        return TEST_PASS;
    }

    free_queue(testq);
    return TEST_FAIL;
}

// Test peek function
int unitTest3(int status)
{
    queue_t *testq = create_queue(10);
    enqueue(testq, 4);
    enqueue(testq, 3);
    enqueue(testq, 2);
    enqueue(testq, 1);

    int peekVal = peek(testq);

    if (peekVal == 4)
    {
        free_queue(testq);
        return TEST_PASS;
    }

    free_queue(testq);
    return TEST_FAIL;
}

// Test enqueing and dequeing multiple times
int unitTest4(int status)
{
    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        dequeue(testq);
    }
    for (i = 0; i < 32; i++)
    {
        enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        dequeue(testq);
    }

    if (0 == queue_size(testq))
    {
        free_queue(testq);
        return TEST_PASS;
    }

    free_queue(testq);
    return TEST_FAIL;
}

// Test isFull function
int unitTest5(int status)
{
    queue_t *testq = create_queue(1);
    enqueue(testq, 1);
    if (isFull(testq) != 1)
    {
        free_queue(testq);
        return TEST_FAIL;
    }

    dequeue(testq);
    if (isFull(testq) != 0)
    {
        free_queue(testq);
        return TEST_FAIL;
    }

    free_queue(testq);
    return TEST_PASS;
}

// Test isEmpty function
int unitTest6(int status)
{
    queue_t *testq = create_queue(2);
    dequeue(testq);
    if (isEmpty(testq) != 1)
    {
        free_queue(testq);
        return TEST_FAIL;
    }

    enqueue(testq, 1);
    if (isEmpty(testq) != 0)
    {
        free_queue(testq);
        return TEST_FAIL;
    }

    free_queue(testq);
    return TEST_PASS;
}

int (*unitTests[])() = {
    unitTest0,
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    NULL};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    int testsPassed = 0;
    int counter = 0;

    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter]())
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}
