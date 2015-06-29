#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 12
#define NIL -1

void printQueue(int array[], int head, int tail)
{
    for (int i = 0; i < MAX_NUM; i++) {
        if (NIL != array[i])
            printf("%3d\t", array[i]);
        else
            printf("NIL\t");
    }
    printf("\n");

    if (head <= tail) {
        for (int i = head - 1; i < tail - 1; i++)
            printf("%3d\t", array[i]);
    }
    else {
        for (int i = head - 1; i < MAX_NUM; i++)
            printf("%3d\t", array[i]);
        for (int i = 0; i < tail - 1; i++)
            printf("%3d\t", array[i]);
    }

    printf("\n");
}

void backEnqueue(int array[], int head, int* tail, int key)
{
    if (head == (*tail) + 1) {
        printf("overflow\n");
        exit(-1);
    } else {
        array[(*tail) - 1] = key;
        
        if (MAX_NUM == (*tail))
            *tail = 1;
        else
            (*tail)++;
    }
}

int frontDequeue(int array[], int* head, int tail)
{
    if (tail == (*head)) {
        printf("underflow\n");
        exit(-1);
    } else {
        int key = array[(*head) - 1];

        if (MAX_NUM == (*head))
            *head = 1;
        else
            (*head)++;

        return key;
    }
}

void frontEnqueue(int array[], int *head, int tail, int key)
{
    if ((*head) == tail + 1) {
        printf("overflow\n");
        exit(-1);
    } else {
        if (1 == (*head))
            *head = MAX_NUM;
        else
            (*head)--;
        
        array[(*head) - 1] = key;
    }
}

int backDequeue(int array[], int head, int* tail)
{
    if (head == (*tail)) {
        printf("underflow\n");
        exit(-1);
    } else {
        if (1 == (*tail))
            *tail = MAX_NUM;
        else
            (*tail)--;

        int key = array[(*tail) - 1];

        return key;
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {NIL, NIL, NIL, NIL, NIL, NIL, 15, 6, 9, 8, 4, NIL};

    int head = 7;
    int tail = 12;
    printf("the deque is:\n");
    printQueue(test_array, head, tail);

    backEnqueue(test_array, head, &tail, 17);
    printf("after back enqueue 17, deque is:\n");
    printQueue(test_array, head, tail);

    frontEnqueue(test_array, &head, tail, 3);
    printf("after front enqueue 3, deque is:\n");
    printQueue(test_array, head, tail);

    backDequeue(test_array, head, &tail);
    printf("after back dequeue, deque is:\n");
    printQueue(test_array, head, tail);
    
    backEnqueue(test_array, head, &tail, 5);
    printf("after back enqueue 5, deque is:\n");
    printQueue(test_array, head, tail);

    frontDequeue(test_array, &head, tail);
    printf("after front dequeue, deque is:\n");
    printQueue(test_array, head, tail);
    
    return 0;
}
