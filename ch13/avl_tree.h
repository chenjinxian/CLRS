#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct element {
    int key;
    struct element *parent;
    struct element *left;
    struct element *right;
    int height;
} tree, *tree_ptr;

typedef struct root {
    struct element *root;
} root, *root_ptr;

void avlBalance(tree_ptr node_x);

void avlInsert(root_ptr ts_root, tree_ptr node_z);

#endif //AVL_TREE_H
