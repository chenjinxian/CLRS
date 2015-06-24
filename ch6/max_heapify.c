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

void maxHeapifyIterate(int array[], int node)
{
    while (1) {
        int left = LEFT(node);
        int right = RIGHT(node);

        int largest = 0;
        if (left < MAX_NUM && array[left ] > array[node])
            largest = left;
        else
            largest = node;

        if (right < MAX_NUM && array[right] > array[largest])
            largest = right;

        if (largest != node) {
            swap(&array[node], &array[largest]);
            node = largest;
        } else
            break;
    }
}

void maxHeapifyRecursive(int array[], int node)
{
    int left = LEFT(node);
    int right = RIGHT(node);

    int largest = 0;
    if (left < MAX_NUM && array[left ] > array[node])
        largest = left;
    else
        largest = node;

    if (right < MAX_NUM && array[right] > array[largest])
        largest = right;

    if (largest != node) {
        swap(&array[node], &array[largest]);
        maxHeapifyRecursive(array, largest);
    }
}

void minHeapify(int array[], int node)
{
    int left = LEFT(node);
    int right = RIGHT(node);

    int largest = 0;
    if (left < MAX_NUM && array[left ] < array[node])
        largest = left;
    else
        largest = node;

    if (right < MAX_NUM && array[right] < array[largest])
        largest = right;

    if (largest != node) {
        swap(&array[node], &array[largest]);
        minHeapify(array, largest);
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

    maxHeapifyRecursive(test_array, 1);

    printf("Max-heapify-Rec array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
    
    maxHeapifyIterate(test_array, 1);

    printf("Max-heapify-Ite array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
    
    minHeapify(test_array, 0);

    printf("Min-heapify array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");
    
    return 0;
}
