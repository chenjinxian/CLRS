#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 7

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d\t", array[i]);

    printf("\n");
}

void countingSort(
        const int length, const int k,
        int array_radix[], int array_src[], int array_dst[])
{
    const int temp = k + 1;
    int* array_temp = (int*)calloc(temp, sizeof(int));
    if (array_temp == NULL) {
        printf("allocate memery failed\n");
        exit(-1);
    }
    
    for (int i = 0; i < length; i++)
        array_temp[array_radix[i]]++;

    for (int i = 1; i < temp; i++)
        array_temp[i] += array_temp[i - 1];

    for (int i = length - 1; i >= 0; i--) {
        //for radix sort, reset element of array_dst by the index sort in array_radix
        array_dst[array_temp[array_radix[i]] - 1] = array_src[i];
        array_temp[array_radix[i]]--;
    }

    free(array_temp);
}

void radixSort(int array[], int length, int digit, int k)
{
    int num = 1;
    int* radix = (int*)calloc(length, sizeof(int));
    if (radix == NULL) {
        printf("allocate memery failed\n");
        exit(-1);
    }

    //counting sort not sort in place, we need another array to save the source array
    int* array_temp = (int*)calloc(length, sizeof(int));
    if (array_temp == NULL) {
        printf("allocate memery failed\n");
        exit(-1);
    }

    for (int i = 0; i < digit; i++) {
        for (int j = 0; j < length; j++) {
            radix[j] = (array[j] / num) % 10;
            array_temp[j] = array[j];
        }

        countingSort(length, k, radix, array_temp, array);
        printf("sort by digit %d:\n", i + 1);
        printArray(array, length);

        num *= 10;
    }

    free(radix);
}

int main(int argc, char* argv[])
{
    int array[MAX_NUM] = {329, 457, 657, 839, 436, 720, 355};
    printf("Test array is:\n");
    printArray(array, MAX_NUM);

    radixSort(array, MAX_NUM, 3, 9);

    printf("Sort array is:\n");
    printArray(array, MAX_NUM);
    
    return 0;
}
