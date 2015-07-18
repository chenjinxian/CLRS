#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    WHITE = 0, BLACK
} FLAG;

typedef enum {
    ROOT = 0, LEFT, RIGHT
} PATH;

typedef struct element {
    struct element *parent;
    struct element *left;
    struct element *right;
    FLAG flag;
} tree, *tree_ptr;

typedef struct root {
    struct element *root;
} root, *root_ptr;

void preorderTreeWalkL(root_ptr ts_root, tree_ptr ts, PATH path)
{
    if (ts == NULL) {
        return;
    }
    else {
        if (path == LEFT) {
            printf("0");
            if (ts->flag == WHITE) {
                ts->flag = BLACK;
                printf("\n");
                return preorderTreeWalkL(ts_root, ts_root->root->left, LEFT);
            } else {
                preorderTreeWalkL(ts_root, ts->left, LEFT);
                preorderTreeWalkL(ts_root, ts->right, RIGHT);
            }
        }
        else if (path == RIGHT) {
            printf("1");
            if (ts->flag == WHITE) {
                ts->flag = BLACK;
                printf("\n");
                return preorderTreeWalkL(ts_root, ts_root->root->left, LEFT);
                return;
            } else {
                preorderTreeWalkL(ts_root, ts->left, LEFT);
                preorderTreeWalkL(ts_root, ts->right, RIGHT);
            }
        }
    }
}

void preorderTreeWalkR(root_ptr ts_root, tree_ptr ts, PATH path)
{
    if (ts == NULL) {
        return;
    }
    else {
        if (path == LEFT) {
            printf("0");
            if (ts->flag == WHITE) {
                ts->flag = BLACK;
                printf("\n");
                return preorderTreeWalkR(ts_root, ts_root->root->right, RIGHT);
            } else {
                preorderTreeWalkR(ts_root, ts->left, LEFT);
                preorderTreeWalkR(ts_root, ts->right, RIGHT);
            }
        }
        else if (path == RIGHT) {
            printf("1");
            if (ts->flag == WHITE) {
                ts->flag = BLACK;
                printf("\n");
                return preorderTreeWalkR(ts_root, ts_root->root->right, RIGHT);
                return;
            } else {
                preorderTreeWalkR(ts_root, ts->left, LEFT);
                preorderTreeWalkR(ts_root, ts->right, RIGHT);
            }
        }
    }
}

void printTree(root_ptr ts_root)
{
    if (ts_root->root != NULL) {
        preorderTreeWalkL(ts_root, ts_root->root->left, LEFT);
        printf("\n");
        preorderTreeWalkR(ts_root, ts_root->root->right, RIGHT);
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    tree ele_root;
    tree ele1;
    tree ele2;
    tree ele3;
    tree ele4;
    tree ele5;
    tree ele6;
    tree ele7;
    tree ele8;

    ele_root.left = &ele1;
    ele_root.right = &ele4;
    ele_root.parent = NULL;
    ele_root.flag = BLACK;

    ele1.left = NULL;
    ele1.right = &ele2;
    ele1.parent = &ele_root;
    ele1.flag = WHITE;

    ele2.left = NULL;
    ele2.right = &ele3;
    ele2.parent = &ele1;
    ele2.flag = BLACK;

    ele3.left = NULL;
    ele3.right = NULL;
    ele3.parent = &ele2;
    ele3.flag = WHITE;

    ele4.left = &ele5;
    ele4.right = NULL;
    ele4.parent = &ele_root;
    ele4.flag = BLACK;

    ele5.left = &ele6;
    ele5.right = &ele7;
    ele5.parent = &ele4;
    ele5.flag = WHITE;

    ele6.left = NULL;
    ele6.right = NULL;
    ele6.parent = &ele5;
    ele6.flag = WHITE;

    ele7.left = NULL;
    ele7.right = &ele8;
    ele7.parent = &ele5;
    ele7.flag = BLACK;

    ele8.left = NULL;
    ele8.right = NULL;
    ele8.parent = &ele7;
    ele8.flag = WHITE;

    root_ptr ts_root = (root_ptr)malloc(sizeof(root));
    ts_root->root = &ele_root;

    printf("The binary tree is:\n");
    printTree(ts_root);
    
    free(ts_root);
    ts_root = NULL;
    return 0;
}
