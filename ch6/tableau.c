#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define M 4
#define N 4

typedef struct {
    int x;
    int y;
} pos;

pos move_up(pos cur_pos)
{
    pos new_pos = {cur_pos.x - 1, cur_pos.y};
    return new_pos;
}

pos move_down(pos cur_pos)
{
    pos new_pos = {cur_pos.x + 1, cur_pos.y};
    return new_pos;
}

pos move_left(pos cur_pos)
{
    pos new_pos = {cur_pos.x, cur_pos.y - 1};
    return new_pos;
}

pos move_right(pos cur_pos)
{
    pos new_pos = {cur_pos.x, cur_pos.y + 1};
    return new_pos;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tableauInit(int tableau[M][N], int m, int n)
{
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j++) {
            tableau[i][j] = INT_MAX;
        }
    }
}

void tableauMinSatisfy(int tableau[M][N], pos cur_pos)
{
    pos right = move_right(cur_pos);
    pos down = move_down(cur_pos);

    pos smallest = {cur_pos.x, cur_pos.y};
    if (right.y < M &&
            tableau[right.x][right.y] < tableau[smallest.x][smallest.y]) {
        smallest.x = right.x;
        smallest.y = right.y;
    }

    if (down.x < N &&
            tableau[down.x][down.y] < tableau[smallest.x][smallest.y]) {
        smallest.x = down.x;
        smallest.y = down.y;
    }

    if (smallest.x != cur_pos.x || smallest.y != cur_pos.y) {
        swap(&tableau[cur_pos.x][cur_pos.y], &tableau[smallest.x][smallest.y]);
        tableauMinSatisfy(tableau, smallest);
    }
}

void tableauMaxSatisfy(int tableau[M][N], pos cur_pos)
{
    pos left = move_left(cur_pos);
    pos up = move_up(cur_pos);

    pos largest = {cur_pos.x, cur_pos.y};
    if (left.y >= 0 &&
            tableau[left.x][left.y] > tableau[largest.x][largest.y]) {
        largest.x = left.x;
        largest.y = left.y;
    }

    if (up.x >= 0 &&
            tableau[up.x][up.y] > tableau[largest.x][largest.y]) {
        largest.x = up.x;
        largest.y = up.y;
    }

    if (largest.x != cur_pos.x || largest.y != cur_pos.y) {
        swap(&tableau[cur_pos.x][cur_pos.y], &tableau[largest.x][largest.y]);
        tableauMaxSatisfy(tableau, largest);
    }
}

int tableauExtractMin(int tableau[M][N])
{
    int min = tableau[0][0];
    if (min == INT_MAX) {
        printf("tableau is empty\n");
        //exit(-1);
        return min;
    }

    tableau[0][0] = INT_MAX;
    pos cur_pos = {0, 0};
    tableauMinSatisfy(tableau, cur_pos);

    return min;
}

void tableauInsert(int tableau[M][N], int new_value)
{
    if (tableau[M - 1][N - 1] < INT_MAX) {
        printf("tableau is full\n");
        exit(-1);
    }

    tableau[M - 1][N - 1] = new_value;
    pos cur_pos = {M - 1, N - 1};
    tableauMaxSatisfy(tableau, cur_pos);
}

void tableauSort(int array[], int m, int n)
{
    int tableau[m][n];
    tableauInit(tableau, m, n);

    int length = m * n;
    //constract a tableau by array(length = n * n)
    //this will take O(n+n) * (n * n)
    for (int i = 0; i < length; i++)
        tableauInsert(tableau, array[i]);

    //set array by extract min
    //alse take O(n+n) * (n * n)
    for (int i = 0; i < length; i++)
        array[i] = tableauExtractMin(tableau);
}

//start from the left-bottom
//move right when key is larger than the current, and move up right when smaller
pos tableauFind(int tableau[M][N], int key)
{
    pos left_bottom = {M - 1, 0};

    while (left_bottom.x >= 0 && left_bottom.y < M) {
        int current = tableau[left_bottom.x][left_bottom.y];
        
        if (current == key)
            return left_bottom;
        else if (key > current)
            left_bottom = move_right(left_bottom);
        else
            left_bottom = move_up(left_bottom);
    }

    left_bottom.x = -1;
    left_bottom.y = -1;
    return left_bottom;
}

int main(int argc, char* argv[])
{
    int tableau[M][N];
    tableauInit(tableau, M, N);
    
    const int length = M * N;
    int test_array[length] = {
        9, 16, 3, 2,
        4, 8 , 5, 14,
        12, INT_MAX, INT_MAX, INT_MAX,
        INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    printf("Test array is:\n");
    for (int i = 0; i < length; i++) {
        printf("%d\t", test_array[i]);
        tableauInsert(tableau, test_array[i]);
    }
    printf("\n");

    printf("Young tableau is:\n");
    for (int i = 0; i <  M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", tableau[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    pos find = tableauFind(tableau, 5);
    printf("find 5 in tableau: %d, %d\n", find.x, find.y);
    
    tableauSort(test_array, M, N);
    for (int i = 0; i < length; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    return 0;
}
