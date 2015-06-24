#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10
#define PARENT(i) ((i - 1) >> 1)
#define LEFT(i) ((i << 1) + 1)
#define RIGHT(i) ((i << 1) + 2)

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int array[], int node)
{
    int left = LEFT(node);
    int right = RIGHT(node);

    int largest = 0;
    if (left <= MAX_NUM && array[left ] > array[node])
        largest = left;
    else
        largest = node;

    if (right <= MAX_NUM && array[right] > array[largest])
        largest = right;

    if (largest != node) {
        swap(&array[node], &array[largest]);
        maxHeapify(array, largest);
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    maxHeapify(test_array, 1);

    printf("Max-heapify array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
    
    return 0;
}
