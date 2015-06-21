#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10
#define NIL -1

int linerSearch(int array[], int length, int value)
{
    for (int i = 0; i < length; i++) {
        if (value == array[i])
            return i;
    }

    return NIL;
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {4, 2, 5, 1, 6, 7, 8, 3, 0, 9};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    int ret = linerSearch(test_array, MAX_NUM, 3);
    printf("Find \"3\" at index %d of Test array\n", ret);
    
    return 0;
}
