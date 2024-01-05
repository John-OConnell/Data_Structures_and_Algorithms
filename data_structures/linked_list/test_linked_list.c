//
// test_linked_list.c - Tests for the linked list data structure
//
// Implementation by John O'Connell
// Email: jpoconnell24(@t)gmail(d 0 t)com
//
//

// TODO: Add additional tests

#include <stdio.h>
#include "linked_list.h"

#define TEST_PASS 1
#define TEST_FAIL 0

// Test that a new linked list was created
int unitTest0()
{
    list_t* myList = create_LL();
    if (myList != NULL)
    {
        free_list(myList);
        return TEST_PASS;
    }
    return TEST_FAIL;
}

// Test adding to front of linked list
int unitTest1()
{
    list_t* myList = create_LL();
    insert_first(myList, 3);
    insert_first(myList, 2);
    insert_first(myList, 1);
    if (3 == myList->size)
    {
        print_list(myList);
        free_list(myList);
        return TEST_PASS;
    }
    free_list(myList);
    return TEST_FAIL;
}

// Test adding to back of linked list
int unitTest2()
{
    list_t* myList = create_LL();
    insert_last(myList, 1);
    insert_last(myList, 2);
    insert_last(myList, 3);
    if (3 == myList->size)
    {
        print_list(myList);
        free_list(myList);
        return TEST_PASS;
    }
    free_list(myList);
    return TEST_FAIL;
}

// Test adding to specifc position in linked list
int unitTest3()
{
    list_t* myList = create_LL();
    insert_pos(myList, 1, 0);
    insert_pos(myList, 3, 1);
    insert_pos(myList, 2, 1);
    if (3 == myList->size)
    {
        print_list(myList);
        free_list(myList);
        return TEST_PASS;
    }
    free_list(myList);
    return TEST_FAIL;
}

// Test removing from front of linked list
int unitTest4()
{
    list_t* myList = create_LL();
    insert_first(myList, 3);
    insert_first(myList, 2);
    insert_first(myList, 1);
    remove_first(myList);
    if (2 == myList->size)
    {
        print_list(myList);
        free_list(myList);
        return TEST_PASS;
    }
    free_list(myList);
    return TEST_FAIL;
}

// Test removing from back of linked list
int unitTest5()
{
    list_t* myList = create_LL();
    insert_first(myList, 3);
    insert_first(myList, 2);
    insert_first(myList, 1);
    remove_last(myList);
    if (2 == myList->size)
    {
        print_list(myList);
        free_list(myList);
        return TEST_PASS;
    }
    free_list(myList);
    return TEST_FAIL;
}

// Test removing from back of linked list
int unitTest6()
{
    list_t* myList = create_LL();
    insert_first(myList, 3);
    insert_first(myList, 2);
    insert_first(myList, 1);
    remove_pos(myList, 1);
    if (2 == myList->size)
    {
        print_list(myList);
        free_list(myList);
        return TEST_PASS;
    }
    free_list(myList);
    return TEST_FAIL;
}

// Test searching linked list
int unitTest7()
{
    list_t* myList = create_LL();
    insert_first(myList, 4);
    insert_first(myList, 3);
    insert_first(myList, 2);
    insert_first(myList, 1);
    if (search_list(myList, 2))
    {
        free_list(myList);
        return TEST_PASS;
    }
    free_list(myList);
    return TEST_FAIL;
}

// Test reversing linked list
int unitTest8()
{
    list_t* myList = create_LL();
    insert_first(myList, 4);
    insert_first(myList, 3);
    insert_first(myList, 2);
    insert_first(myList, 1);

    print_list(myList);
    reverse_list(myList);
    print_list(myList);
    free_list(myList);

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
    unitTest7,
    unitTest8,
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
