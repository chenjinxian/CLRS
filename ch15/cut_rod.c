#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10

int cutRod(int price[], int length)
{
    if (length == 0)
        return 0;

    int max_sum = -1;
    for (int i = 0; i < length; i++) {
        int sub_sum = price[i] + cutRod(price, length -1 - i);
        if (sub_sum > max_sum)
            max_sum = sub_sum;
    }

    return max_sum;
}

int main(int argc, char* argv[])
{
    int price[MAX_NUM] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int ret = cutRod(price, 30);
    printf("the max is: %d\n", ret);
    
    return 0;
}
