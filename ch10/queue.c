#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6
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

void enqueue(int array[], int head, int* tail, int key)
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

int dequeue(int array[], int* head, int tail)
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

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {NIL, NIL, NIL, NIL, NIL, NIL};

    int head = 1;
    int tail = 1;
    printf("the stack is:\n");
    printQueue(test_array, head, tail);

    enqueue(test_array, head, &tail, 4);
    enqueue(test_array, head, &tail, 1);
    enqueue(test_array, head, &tail, 3);
    printf("after enqueue 4, 1 and 3, stack is:\n");
    printQueue(test_array, head, tail);

    dequeue(test_array, &head, tail);
    printf("after dequeue, stack is:\n");
    printQueue(test_array, head, tail);
    
    enqueue(test_array, head, &tail, 8);
    printf("after enqueue 8, stack is:\n");
    printQueue(test_array, head, tail);

    dequeue(test_array, &head, tail);
    printf("after dequeue, stack is:\n");
    printQueue(test_array, head, tail);
    
    return 0;
}
