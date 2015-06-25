#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 12
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

int heapMaxinum(int array[])
{
    return array[0];
}

int heapExtractMax(int array[], int* heap_size)
{
    if (*heap_size < 0) {
        printf("error: heap underflow\n");
        return -1;
    }

    int max = array[0];
    array[0] = array[(*heap_size) - 1];
    (*heap_size)--;

    maxHeapify(array, 0, *heap_size);
    
    return max;
}

void heapIncreaseKey(int array[], int i, int key)
{
    if (key < array[i]) {
        printf("error: new key is smaller than current key\n");
        return;
    }

    array[i] = key;
    while (i > 0 && array[PARENT(i)] < array[i]) {
        swap(&array[i], &array[PARENT(i)]);
        i = PARENT(i);
    }
}

void maxHeapInsert(int array[], int* heap_size, int key)
{
    (*heap_size)++;
    //init the value of insert node is less than new key
    //note that the index of array is from 0 to heap_size - 1
    array[(*heap_size) - 1] = key - 1;
    heapIncreaseKey(array, (*heap_size) - 1, key);
}

int main(int argc, char* argv[])
{
#define sol2
    int test_array[MAX_NUM] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    int heap_size = MAX_NUM;
#ifdef sol1
    int max = heapExtractMax(test_array, &heap_size);
    printf("Heap extract max: %d\n", max);
#endif

#ifdef sol2
    maxHeapInsert(test_array, &heap_size, 10);
    printf("Heap insert key: %d\n", 10);
#endif

    printf("Now the heap is:\n");
    for (int i = 0; i < heap_size; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
    
    return 0;
}
