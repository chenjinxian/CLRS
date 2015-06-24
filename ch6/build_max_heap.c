#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10
#define PARENT(i) (i == 0 ? 0 : (i - 1) >> 1)
#define LEFT(i) ((i << 1) + 1)
#define RIGHT(i) ((i << 1) + 2)

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int array[], int node, int heap_size)
{
    int left = LEFT(node);
    int right = RIGHT(node);

    int largest = 0;
    if (left < heap_size && array[left ] > array[node])
        largest = left;
    else
        largest = node;

    if (right < heap_size && array[right] > array[largest])
        largest = right;

    if (largest != node) {
        swap(&array[node], &array[largest]);
        maxHeapify(array, largest, heap_size);
    }
}

void buildMaxHeap(int array[], int length, int* heap_size)
{
    *heap_size = length;
    for (int i = (length - 1) / 2; i >= 0; i--)
        maxHeapify(array, i, *heap_size);
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    int heap_size = 0;
    buildMaxHeap(test_array, MAX_NUM, &heap_size);

    printf("Build max-heapify array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
    
    return 0;
}
