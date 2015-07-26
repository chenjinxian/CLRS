#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void computePrefixFunction(
        const char* str_pattern,
        int len,
        int array[])
{
    array[0] = 0;
    int k = 0;
    for (int q = 2; q < len; q++) {
        while (k > 0 && str_pattern[k] != str_pattern[q])
            k = array[k - 1];

        if (str_pattern[k] == str_pattern[q])
            k++;
        array[q] = k;
    }
}

void kmpMatcher(char* str_text, char* str_pattern)
{
    int n = strlen(str_text);
    int m = strlen(str_pattern);

    int *array = (int*)malloc(sizeof(int) * m);
    memset(array, 0, sizeof(int) * m);
    computePrefixFunction(str_pattern, m, array);

    printf("the prefix array is:\n");
    for (int i = 0; i < m; i++)
        printf("%d\t", array[i]);
    printf("\n");

    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && str_pattern[q] != str_text[i])
            q = array[q - 1];

        if (str_pattern[q] == str_text[i])
            q++;
        if (q == m) {
            printf("Pattern occurs with shift: %d\n", i - m + 1);
            q = array[q - 1];
        }
    }

    free(array);
}

int main(int argc, char* argv[])
{
    printf("Text: abcabaabcabac, Pattern: abaa\n");
    char* str_text = "abcabaabcabac";
    char* str_pattern = "abaa";
    kmpMatcher(str_text, str_pattern);

    return 0;
}
