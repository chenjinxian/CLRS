#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tree_rotate.h"
#include "rb_insertion.h"
#include "rb_deletion.h"

tree_ptr treeMinimum(tree_ptr node_x)
{
    if (node_x == NULL) {
        printf("tree is empty\n");
        return node_x;
    }

    while (node_x->left != NULL) {
        printf("%d --> ", node_x->key);
        node_x = node_x->left;
    }
    
    printf("%d\n", node_x->key);
    return node_x;
}

void inorderTreeWalk(tree_ptr ts)
{
    if (ts == NULL)
        return;
    else {
        inorderTreeWalk(ts->left);
        printf("%d", ts->key);
        if (RED == ts->color)
            printf(" (RED)\t");
        else
            printf(" (BLACK)\t");
        inorderTreeWalk(ts->right);
    }
}

void printTree(root_ptr ts_root)
{
    inorderTreeWalk(ts_root->root);
    printf("\n");
}

int main(int argc, char* argv[])
{
    tree ele1;
    tree ele2;
    tree ele4;
    tree ele5;
    tree ele7;
    tree ele8;
    tree ele11;
    tree ele14;
    tree ele15;

    ele1.key = 1;
    ele1.left = NULL;
    ele1.right = NULL;
    ele1.parent = &ele2;
    ele1.color = BLACK;

    ele2.key = 2;
    ele2.left = &ele1;
    ele2.right = &ele7;
    ele2.parent = &ele11;
    ele2.color = RED;

    ele5.key = 5;
    ele5.left = NULL;
    ele5.right = NULL;
    ele5.parent = &ele7;
    ele5.color = RED;

    ele7.key = 7;
    ele7.left = &ele5;
    ele7.right = &ele8;
    ele7.parent = &ele2;
    ele7.color = BLACK;

    ele8.key = 8;
    ele8.left = NULL;
    ele8.right = NULL;
    ele8.parent = &ele7;
    ele8.color = RED;

    ele11.key = 11;
    ele11.left = &ele2;
    ele11.right = &ele14;
    ele11.parent = NULL;
    ele11.color = BLACK;

    ele14.key = 14;
    ele14.left = NULL;
    ele14.right = &ele15;
    ele14.parent = &ele11;
    ele14.color = BLACK;

    ele15.key = 15;
    ele15.left = NULL;
    ele15.right = NULL;
    ele15.parent = &ele14;
    ele15.color = RED;

    root_ptr ts_root = (root_ptr)malloc(sizeof(root));
    ts_root->root = &ele11;

    printf("The RED-BLACK tree is:\n");
    printTree(ts_root);
    printf("-----------------------------------------------\n");
    
    ele4.key = 4;
    ele4.left = NULL;
    ele4.right = NULL;
    ele4.parent = NULL;
    ele4.color = RED;

    rbInsert(ts_root, &ele4);
    printf("Ater insert 4, the tree is:\n");
    printTree(ts_root);

    rbDelete(ts_root, &ele14);
    printf("Ater delete 14, the tree is:\n");
    printTree(ts_root);

    free(ts_root);
    ts_root = NULL;
    return 0;
}
