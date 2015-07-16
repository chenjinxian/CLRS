#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6

typedef struct element {
    int key;
    struct element *parent;
    struct element *left;
    struct element *right;
} tree, *tree_ptr;

typedef struct root {
    struct element *root;
} root, *root_ptr;

void inorderTreeWalk(tree_ptr ts)
{
    if (ts == NULL)
        return;
    else {
        inorderTreeWalk(ts->left);
        printf("%d\t", ts->key);
        inorderTreeWalk(ts->right);

        /*
         *preorderTreeWalk
        printf("%d\t", ts->key);
        preorderTreeWalk(ts->left);
        preorderTreeWalk(ts->right);
        */

        /*
         *postorderTreeWalk
        postorderTreeWalk(ts->left);
        postorderTreeWalk(ts->right);
        printf("%d\t", ts->key);
        */
    }
}

void nonrecursiveTreeWalk(tree_ptr ts)
{
    if (ts == NULL)
        printf("tree is empty\n");
    else {
        tree_ptr temp = NULL;

        while (ts) {
            if (temp == ts->parent) {
                if (ts->left) {
                    temp = ts;
                    ts = ts->left;
                    continue;
                } else
                    temp = NULL;
            }
            if (temp == ts->left) {
                printf("%d\t", ts->key);

                if (ts->right) {
                    temp = ts;
                    ts = ts->right;
                } else
                    temp = NULL;
            }
            if (temp == ts->right) {
                temp = ts;
                ts = ts->parent;
            }
        }
    }
}

void printTree(root_ptr ts_root)
{
    nonrecursiveTreeWalk(ts_root->root);
    printf("\n");
}

int main(int argc, char* argv[])
{
    tree ele2;
    tree ele5a;
    tree ele5b;
    tree ele6;
    tree ele7;
    tree ele8;

    ele2.key = 2;
    ele2.left = NULL;
    ele2.right = NULL;
    ele2.parent = &ele5a;

    ele5a.key = 5;
    ele5a.left = &ele2;
    ele5a.right = &ele5b;
    ele5a.parent = &ele6;

    ele5b.key = 5;
    ele5b.left = NULL;
    ele5b.right = NULL;
    ele5b.parent = &ele5a;

    ele6.key = 6;
    ele6.left = &ele5a;
    ele6.right = &ele7;
    ele6.parent = NULL;

    ele7.key = 7;
    ele7.left = NULL;
    ele7.right = &ele8;
    ele7.parent = &ele6;

    ele8.key = 8;
    ele8.left = NULL;
    ele8.right = NULL;
    ele8.parent = &ele7;

    root_ptr ts_root = (root_ptr)malloc(sizeof(root));
    ts_root->root = &ele6;

    printTree(ts_root);

    free(ts_root);
    ts_root = NULL;
    return 0;
}
