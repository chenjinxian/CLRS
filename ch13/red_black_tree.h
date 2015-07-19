#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

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

#endif //RED_BLACK_TREE_H
