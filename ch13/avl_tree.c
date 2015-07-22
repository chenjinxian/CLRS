#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "avl_tree.h"

void avlBalance(tree_ptr node_x)
{
    if (node_x->left->height - node_x->right->height > 1 ||
            node_x->right->height- node_x->left->height > 1) {
    }
}

void InsertRecursive(tree_ptr node_x, tree_ptr node_z)
{
    if (node_z->key < node_x->key) {
        if (node_x->left != NULL)
            InsertRecursive(node_x->left, node_z);
        else
            node_x->left = node_z;

        avlBalance(node_x);
    } else {
        InsertRecursive(node_x->right, node_z);
        avlBalance(node_x->right);
    }
}

void avlInsert(root_ptr ts_root, tree_ptr node_z)
{
    tree_ptr node_x = ts_root->root;
    if (NULL == node_x)
        ts_root->root = node_z;
    else
        InsertRecursive(node_x, node_z);
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

