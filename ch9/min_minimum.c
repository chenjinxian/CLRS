#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10
#define MIN(a, b) (a < b ? a : b)

typedef struct {
    int first;
    int second;
} min_min;

int minimum(int array[], int length)
{
    int min = array[0];
    for (int i = 1; i < length; i++) {
        if (min > array[i])
            min = array[i];
    }

    return min;
}

min_min min_minimum(int array[], int length)
{
    min_min mm;
    if (length == 2) {
        if (array[0] < array[1]) {
            mm.first = array[0];
            mm.second = array[1];
        } else {
            mm.first = array[1];
            mm.second = array[0];
        }

        return mm;
    }

    int temp = (length + 1) / 2;
    int* array_temp = (int*)malloc(sizeof(int) * temp);

    int i = 0;
    while (i < length - 1) {
        if (array[i] < array[i + 1])
            array_temp[i / 2] = array[i];
        else
            array_temp[i / 2] = array[i + 1];

        i += 2;
    }

    if (i < length)
        array_temp[i / 2] = array[i];

    return min_minimum(array_temp, temp);
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {4, 2, 5, 1, 6, 7, 8, 3, 0, 9};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    int min = minimum(test_array, MAX_NUM);
    printf("the min num in test_array is:%d\n", min);

    min_min mm = min_minimum(test_array, MAX_NUM);
    printf("the min and max num in test_array is:%d -- %d\n",
            mm.first, mm.second);
    
    return 0;
}
