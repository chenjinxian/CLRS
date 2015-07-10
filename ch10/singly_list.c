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

//same as doubly linked list, INSERT take O(1) time on a singly
void listInsert(head_ptr ls_head, list_ptr ele_x)
{
    ele_x->next = ls_head->head;
    ls_head->head = ele_x;
}

//but unlike doubly, the operation DELETE take O(n) time in singly
//as the search opertation for the PREV of the element x
void listDelete(head_ptr ls_head, list_ptr ele_x)
{
    list_ptr prev = NULL;
    list_ptr ele_t = ls_head->head;
    while (ele_t != NULL && ele_t->key != ele_x->key) {
        prev = ele_t;
        ele_t = ele_t->next;
    }

    if (prev != NULL) {
        prev->next = ele_t->next;
        ele_t->next = NULL;
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
    
    listInsert(ls_head, &ele_x1);
    listInsert(ls_head, &ele_x2);
    listInsert(ls_head, &ele_x3);
    listInsert(ls_head, &ele_x4);
    printList(ls_head);

    list_ptr ele_find = listSearch(ls_head, 4);
    if (ele_find != NULL)
        printf("find element of key in 4\n");
    else
        printf("find not element of key in 4\n");
    
    list ele_x5;
    ele_x5.key = 25;
    listInsert(ls_head, &ele_x5);
    printList(ls_head);

    if (ele_find != NULL) {
        listDelete(ls_head, ele_find);
        printList(ls_head);
    }

    free(ls_head);
    ls_head = NULL;
    return 0;
}
