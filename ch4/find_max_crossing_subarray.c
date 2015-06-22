#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 16

typedef struct max_subarray {
    int low;
    int high;
    int sum;
} max_subarray;

void setSubarray(
        /*in*/ int max_left,
        /*in*/ int max_right,
        /*in*/ int max_sum,
        /*out*/max_subarray* sub_array)
{
    sub_array->low = max_left;
    sub_array->high = max_right;
    sub_array->sum = max_sum;
}

void findMaxCrossingSubarray(
        /*in*/ int in_array[],
        /*in*/ int low,
        /*in*/ int mid,
        /*in*/ int high,
        /*out*/max_subarray* sub_array)
{
    int max_left = 0, max_right = 0;

    int left_sum = 0;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += in_array[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = 0;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += in_array[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    setSubarray(max_left, max_right, left_sum + right_sum, sub_array);
}

void findMaximumSubarray(
        /*in*/ int in_array[],
        /*in*/ int low,
        /*in*/ int high,
        /*out*/max_subarray* sub_array)
{
    if (high == low)
        return setSubarray(low, high, in_array[low], sub_array);
    else {
        int mid = (low + high) / 2;

        max_subarray left_sub;
        findMaximumSubarray(in_array, low, mid, &left_sub);
        
        max_subarray right_sub;
        findMaximumSubarray(in_array, mid + 1, high, &right_sub);
        
        max_subarray cross_sub;
        findMaxCrossingSubarray(in_array, low, mid, high, &cross_sub);
        
        if (left_sub.sum >= right_sub.sum &&
                left_sub.sum >= cross_sub.sum) {
            return setSubarray(left_sub.low, left_sub.high, left_sub.sum, sub_array);
        }
        else if (right_sub.sum >= left_sub.sum &&
                right_sub.sum >= cross_sub.sum) {
            return setSubarray(right_sub.low, right_sub.high, right_sub.sum, sub_array);
        }
        else
            return setSubarray(cross_sub.low, cross_sub.high, cross_sub.sum, sub_array);
    }
}

int main(int argc, char* argv[])
{
    int test_array[MAX_NUM] =
        {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    
    printf("Test array is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    max_subarray sub_array;
    findMaximumSubarray(test_array, 0, MAX_NUM - 1, &sub_array);

    printf("The maximum sub array is:\n");
    for (int i = sub_array.low; i <= sub_array.high; i++) {
        printf("%d\t", test_array[i]);
    }
    printf("\n");

    printf("The max sum is: %d\n", sub_array.sum);
    
    return 0;
}
