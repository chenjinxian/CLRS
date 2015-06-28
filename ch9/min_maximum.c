#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10

typedef struct {
    int min;
    int max;
} min_max;

int minimum(int array[], int length)
{
    int min = array[0];
    for (int i = 1; i < length; i++) {
        if (min > array[i])
            min = array[i];
    }

    return min;
}

min_max min_maximum(int array[], int length)
{
    //we assume that the set contains distinct numbers

    int i = 1;
    min_max mm;
    if (length % 2) {
        mm.min = array[0];
        mm.max = array[0];
    } else {
        i++;
        mm.min = array[0];
        mm.max = array[1];
    }

    while (i < length) {
        //we need 3 compares
        if (array[i] < array[i + 1]) {
            if (mm.min > array[i])
                mm.min = array[i];

            if (mm.max < array[i + 1])
                mm.max = array[i + 1];
        } else {
            if (mm.min > array[i + 1])
                mm.min = array[i + 1];

            if (mm.max < array[i])
                mm.max = array[i];
        }

        i += 2;
    }

    return mm;
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

    min_max mm = min_maximum(test_array, MAX_NUM);
    printf("the min and max num in test_array is:%d -- %d\n",
            mm.min, mm.max);
    
    return 0;
}
