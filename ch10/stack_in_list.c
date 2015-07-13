#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6

typedef struct element {
    int key;
    struct element *next;
} list, *list_ptr;

typedef struct head {
    struct element *head;
} head, *head_ptr;

void printList(head_ptr ls_head)
{
    list_ptr ls_ele = ls_head->head;
    while (ls_ele != NULL) {
        printf("%d\t", ls_ele->key);
        ls_ele  = ls_ele->next;
    }
    printf("\n");
}

list_ptr listSearch(head_ptr ls_head, int key)
{
    list_ptr ele_x = ls_head->head;
    while (ele_x != NULL && ele_x->key != key)
        ele_x = ele_x->next;

    return ele_x;
}

void push(head_ptr ls_head, list_ptr ele_x)
{
    ele_x->next = ls_head->head;
    ls_head->head = ele_x;
}

int pop(head_ptr ls_head)
{
    list_ptr ele_t = ls_head->head;
    if (ele_t == NULL) {
        printf("underflow\n");
        exit(-1);
    } else {
        ls_head->head = ele_t->next;
        ele_t->next = NULL;
        
        return ele_t->key;
    }
}

int main(int argc, char* argv[])
{
    head_ptr ls_head = (head_ptr)malloc(sizeof(head));
    ls_head->head = NULL;

    list ele_x1;
    ele_x1.key = 1;
    list ele_x2;
    ele_x2.key = 4;
    list ele_x3;
    ele_x3.key = 16;
    list ele_x4;
    ele_x4.key = 9;
    
    push(ls_head, &ele_x1);
    push(ls_head, &ele_x2);
    push(ls_head, &ele_x3);
    push(ls_head, &ele_x4);
    printf("after push 1, 4, 16, 9, stack is:\n");
    printList(ls_head);

    int ele = pop(ls_head);
    printf("after pop, stack is:\n");
    printList(ls_head);

    free(ls_head);
    ls_head = NULL;
    return 0;
}
