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
    list_ptr ele_x = ls_head->head;
    while (ele_x != NULL) {
        printf("%d\t", ele_x->key);
        ele_x  = ele_x->next;
    }
    printf("\n");
}

void reverseList(head_ptr ls_head)
{
    list_ptr ele_x = ls_head->head;
    list_ptr ele_temp = NULL;
    list_ptr ele_next = NULL;

    while (ele_x != NULL) {
        ele_temp = ele_next;
        ele_next = ele_x;
        ele_x = ele_x->next;
        ele_next->next = ele_temp;
    }

    ls_head->head = ele_next;
}

list_ptr listSearch(head_ptr ls_head, int key)
{
    list_ptr ele_x = ls_head->head;
    while (ele_x != NULL && ele_x->key != key)
        ele_x = ele_x->next;

    return ele_x;
}

void listInsert(head_ptr ls_head, list_ptr ele_x)
{
    ele_x->next = ls_head->head;
    ls_head->head = ele_x;
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
    
    listInsert(ls_head, &ele_x1);
    listInsert(ls_head, &ele_x2);
    listInsert(ls_head, &ele_x3);
    listInsert(ls_head, &ele_x4);
    printList(ls_head);

    
    printf("After reverse, the list is:\n");
    reverseList(ls_head);
    printList(ls_head);

    free(ls_head);
    ls_head = NULL;
    return 0;
}
