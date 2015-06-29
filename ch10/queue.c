#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6
#define NIL -1

typedef struct {
    int array[MAX_NUM];
    int head;
    int tail;
} queue;

void printQueue(queue q)
{
    for (int i = 0; i < MAX_NUM; i++) {
        if (NIL != q.array[i])
            printf("%3d\t", q.array[i]);
        else
            printf("NIL\t");
    }
    printf("\n");

    if (q.head <= q.tail) {
        for (int i = q.head - 1; i < q.tail - 1; i++)
            printf("%3d\t", q.array[i]);
    }
    else {
        for (int i = q.head - 1; i < MAX_NUM; i++)
            printf("%3d\t", q.array[i]);
        for (int i = 0; i < q.tail - 1; i++)
            printf("%3d\t", q.array[i]);
    }

    printf("\n");
}

void enqueue(queue* q, int key)
{
    if (q->head == q->tail + 1) {
        printf("overflow\n");
        exit(-1);
    } else {
        q->array[q->tail - 1] = key;
        
        if (MAX_NUM == q->tail)
            q->tail = 1;
        else
            q->tail++;
    }
}

int dequeue(queue* q)
{
    if (q->tail == q->head) {
        printf("underflow\n");
        exit(-1);
    } else {
        int key = q->array[q->head - 1];

        if (MAX_NUM == q->head)
            q->head = 1;
        else
            q->head++;

        return key;
    }
}

int main(int argc, char* argv[])
{
    queue q;
    for (int i = 0; i < MAX_NUM; i++)
        q.array[i] = NIL;
    q.head = 1;
    q.tail = 1;
    printf("the queue is:\n");
    printQueue(q);

    enqueue(&q, 4);
    enqueue(&q, 1);
    enqueue(&q, 3);
    printf("after enqueue 4, 1 and 3, stack is:\n");
    printQueue(q);

    dequeue(&q);
    printf("after dequeue, stack is:\n");
    printQueue(q);
    
    enqueue(&q, 8);
    printf("after enqueue 8, stack is:\n");
    printQueue(q);

    dequeue(&q);
    printf("after dequeue, stack is:\n");
    printQueue(q);
    
    return 0;
}
