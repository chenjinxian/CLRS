#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6

typedef struct element {
    int key;
    struct element *parent;
    struct element *left;
    struct element *right;
    bool b_flag;    //for solution 12-1
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

void treeInsertEqualKeys(root_ptr ts_root, tree_ptr node_z)
{
    tree_ptr node_y = NULL;
    tree_ptr node_x = ts_root->root;
    while (node_x != NULL) {
        node_y = node_x;
        if (node_z->key == node_x->key) {
            //strategy b
            if (node_x->b_flag) {
                node_x->b_flag = !node_x->b_flag;
                node_x = node_x->left;
            } else {
                node_x->b_flag = !node_x->b_flag;
                node_x = node_x->right;
            }
        }
        else if (node_z->key < node_x->key)
            node_x = node_x->left;
        else
            node_x = node_x->right;
    }
    node_z->parent = NULL;

    if (node_y == NULL)
        ts_root->root = node_z;
    else if (node_z->key == node_y->key) {
        //strategy b
        if (node_y->b_flag) {
            node_y->b_flag = !node_y->b_flag;
            node_y = node_y->left;
        } else {
            node_y->b_flag = !node_y->b_flag;
            node_y = node_y->right;
        }
    }
    else if (node_z->key < node_y->key)
        node_y->left = node_z;
    else
        node_y->right = node_z;
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
    ele2.b_flag = true;

    ele9.key = 9;
    ele9.left = NULL;
    ele9.right = NULL;
    ele9.parent = &ele5;
    ele9.b_flag = true;

    ele5.key = 5;
    ele5.left = &ele2;
    ele5.right = &ele9;
    ele5.parent = &ele12;
    ele5.b_flag = true;

    ele12.key = 12;
    ele12.left = &ele5;
    ele12.right = &ele18;
    ele12.parent = NULL;
    ele12.b_flag = true;

    ele15.key = 15;
    ele15.left = NULL;
    ele15.right = &ele17;
    ele15.parent = &ele18;
    ele15.b_flag = true;

    ele18.key = 18;
    ele18.left = &ele15;
    ele18.right = &ele19;
    ele18.parent = &ele12;
    ele18.b_flag = true;

    ele17.key = 17;
    ele17.left = NULL;
    ele17.right = NULL;
    ele17.parent = &ele15;
    ele17.b_flag = true;

    ele19.key = 19;
    ele19.left = NULL;
    ele19.right = NULL;
    ele19.parent = &ele18;
    ele19.b_flag = true;

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
    ele13.b_flag = true;
    
    tree ele14;
    ele14.key = 18;
    ele14.left = NULL;
    ele14.right = NULL;
    ele14.parent = NULL;
    ele14.b_flag = true;
    
    tree ele11;
    ele11.key = 18;
    ele11.left = NULL;
    ele11.right = NULL;
    ele11.parent = NULL;
    ele11.b_flag = true;
    
    printf("Insert an element with key of %d:\n", ele13.key);
    treeInsertEqualKeys(ts_root, &ele13);
    printTree(ts_root);

    printf("Insert an element with key of %d:\n", ele14.key);
    treeInsertEqualKeys(ts_root, &ele14);
    printTree(ts_root);
    
    printf("Insert an element with key of %d:\n", ele11.key);
    treeInsertEqualKeys(ts_root, &ele11);
    printTree(ts_root);
    
    free(ts_root);
    ts_root = NULL;
    return 0;
}
