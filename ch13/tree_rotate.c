#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tree_rotate.h"

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
