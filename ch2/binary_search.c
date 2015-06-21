#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10
#define NIL -1

int binarySearch(int array[], int start, int length, int value)
{
    int middle = (start + length - 1) / 2;

    if (value == array[middle])
        return middle;
    
    if (length - 1 == middle)
        return NIL;
    
    if (value > array[middle])
        return binarySearch(array, middle + 1, length, value);
    
    if (value < array[middle])
        return binarySearch(array, start, middle - 1, value);

    return NIL;
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {3, 9, 26, 38, 41, 49, 52, 57, 89, 108};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    int ret = binarySearch(test_array, 0, MAX_NUM, 3);

    if (ret == -1)
        printf("Does not fined \"3\" int Test array.\n");
    else
        printf("Find \"3\" at index %d of Test array\n", ret + 1);
    
    return 0;
}
