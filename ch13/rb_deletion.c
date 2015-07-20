#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "rb_deletion.h"
#include "tree_rotate.h"

void rbTransplant(root_ptr ts_root, tree_ptr node_u, tree_ptr node_v)
{
    if (NULL == node_u->parent)
        ts_root->root = node_v;
    else if (node_u == node_u->parent->left)
        node_u->parent->left = node_v;
    else
        node_u->parent->right = node_v;

    node_v->parent = node_u->parent;
}

void rbDeleteFixup(root_ptr ts_root, tree_ptr node_x)
{
    while (node_x != ts_root->root && BLACK == node_x->color) {
        if (node_x == node_x->parent->left) {
            tree_ptr node_w = node_x->parent->right;
            if (RED == node_w->color) {
                node_w->color = BLACK;
                node_x->parent->color = RED;
                leftRotate(ts_root, node_x->parent);
                node_w = node_x->parent->right;
            }
            else if (BLACK == node_w->left->color && BLACK == node_w->right->color) {
                node_w->color = RED;
                node_x = node_x->parent;
            }
            else if (BLACK == node_w->right->color) {
                node_w->left->color = BLACK;
                node_w->color = RED;
                rightRotate(ts_root, node_w);
                node_w = node_x->parent->right;
            } else {
                node_w->color = node_x->parent->color;
                node_x->parent->color = BLACK;
                node_w->right->color = BLACK;
                leftRotate(ts_root, node_x->parent);
                node_x = ts_root->root;
            }
        }
        else if (node_x == node_x->parent->right) {
            tree_ptr node_w = node_x->parent->left;
            if (RED == node_w->color) {
                node_w->color = BLACK;
                node_x->parent->color = RED;
                leftRotate(ts_root, node_x->parent);
                node_w = node_x->parent->right;
            }
            else if (BLACK == node_w->left->color && BLACK == node_w->right->color) {
                node_w->color = RED;
                node_x = node_x->parent;
            }
            else if (BLACK == node_w->right->color) {
                node_w->left->color = BLACK;
                node_w->color = RED;
                rightRotate(ts_root, node_w);
                node_w = node_x->parent->right;
            } else {
                node_w->color = node_x->parent->color;
                node_x->parent->color = BLACK;
                node_w->right->color = BLACK;
                leftRotate(ts_root, node_x->parent);
                node_x = ts_root->root;
            }
        }
    }
    node_x->color = BLACK;
}

void rbDelete(root_ptr ts_root, tree_ptr node_z)
{
    tree_ptr node_y = node_z;
    COLOR y_original_color = node_y->color;

    tree_ptr node_x = NULL;
    if (node_z->left == NULL) {
        node_x = node_z->right;
        rbTransplant(ts_root, node_z, node_z->right);
    }
    else if (node_z->right == NULL) {
        node_x = node_z->left;
        rbTransplant(ts_root, node_z, node_z->left);
    } else {
        node_y = treeMinimum(node_z->right);
        y_original_color = node_y->color;
        node_x = node_y->right;
        if (node_y->parent == node_z)
            node_x->parent = node_y;
        else {
            rbTransplant(ts_root, node_y, node_y->right);
            node_y->right = node_z->right;
            node_y->right->parent = node_y;
        }

        rbTransplant(ts_root, node_z, node_y);
        node_y->left = node_z->left;
        node_y->left->parent = node_y;
        node_y->color = node_z->color;
    }

    if (y_original_color == BLACK)
        rbDeleteFixup(ts_root, node_x);
}
