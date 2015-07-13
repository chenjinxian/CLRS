#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6
#define NIL -1

typedef struct element {
    int key;
    struct element *prev;
    struct element *next;
} list, *list_ptr;

typedef struct nil {
    struct element *nil;
} nil, *nil_ptr;

void printList(nil_ptr ls_nil)
{
    list_ptr ls_ele = ls_nil->nil->next;
    while (ls_ele!= ls_nil->nil) {
        printf("%d\t", ls_ele->key);
        ls_ele  = ls_ele->next;
    }
    printf("\n");
}

list_ptr listSearch(nil_ptr ls_nil, int key)
{
    list_ptr ele_x = ls_nil->nil->next;
    while (ele_x!= ls_nil->nil && ele_x->key != key)
        ele_x = ele_x->next;

    return ele_x;
}

void listInsert(nil_ptr ls_nil, list_ptr ele_x)
{
    ele_x->next = ls_nil->nil->next;
    ls_nil->nil->next->prev = ele_x;
    ls_nil->nil->next = ele_x;
    ele_x->prev = ls_nil->nil;
}

void listDelete(nil_ptr ls_nil, list_ptr ele_x)
{
    ele_x->prev->next = ele_x->next;
    ele_x->next->prev = ele_x->prev;
}

int main(int argc, char* argv[])
{
    list nil;
    nil.key = NIL;
    nil.next = &nil;
    nil.prev = &nil;

    nil_ptr ls_nil = (nil_ptr)malloc(sizeof(nil));
    ls_nil->nil = &nil;

    list ele_x1;
    ele_x1.key = 1;
    list ele_x2;
    ele_x2.key = 4;
    list ele_x3;
    ele_x3.key = 16;
    list ele_x4;
    ele_x4.key = 9;
    
    listInsert(ls_nil, &ele_x1);
    listInsert(ls_nil, &ele_x2);
    listInsert(ls_nil, &ele_x3);
    listInsert(ls_nil, &ele_x4);
    printList(ls_nil);

    list_ptr ele_find = listSearch(ls_nil, 4);
    if (ele_find != NULL)
        printf("find element of key in 4\n");
    else
        printf("find not element of key in 4\n");
    
    list ele_x5;
    ele_x5.key = 25;
    listInsert(ls_nil, &ele_x5);
    printList(ls_nil);

    if (ele_find != NULL) {
        listDelete(ls_nil, ele_find);
        printList(ls_nil);
    }

    free(ls_nil);
    ls_nil = NULL;
    return 0;
}
