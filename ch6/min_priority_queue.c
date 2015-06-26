#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 13
#define MIN(a, b) (a < b ? a : b)
#define PARENT(i) (i == 0 ? 0 : (i - 1) >> 1)
#define LEFT(i) ((i << 1) + 1)
#define RIGHT(i) ((i << 1) + 2)

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int array[], int node, int heap_size)
{
    int left = LEFT(node);
    int right = RIGHT(node);

    int smallest = 0;
    if (left < heap_size && array[left] < array[node])
        smallest = left;
    else
        smallest = node;

    if (right < heap_size && array[right] < array[smallest])
        smallest = right;

    if (smallest != node) {
        swap(&array[node], &array[smallest]);
        minHeapify(array, smallest, heap_size);
    }
}

int heapMinimum(int array[])
{
    return array[0];
}

int heapExtractMin(int array[], int* heap_size)
{
    if (*heap_size < 0) {
        printf("error: heap underflow\n");
        exit(-1);
    }

    int min = array[0];
    array[0] = array[(*heap_size) - 1];
    (*heap_size)--;

    minHeapify(array, 0, *heap_size);
    
    return min;
}

void heapDecreaseKey(int array[], int i, int key)
{
    if (key > array[i]) {
        printf("error: new key is smaller than current key\n");
        exit(-1);
    }

    array[i] = key;
    while (i > 0 && array[PARENT(i)] > array[i]) {
        swap(&array[i], &array[PARENT(i)]);
        i = PARENT(i);
    }
}

void minHeapInsert(int array[], int length, int* heap_size, int key)
{
    if (++(*heap_size) > length) {
        printf("heap overflow\n");
        exit(-1);
    }
    //init the value of insert node is larger than new key
    //note that the index of array is from 0 to heap_size - 1
    array[(*heap_size) - 1] = key + 1;
    heapDecreaseKey(array, (*heap_size) - 1, key);
}

int main(int argc, char* argv[])
{
#define sol1
    int test_array[MAX_NUM] = {0, 4, 1, 6, 7, 2, 9, 12, 13, 15, 10, 8};

    int heap_size = MAX_NUM -1;
    printf("Test array is:\n");
    for (int i = 0; i < heap_size; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
#ifdef sol1
    int min = heapExtractMin(test_array, &heap_size);
    printf("Heap extract min: %d\n", min);
#endif

#ifdef sol2
    minHeapInsert(test_array, MAX_NUM,  &heap_size, 0);
    printf("Heap insert key: %d\n", 10);
#endif

    printf("Now the heap is:\n");
    int size = MIN(heap_size, MAX_NUM);
    for (int i = 0; i < size; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
    
    return 0;
}
