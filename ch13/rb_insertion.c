#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "rb_insertion.h"
#include "tree_rotate.h"

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
