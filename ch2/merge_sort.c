#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10

void merge(int array[], int start, int middle, int lenght)
{
    const int left = middle - start;
    const int right = lenght - middle;

    int array_left[left];
    int array_right[right];

    for (int i = 0; i < left; i++)
        array_left[i] = array[start + i];
    for (int j = 0; j < right; j++)
        array_right[j] = array[middle + j];

    int i = 0, j = 0, k = start;
    while (i < left && j < right) {
        if (array_left[i] <= array_right[j])
            array[k++] = array_left[i++];
        else
            array[k++] = array_right[j++];
    }

    while (i < left)
        array[k++] = array_left[i++];
    while (j < right)
        array[k++] = array_right[j++];
}

void mergeSort(int array[], int start, int lenght)
{
    if (start < lenght - 1) {
        int middle = (start + lenght) / 2;

        mergeSort(array, start, middle);
        mergeSort(array, middle, lenght);

        merge(array, start, middle, lenght);
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {4, 2, 5, 1, 6, 7, 8, 3, 0, 9};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    printf("Sort array is:\n");
    mergeSort(test_array, 0, MAX_NUM);

    for (int i = 0; i <  MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
    
    return 0;
}
