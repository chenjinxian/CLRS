#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 13
#define MIN(a, b) (a < b ? a : b)

//suppose that j is from 0 to D-1
#define D 3
#define D_ARY_PARENT(i) (i == 0 ? 0 : (i - 1) / D)
#define D_ARY_CHILD(i, j) ((D * i) + j + 1)

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int array[], int node, int heap_size)
{
    int largest = node;
    for (int j = 0; j < D; j++) {
        int child = D_ARY_CHILD(node, j);

        if (child < heap_size && array[child] > array[largest])
            largest = child;
    }

    if (largest != node) {
        swap(&array[node], &array[largest]);
        maxHeapify(array, largest, heap_size);
    }
}

int heapMaximum(int array[])
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

void daryHeapIncreaseKey(int array[], int i, int key)
{
    if (key < array[i]) {
        printf("error: new key is smaller than current key\n");
        return;
    }

    array[i] = key;
    while (i > 0 && array[D_ARY_PARENT(i)] < array[i]) {
        swap(&array[i], &array[D_ARY_PARENT(i)]);
        i = D_ARY_PARENT(i);
    }
}

void maxHeapInsert(int array[], int length, int* heap_size, int key)
{
    if (++(*heap_size) > length) {
        printf("heap overflow\n");
        return;
    }
    //init the value of insert node is less than new key
    //note that the index of array is from 0 to heap_size - 1
    array[(*heap_size) - 1] = key - 1;
    daryHeapIncreaseKey(array, (*heap_size) - 1, key);
}

int main(int argc, char* argv[])
{
//solution 6.5-1, 2, 8
#define sol1
    int test_array[MAX_NUM] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

    int heap_size = MAX_NUM - 1;
    printf("Test array is:\n");
    for (int i = 0; i < heap_size; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
#ifdef sol1
    int max = heapExtractMax(test_array, &heap_size);
    printf("Heap extract max: %d\n", max);
#endif

#ifdef sol2
    maxHeapInsert(test_array, MAX_NUM, &heap_size, 10);
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
