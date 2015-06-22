#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 5

int findInvert(int array[], int start, int middle, int lenght)
{
    int invert_cnt = 0;
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
        if (array_left[i] <= array_right[j]) {
            array[k++] = array_left[i++];
        } else {
            array[k++] = array_right[j++];
            invert_cnt += left - i;
        }
    }

    while (i < left)
        array[k++] = array_left[i++];
    while (j < right)
        array[k++] = array_right[j++];

    return invert_cnt;
}

int getInversions(int array[], int start, int lenght)
{
    if (start < lenght - 1) {
        int invert_cnt = 0;
        int middle = (start + lenght) / 2;

        invert_cnt += getInversions(array, start, middle);
        invert_cnt += getInversions(array, middle, lenght);

        invert_cnt += findInvert(array, start, middle, lenght);
        return invert_cnt;
    } else {
        return 0;
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] = {2, 3, 8, 6, 1};
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    int ret = getInversions(test_array, 0, MAX_NUM);

    printf("There are %d inversions in Test array\n", ret);
    
    return 0;
}
