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

int main(int argc, char* argv[])
{
    stack s;
    for (int i = 0; i < MAX_NUM; i++)
        s.array[i] = 0;
    s.top = 0;
    printf("the stack is:\n");
    printStack(s);

    push(&s, 4);
    push(&s, 1);
    push(&s, 3);

    printf("after push 4 , 1 and 3, stack is:\n");
    printStack(s);

    pop(&s);
    printf("after pop, stack is:\n");
    printStack(s);
    
    push(&s, 8);
    printf("after push 8, stack is:\n");
    printStack(s);

    pop(&s);
    printf("after pop, stack is:\n");
    printStack(s);
    
    return 0;
}
