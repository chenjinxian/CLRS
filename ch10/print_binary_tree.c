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

typedef struct {
    tree_ptr array[MAX_NUM];
    int top;
} stack;

/*
//recursive procedure
void printElement(tree_ptr ts)
{
    if (ts == NULL)
        return;
    else {
        printf("%d\t", ts->key);

        printElement(ts->left);
        printElement(ts->right);
    }
}
*/

/*
bool stackEmpty(stack s)
{
    if (0 == s.top)
        return true;
    else
        return false;
}

void push(stack *s, tree_ptr ts)
{
    if (MAX_NUM == (s->top)) {
        printf("overflow\n");
        exit(-1);
    } else {
        s->top++;
        s->array[s->top - 1] = ts;
    }
}

tree_ptr pop(stack *s)
{
    if (stackEmpty(*s)) {
        printf("underflow\n");
        exit(-1);
    } else {
        s->top--;
        return s->array[s->top];
    }
}

//nonrecursive procedure with a stack
void printElement(tree_ptr ts)
{
    if (ts == NULL)
        printf("tree is empty\n");
    else {
        stack s;
        s.top = 0;
        push(&s, ts);
        while (!stackEmpty(s)) {
            tree_ptr temp = pop(&s);
            printf("%d\t", temp->key);

            if (temp->left)
                push(&s, temp->left);

            if (temp->right)
                push(&s, temp->right);
        }
    }
}
*/

//nonrecursive with no more constant extra space
void printElement(tree_ptr ts)
{
    if (ts == NULL)
        printf("tree is empty\n");
    else {
        tree_ptr temp = NULL;

        while (ts) {
            if (temp == ts->parent) {
                printf("%d\t", ts->key);

                temp = ts;
                if (ts->left)
                    ts = ts->left;
                else if (ts->right)
                    ts = ts->right;
                else
                    ts = ts->parent;
            } else if (temp == ts->left && ts->right) {
                temp = ts;
                ts = ts->right;
            } else {
                temp = ts;
                ts = ts->parent;
            }
        }
    }
}

void printTree(root_ptr ts_root)
{
    printElement(ts_root->root);
    printf("\n");
}

int main(int argc, char* argv[])
{
    tree ele_x1;
    tree ele_x2;

    ele_x1.key = 1;
    ele_x1.left = NULL;
    ele_x1.right = NULL;
    ele_x1.parent = &ele_x2;

    ele_x2.key = 4;
    ele_x2.left = &ele_x1;
    ele_x2.right = NULL;
    ele_x2.parent = NULL;
    
    root_ptr ts_root = (root_ptr)malloc(sizeof(root));
    ts_root->root = &ele_x2;

    printTree(ts_root);

    free(ts_root);
    ts_root = NULL;
    return 0;
}
