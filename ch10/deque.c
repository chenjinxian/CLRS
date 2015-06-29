#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 12
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

void backEnqueue(queue* q, int key)
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

int frontDequeue(queue* q)
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

void frontEnqueue(queue* q, int key)
{
    if (q->head == q->tail + 1) {
        printf("overflow\n");
        exit(-1);
    } else {
        if (1 == q->head)
            q->head = MAX_NUM;
        else
            q->head--;
        
        q->array[q->head - 1] = key;
    }
}

int backDequeue(queue* q)
{
    if (q->head == q->tail) {
        printf("underflow\n");
        exit(-1);
    } else {
        if (1 == q->tail)
            q->tail = MAX_NUM;
        else
            q->tail--;

        int key = q->array[q->tail - 1];

        return key;
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {NIL, NIL, NIL, NIL, NIL, NIL, 15, 6, 9, 8, 4, NIL};

    queue q;
    for (int i = 0; i < MAX_NUM; i++)
        q.array[i] = test_array[i];
    q.head = 7;
    q.tail = 12;
    printf("the deque is:\n");
    printQueue(q);

    backEnqueue(&q, 17);
    printf("after back enqueue 17, deque is:\n");
    printQueue(q);

    frontEnqueue(&q, 3);
    printf("after front enqueue 3, deque is:\n");
    printQueue(q);

    backDequeue(&q);
    printf("after back dequeue, deque is:\n");
    printQueue(q);
    
    backEnqueue(&q, 5);
    printf("after back enqueue 5, deque is:\n");
    printQueue(q);

    frontDequeue(&q);
    printf("after front dequeue, deque is:\n");
    printQueue(q);
    
    return 0;
}
