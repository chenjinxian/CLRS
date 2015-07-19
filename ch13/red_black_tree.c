#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum { RED, BLACK } COLOR;

typedef struct element {
    int key;
    struct element *parent;
    struct element *left;
    struct element *right;
    COLOR color;
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

void leftRotate(root_ptr ts_root, tree_ptr node_x)
{
    tree_ptr node_y = node_x->right;
    node_x->right = node_y->left;
    if (node_y->left != NULL)
        node_y->left->parent = node_x;
    node_y->parent = node_x->parent;

    if (node_x->parent == NULL)
        ts_root->root = node_y;
    else if (node_x == node_x->parent->left)
        node_x->parent->left = node_y;
    else
        node_x->parent->right = node_y;

    node_y->left = node_x;
    node_x->parent = node_y;
}

void rightRotate(root_ptr ts_root, tree_ptr node_y)
{
    tree_ptr node_x = node_y->left;
    node_y->left = node_x->right;
    if (node_x->right != NULL)
        node_x->right->parent = node_y;
    node_x->parent = node_y->parent;

    if (node_y->parent == NULL)
        ts_root->root = node_x;
    else if (node_y == node_y->parent->right)
        node_y->parent->right = node_x;
    else
        node_y->parent->left = node_x;

    node_x->right = node_y;
    node_y->parent = node_x;
}

void rbInsertFixup(root_ptr ts_root, tree_ptr node_z)
{
    while (RED == node_z->parent->color) {
        if (node_z->parent == node_z->parent->parent->left) {
            tree_ptr node_y = node_z->parent->parent->right;
            if (RED == node_y->color) {
                node_z->parent->color = BLACK;
                node_y->color = BLACK;
                node_z->parent->parent->color = RED;
                node_z = node_z->parent->parent;
            }
            else if (node_z == node_z->parent->right) {
                node_z = node_z->parent;
                leftRotate(ts_root, node_z);
            } else {
                node_z->parent->color = BLACK;
                node_z->parent->parent->color = RED;
                rightRotate(ts_root, node_z->parent->parent);
            }
        }
        else if (node_z->parent == node_z->parent->parent->right) {
            tree_ptr node_y = node_z->parent->parent->left;
            if (RED == node_y->color) {
                node_z->parent->color = BLACK;
                node_y->color = BLACK;
                node_z->parent->parent->color = RED;
                node_z = node_z->parent->parent;
            }
            else if (node_z == node_z->parent->right) {
                node_z = node_z->parent;
                leftRotate(ts_root, node_z);
            } else {
                node_z->parent->color = BLACK;
                node_z->parent->parent->color = RED;
                rightRotate(ts_root, node_z->parent->parent);
            }
        }
    }
    ts_root->root->color = BLACK;
}

void rbInsert(root_ptr ts_root, tree_ptr node_z)
{
    tree_ptr node_y = NULL;
    tree_ptr node_x = ts_root->root;

    while (node_x != NULL) {
        node_y = node_x;
        if (node_z->key < node_x->key)
            node_x = node_x->left;
        else
            node_x = node_x->right;
    }
    node_z->parent = node_y;

    if (NULL == node_y)
        ts_root->root = node_z;
    else if (node_z->key < node_y->key)
        node_y->left = node_z;
    else
        node_y->right = node_z;

    node_z->left = NULL;
    node_z->right = NULL;
    node_z->color = RED;
    
    rbInsertFixup(ts_root, node_z);
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

    free(ts_root);
    ts_root = NULL;
    return 0;
}
