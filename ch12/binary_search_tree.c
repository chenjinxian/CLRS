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

tree_ptr treeSearch(tree_ptr node_x, int key)
{
    if (node_x == NULL || key == node_x->key) {
        printf("%d\n", key);
        return node_x;
    }

    printf("%d --> ", node_x->key);

    if (key < node_x->key)
        return treeSearch(node_x->left, key);
    else
        return treeSearch(node_x->right, key);
}

tree_ptr iterativeTreeSearch(tree_ptr node_x, int key)
{
    while (node_x != NULL && key != node_x->key) {
        printf("%d --> ", node_x->key);
        
        if (key < node_x->key)
            node_x = node_x->left;
        else
            node_x = node_x->right;
    }

    printf("%d\n", key);
    return node_x;
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

tree_ptr recursiveMinimum(tree_ptr node_x)
{
    if (node_x != NULL && node_x->left != NULL)
        return recursiveMinimum(node_x->left);
    else
        return node_x;
}

tree_ptr recursiveMaximum(tree_ptr node_x)
{
    if (node_x != NULL && node_x->right != NULL)
        return recursiveMinimum(node_x->right);
    else
        return node_x;
}

tree_ptr treeMaximum(tree_ptr node_x)
{
    if (node_x == NULL) {
        printf("tree is empty\n");
        return node_x;
    }

    while (node_x->right != NULL) {
        printf("%d --> ", node_x->key);
        node_x = node_x->right;
    }
    
    printf("%d\n", node_x->key);
    return node_x;
}

tree_ptr treeSuccessor(tree_ptr node_x)
{
    if (node_x == NULL) {
        printf("tree is empty\n");
        return node_x;
    }
    printf("%d --> ", node_x->key);

    if (node_x->right != NULL)
        return treeMinimum(node_x->right);

    tree_ptr node_y = node_x->parent;
    while (node_y != NULL && node_x == node_y->right) {
        printf("%d --> ", node_y->key);
        node_x = node_y;
        node_y = node_y->parent;
    }

    printf("%d\n", node_y->key);
    return node_y;
}

tree_ptr treePredecessor(tree_ptr node_x)
{
    if (node_x == NULL) {
        printf("tree is empty\n");
        return node_x;
    }
    printf("%d --> ", node_x->key);

    if (node_x->left != NULL)
        return treeMaximum(node_x->left);

    tree_ptr node_y = node_x->parent;
    while (node_y != NULL && node_x == node_y->left) {
        printf("%d --> ", node_y->key);
        node_x = node_y;
        node_y = node_y->parent;
    }

    printf("%d\n", node_y->key);
    return node_y;
}

int main(int argc, char* argv[])
{
    tree ele2;
    tree ele3;
    tree ele4;
    tree ele6;
    tree ele7;
    tree ele9;
    tree ele13;
    tree ele15;
    tree ele17;
    tree ele18;
    tree ele20;

    ele2.key = 2;
    ele2.left = NULL;
    ele2.right = NULL;
    ele2.parent = &ele3;

    ele4.key = 4;
    ele4.left = NULL;
    ele4.right = NULL;
    ele4.parent = &ele3;

    ele3.key = 3;
    ele3.left = &ele2;
    ele3.right = &ele4;
    ele3.parent = &ele6;

    ele6.key = 6;
    ele6.left = &ele3;
    ele6.right = &ele7;
    ele6.parent = &ele15;

    ele7.key = 7;
    ele7.left = NULL;
    ele7.right = &ele13;
    ele7.parent = &ele6;

    ele9.key = 9;
    ele9.left = NULL;
    ele9.right = NULL;
    ele9.parent = &ele13;

    ele13.key = 13;
    ele13.left = &ele9;
    ele13.right = NULL;
    ele13.parent = &ele7;

    ele15.key = 15;
    ele15.left = &ele6;
    ele15.right = &ele18;
    ele15.parent = NULL;

    ele18.key = 18;
    ele18.left = &ele17;
    ele18.right = &ele20;
    ele18.parent = &ele15;

    ele17.key = 17;
    ele17.left = NULL;
    ele17.right = NULL;
    ele17.parent = &ele18;

    ele20.key = 20;
    ele20.left = NULL;
    ele20.right = NULL;
    ele20.parent = &ele18;

    root_ptr ts_root = (root_ptr)malloc(sizeof(root));
    ts_root->root = &ele15;

    printf("The binary tree is:\n");
    printTree(ts_root);
    printf("-----------------------------------------------\n");
    
    printf("Search the node with key of 13 in recursive:\n");
    treeSearch(ts_root->root, 13);
    printf("Search the node with key of 13 in iterative:\n");
    tree_ptr ele_find = iterativeTreeSearch(ts_root->root, 13);
    printf("-----------------------------------------------\n");

    printf("Trace the mininum in the tree:\n");
    treeMinimum(ts_root->root);
    printf("Trace the maxinum in the tree:\n");
    treeMaximum(ts_root->root);
    printf("-----------------------------------------------\n");

    printf("Trace successor of node %d:\n", ele_find->key);
    treeSuccessor(ele_find);
    printf("Trace predecessor of node %d:\n", ele_find->key);
    treePredecessor(ele_find);

    free(ts_root);
    ts_root = NULL;
    return 0;
}
