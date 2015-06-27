#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 12

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int start, int end)
{
    int pivot_element = array[end];
    int i = start;

    for (int j = start; j < end; j++) {
        if (array[j] < pivot_element) {
            swap(&array[i], &array[j]);
            i++;
        }
        else if (array[j] == pivot_element) {
            if (j % 2)
                i++;
        }
    }

    swap(&array[i], &array[end]);

    printf("\n");
    for (int j = start; j <= end; j++) {
        printf("%d\t", array[j]);
    }
    printf("\n");
    
    return i;
}

void tailRecursiveQuickSort(int array[], int start, int end)
{
    while (start < end) {
        int pivot_index = partition(array, start, end);
        tailRecursiveQuickSort(array, start, pivot_index - 1);
        start = pivot_index + 1;
    }
}

int main(int argc, char* argv[])
{
    //int test_array[MAX_NUM] = {2, 8, 7, 1, 3, 5, 6, 4};
    int test_array[MAX_NUM] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    printf("Sort array is:\n");
    tailRecursiveQuickSort(test_array, 0, MAX_NUM - 1);

    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
    
    return 0;
}
