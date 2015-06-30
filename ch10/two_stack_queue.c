#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6

typedef struct {
    int array[MAX_NUM];
    int top;
} stack;

void printStack(stack s)
{
    for (int i = 0; i < s.top; i++)
        printf("%d\t", s.array[i]);
    printf("\n");
}

bool stackEmpty(stack s)
{
    if (0 == s.top)
        return true;
    else
        return false;
}

void push(stack* s, int key)
{
    if (MAX_NUM == (s->top)) {
        printf("overflow\n");
        exit(-1);
    } else {
        s->top++;
        s->array[s->top - 1] = key;
    }
}

int pop(stack* s)
{
    if (stackEmpty(*s)) {
        printf("underflow\n");
        exit(-1);
    } else {
        s->top--;
        return s->array[s->top];
    }
}

void enqueue(stack* stack_b, int key)
{
    if (MAX_NUM == (stack_b->top)) {
        printf("overflow\n");
        exit(-1);
    } else {
        //push key into stack_b
        push(stack_b, key);
    }
}

int dequeue(stack* stack_a, stack* stack_b)
{
    if (stackEmpty(*stack_a) && stackEmpty(*stack_b)) {
        printf("underflow\n");
        exit(-1);
    }

    //if stack a is empty, pop every element of stack a and push into stack b
    //else just pop stack a
    if (stackEmpty(*stack_a)) {
        while (!stackEmpty(*stack_b)) {
            push(stack_a, pop(stack_b));
        }
    }

    return pop(stack_a);
}

int main(int argc, char* argv[])
{
    stack sa, sb;
    for (int i = 0; i < MAX_NUM; i++) {
        sa.array[i] = 0;
        sb.array[i] = 0;
    }
    sa.top = 0;
    sb.top = 0;

    enqueue(&sb, 4);
    enqueue(&sb, 1);
    enqueue(&sb, 3);

    printf("after enqueue 4 , 1 and 3, stack is:\n");
    printStack(sa);
    printStack(sb);

    dequeue(&sa, &sb);
    printf("after dequeue, stack is:\n");
    printStack(sa);
    printStack(sb);
    
    enqueue(&sb, 8);
    printf("after enqueue 8, stack is:\n");
    printStack(sa);
    printStack(sb);

    dequeue(&sa, &sb);
    printf("after dequeue, stack is:\n");
    printStack(sa);
    printStack(sb);
    
    return 0;
}
