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
    }
}

void printTree(root_ptr ts_root)
{
    inorderTreeWalk(ts_root->root);
    printf("\n");
}

void treeInsert(root_ptr ts_root, tree_ptr node_z)
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
    node_z->parent = NULL;

    if (node_y == NULL)
        ts_root->root = node_z;
    else if (node_z->key < node_y->key)
        node_y->left = node_z;
    else
        node_y->right = node_z;
}

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

void transplant(root_ptr ts_root, tree_ptr node_u, tree_ptr node_v)
{
    if (node_u->parent = NULL)
        ts_root->root = node_v;
    else if (node_u = node_u->parent->left)
        node_u->parent->left = node_v;
    else
        node_u->parent->right = node_v;

    if (node_v != NULL)
        node_v->parent = node_u->parent;
}

void treeDelete(root_ptr ts_root, tree_ptr node_z)
{
    if (node_z->left == NULL)
        transplant(ts_root, node_z, node_z->right);
    else if (node_z->right == NULL)
        transplant(ts_root, node_z, node_z->left);
    else {
        tree_ptr node_y = treeMinimum(node_z->right);
        if (node_y->parent != node_z) {
            transplant(ts_root, node_y, node_y->right);
            node_y->right = node_z->right;
            node_y->right->parent = node_y;
        }

        transplant(ts_root, node_z, node_y);
        node_y->left = node_z->left;
        node_y->left->parent = node_y;
    }

    if (node_z != NULL) {
        node_z->left = NULL;
        node_z->right = NULL;
        node_z->parent = NULL;
    }
}

int main(int argc, char* argv[])
{
    tree ele2;
    tree ele5;
    tree ele9;
    tree ele12;
    tree ele15;
    tree ele17;
    tree ele18;
    tree ele19;

    ele2.key = 2;
    ele2.left = NULL;
    ele2.right = NULL;
    ele2.parent = &ele5;

    ele9.key = 9;
    ele9.left = NULL;
    ele9.right = NULL;
    ele9.parent = &ele5;

    ele5.key = 5;
    ele5.left = &ele2;
    ele5.right = &ele9;
    ele5.parent = &ele12;

    ele12.key = 12;
    ele12.left = &ele5;
    ele12.right = &ele18;
    ele12.parent = NULL;

    ele15.key = 15;
    ele15.left = NULL;
    ele15.right = &ele17;
    ele15.parent = &ele18;

    ele18.key = 18;
    ele18.left = &ele15;
    ele18.right = &ele19;
    ele18.parent = &ele12;

    ele17.key = 17;
    ele17.left = NULL;
    ele17.right = NULL;
    ele17.parent = &ele15;

    ele19.key = 19;
    ele19.left = NULL;
    ele19.right = NULL;
    ele19.parent = &ele18;

    root_ptr ts_root = (root_ptr)malloc(sizeof(root));
    ts_root->root = &ele12;

    printf("The binary tree is:\n");
    printTree(ts_root);
    printf("-----------------------------------------------\n");
    
    tree ele13;
    ele13.key = 13;
    ele13.left = NULL;
    ele13.right = NULL;
    ele13.parent = NULL;
    
    printf("Insert an element with key of %d:\n", ele13.key);
    treeInsert(ts_root, &ele13);
    printTree(ts_root);
    
    printf("Delete the element with key of %d:\n", ele17.key);
    treeDelete(ts_root, &ele17);
    printf("The binary tree is:\n");
    printTree(ts_root);
    
    free(ts_root);
    ts_root = NULL;
    return 0;
}
