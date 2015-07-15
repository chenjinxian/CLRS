#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6

typedef struct element {
    int key;
    struct element *parent;
    struct element *left;
    struct element *sibling;
} tree, *tree_ptr;

typedef struct root {
    struct element *root;
} root, *root_ptr;

typedef struct {
    tree_ptr array[MAX_NUM];
    int top;
} stack;

void printElement(tree_ptr ts)
{
    if (ts == NULL)
        return;
    else {
        printf("%d\t", ts->key);

        printElement(ts->left);
        printElement(ts->sibling);
    }
}

void printTree(root_ptr ts_root)
{
    printElement(ts_root->root);
    printf("\n");
}

int main(int argc, char* argv[])
{
    tree ele_x1;
    ele_x1.key = 1;
    ele_x1.left = NULL;
    ele_x1.sibling = NULL;

    tree ele_x2;
    ele_x2.key = 4;
    ele_x2.left = &ele_x1;
    ele_x2.sibling = NULL;
    
    root_ptr ts_root = (root_ptr)malloc(sizeof(root));
    ts_root->root = &ele_x2;

    printTree(ts_root);

    free(ts_root);
    ts_root = NULL;
    return 0;
}
