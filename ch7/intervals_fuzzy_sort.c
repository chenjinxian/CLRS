#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 6

typedef struct {
    int left;
    int right;
} interval;

void swap(interval* a, interval* b)
{
    interval temp = (interval){a->left, a->right};
    a->left = b->left;
    a->right = b->right;
    b->left = temp.left;
    b->right = temp.right;
}

bool isOverlap(interval a, interval b)
{
    return (a.left <= b.right) && (b.left <= a.right);
}

bool isUnder(interval a, interval b)
{
    return a.right  < b.left;
}

interval partition(interval array[], int start, int end)
{
    interval pivot_element;
    pivot_element.left = array[end].left;
    pivot_element.right = array[end].right;

    for (int j = start; j < end; j++) {
        if (isOverlap(pivot_element, array[j])) {
            if (pivot_element.left < array[j].left)
                pivot_element.left = array[j].left;
            if (pivot_element.right > array[j].right)
                pivot_element.right = array[j].right;
        }
    }

    int left  = start;
    for (int j = start; j < end; j++) {
        if (isUnder(array[j], pivot_element)) {
            swap(&array[left], &array[j]);
            left++;
        }
    }
    swap(&array[left], &array[end]);

    int right = left + 1;
    for (int j = end; right < j; ) {
        if (isOverlap(pivot_element, array[j])) {
            swap(&array[right], &array[j]);
            right++;
        } else
            j--;
    }

    printf("partition:\n");
    for (int j = start; j <= end; j++) {
        printf("%d--%d\t", array[j].left, array[j].right);
    }
    printf("\n");
    
    return (interval){left, right};
}

void intervalsFuzzySort(interval array[], int start, int end)
{
    if (start < end) {
        interval pivot_interval = partition(array, start, end);
        intervalsFuzzySort(array, start, pivot_interval.left - 1);
        intervalsFuzzySort(array, pivot_interval.right + 1, end);
    }
}

int main(int argc, char* argv[])
{
    interval test_array[MAX_NUM] =
        {{5, 9}, {13, 19}, {2, 6}, {4, 7}, {11, 21}, {8, 12}};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d--%d\t", test_array[i].left, test_array[i].right);
    }
    printf("\n");

    intervalsFuzzySort(test_array, 0, MAX_NUM - 1);

    printf("Sort array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d--%d\t", test_array[i].left, test_array[i].right);
    }
    printf("\n");
    
    return 0;
}
