#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 10
#define NIL -1

typedef struct {
    int array[MAX_NUM];
    int head;
    int tail;
} queue;

void printQueue(queue q)
{
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

void push(queue* queue_a, queue* queue_b, int key)
{
    if (queue_a->tail == queue_b->head) {
        if (queue_b->tail + 1 == queue_b->head) {
            printf("underflow\n");
            exit(-1);
        } else {
            enqueue(queue_b, key);
        }
    }
    else if (queue_b->tail == queue_b->head) {
        if (queue_a->tail + 1 == queue_a->head) {
            printf("underflow\n");
            exit(-1);
        } else {
            enqueue(queue_a, key);
        }
    }
}

int pop(queue* queue_a, queue* queue_b)
{
    if (queue_a->tail == queue_a->head) {
        if (queue_b->tail == queue_b->head) {
            printf("underflow86\n");
            exit(-1);
        } else {
            while (queue_b->head + 1 != queue_b->tail)
                enqueue(queue_a, dequeue(queue_b));
        }

        return dequeue(queue_b);
    }
    else if (queue_b->tail == queue_b->head) {
        if (queue_a->tail == queue_a->head) {
            printf("underflow97\n");
            exit(-1);
        } else {
            while (queue_a->head + 1 != queue_a->tail)
                enqueue(queue_b, dequeue(queue_a));
        }

        return dequeue(queue_a);
    }
    else {
        printf("queue error\n");
        exit(-1);
    }
}

int main(int argc, char* argv[])
{
    queue qa, qb;
    for (int i = 0; i < MAX_NUM; i++) {
        qa.array[i] = NIL;
        qb.array[i] = NIL;
    }
    qa.head = 1;
    qa.tail = 1;
    qb.head = 1;
    qb.tail = 1;

    push(&qa, &qb, 4);
    push(&qa, &qb, 1);
    push(&qa, &qb, 3);
    printf("after push 4, 1 and 3, stack is:\n");
    printf("a-head: %d, a-tail: %d\n", qa.head, qa.tail);
    printf("b-head: %d, b-tail: %d\n", qb.head, qb.tail);
    printQueue(qa);
    printQueue(qb);

    pop(&qa, &qb);
    printf("after pop, stack is:\n");
    printf("a-head: %d, a-tail: %d\n", qa.head, qa.tail);
    printf("b-head: %d, b-tail: %d\n", qb.head, qb.tail);
    printQueue(qa);
    printQueue(qb);
    
    push(&qa, &qb, 8);
    printf("after push 8, stack is:\n");
    printf("a-head: %d, a-tail: %d\n", qa.head, qa.tail);
    printf("b-head: %d, b-tail: %d\n", qb.head, qb.tail);
    printQueue(qa);
    printQueue(qb);

    pop(&qa, &qb);
    printf("after pop, stack is:\n");
    printf("a-head: %d, a-tail: %d\n", qa.head, qa.tail);
    printf("b-head: %d, b-tail: %d\n", qb.head, qb.tail);
    printQueue(qa);
    printQueue(qb);
    
    return 0;
}
