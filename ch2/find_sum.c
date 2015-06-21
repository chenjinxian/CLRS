#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 10
#define NIL -1

//copy binarySearch to here
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

bool findSum(int array[], int length, int sum, int* first, int* second)
{
    bool ret = false;

    //for 0...length, give first item, finded the sencond item in the array without first
    for (int i = 0; i < length; i++) {
        *first = i;
        *second = sum - i;

        if (NIL != binarySearch(array, 0, length, *second))
            ret = true;
    }

    return ret;
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {4, 2, 5, 1, 6, 7, 8, 3, 0, 9};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    int sum = 16;
    int first = 0, second = 0;

    if (findSum(test_array, MAX_NUM, sum, &first, &second))
        printf("%d is the sum of %d add %d\n", sum, first, second);
    else
        printf("there are not two elements add to %d", sum);

    return 0;
}
