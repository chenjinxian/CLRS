#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10

void addBinary(
        /*int*/int array_a[], int length_a,
        /*int*/int array_b[], int length_b,
        /*out*/int array_c[])
{
    //in the question, length_a == length_b = n
    const int n = length_a - 1;

    //suppose that the binary num is most-significant first
    int carry = 0;
    for (int i = n; i > 0; i--) {
        int a_add_b = array_a[i] + array_b[i];
        array_c[i + 1] = (a_add_b + carry) % 2;
        carry = (a_add_b + carry) / 2;
    }
    array_c[0] = carry;
}

int main(int argc, char* argv[])
{
    int test_array_a[MAX_NUM] = {1, 0, 0, 1, 1, 0, 0, 0 ,1, 1};
    printf("Test array A is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("\t%d", test_array_a[i]);
    }
    printf("\n");

    int test_array_b[MAX_NUM] = {0, 1, 1, 1, 0, 0, 1, 0 ,1, 1};
    printf("Test array B is:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("\t%d", test_array_b[i]);
    }
    printf("\n");
    
    printf("array C is:\n");
    int array_c[MAX_NUM + 1] = {0};
    addBinary(test_array_a, MAX_NUM, test_array_b, MAX_NUM, array_c);

    for (int i = 0; i <  MAX_NUM + 1; i++) {
        printf("%d\t", array_c[i]);
    }
    printf("\n");
    
    return 0;
}
