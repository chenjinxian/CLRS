#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 11

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d\t", array[i]);

    printf("\n");
}

void countingSort(
        const int length, const int k,
        int array_src[], int array_dst[])
{
    const int temp = k + 1;
    int* array_temp = (int*)malloc(sizeof(int) * temp);
    
    //init every elment of array_temp to 0, also can use calloc or memset
    //memset(array_temp, 0, temp);
    for (int i = 0; i < temp; i++)
        array_temp[i] = 0;

    for (int i = 0; i < length; i++)
        array_temp[array_src[i]]++;

    for (int i = 1; i < temp; i++)
        array_temp[i] += array_temp[i - 1];

    //for solution 8.2-4
    //in this step, we can get numbers of the n integers fall into a range[a..b]
    //by count array_temp[b] - array_temp[a - 1] (a>0, else array_temp[a-1] = 0)
    printf("array temp is:\n");
    printArray(array_temp, temp);

    for (int i = length - 1; i >= 0; i--) {
        array_dst[array_temp[array_src[i]] - 1] = array_src[i];
        printf("array dst is:\n");
        printArray(array_dst, length);

        array_temp[array_src[i]]--;
        printf("array temp is:\n");
        printArray(array_temp, temp);
    }

    free(array_temp);
}

int main(int argc, char* argv[])
{
    int array_src[MAX_NUM] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    printf("Test array is:\n");
    printArray(array_src, MAX_NUM);

    int array_dst[MAX_NUM] = {0};
    countingSort(MAX_NUM, 6, array_src, array_dst);

    printf("Sort array is:\n");
    printArray(array_dst, MAX_NUM);
    
    return 0;
}
