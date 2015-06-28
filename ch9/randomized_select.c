#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
        //for solution 7.1-2
        //if all element in array are the same, only add i once in every two compare
        else if (array[j] == pivot_element) {
            if (j % 2)
                i++;
        }
    }

    swap(&array[i], &array[end]);

    return i;
}

int generateRandom(start, end)
{
    srand(time(NULL));
    return rand() % (end -start) + start;
}

int randomizedPartition(int array[], int start, int end)
{
    int i = generateRandom(start, end);
    swap(&array[end], &array[i]);
    return partition(array, start, end);
}

int randomizedSelect(int array[], int start, int end, int num)
{
    if (start == end)
        return array[start];

    int pivot_index = randomizedPartition(array, start, end);
    int count = pivot_index - start + 1;
    if (num == count)
        return array[pivot_index];
    else if (num < count)
        return randomizedSelect(array, start, pivot_index - 1, num);
    else
        return randomizedSelect(array, pivot_index + 1, end, num - count);
}

int randomizedSelectIterate(int array[], int start, int end, int num)
{
    while (start != end) {
        int pivot_index = randomizedPartition(array, start, end);
        int count = pivot_index - start + 1;

        if (num == count)
            return array[pivot_index];
        else if (num < count)
            end = pivot_index - 1;
        else
            start = pivot_index + 1;
    }

    return array[start];
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    int min = randomizedSelectIterate(test_array, 0, MAX_NUM - 1, 2);
    printf("the second min in array is:%d\n", min);

    return 0;
}
