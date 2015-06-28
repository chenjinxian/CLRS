#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6

void printStack(int array[], int top)
{
    for (int i = 0; i < top; i++)
        printf("%d\t", array[i]);
    printf("\n");
}

bool stackEmpty(int array[], int top)
{
    if (0 == top)
        return true;
    else
        return false;
}

void push(int array[], int* top, int key)
{
    if (MAX_NUM == (*top)) {
        printf("overflow\n");
        exit(-1);
    } else {
        (*top)++;
        array[(*top) - 1] = key;
    }
}

int pop(int array[], int* top)
{
    if (stackEmpty(array, *top)) {
        printf("underflow\n");
        exit(-1);
    } else {
        (*top)--;
        return array[(*top)];
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {0};

    int top = 0;
    printf("the stack is:\n");
    printStack(test_array, top);

    push(test_array, &top, 4);
    push(test_array, &top, 1);
    push(test_array, &top, 3);

    printf("after push 4 , 1 and 3, stack is:\n");
    printStack(test_array, top);

    pop(test_array, &top);
    printf("after pop, stack is:\n");
    printStack(test_array, top);
    
    push(test_array, &top, 8);
    printf("after push 8, stack is:\n");
    printStack(test_array, top);

    pop(test_array, &top);
    printf("after pop, stack is:\n");
    printStack(test_array, top);
    
    return 0;
}
