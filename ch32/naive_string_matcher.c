#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void naiveStringMatcher(char* str_text, char* str_pattern)
{
    int n = strlen(str_text);
    int m = strlen(str_pattern);

    for (int s = 0; s < n - m + 1; s++) {
        int i;
        for (i = 0; i < m; i++) {
            if (str_pattern[i] != str_text[s + i])
                break;
        }

        if (i == m)
            printf("Pattern occurs with shift: %d\n", s);
    }
}

void matchDiffPattern(char* str_text, char* str_pattern)
{
    int n = strlen(str_text);
    int m = strlen(str_pattern);

    for (int s = 0; s < n - m + 1; s++) {
        if (str_text[s] != str_pattern[0])
            continue;

        int i;
        for (i = 1; i < m; i++) {
            if (str_pattern[i] != str_text[++s])
                break;
        }

        if (i == m)
            printf("Pattern occurs with shift: %d\n", s - 1);
    }
}

bool matchGapCharacter(char* str_text, char* str_pattern)
{
    int n = strlen(str_text);
    int m = strlen(str_pattern);
    
    int s = 0, i = 0;
    while (s < n && i < m) {
        if (str_text[s] == str_pattern[i]) {
            s++;
            i++;
        }
        else if (str_pattern[i] == 0x2A &&
                matchGapCharacter(str_text + s, str_pattern + (i + 1))) {
            return true;
        }
        else
            s++;
    }

    return i >= m;
}

int main(int argc, char* argv[])
{
    printf("Text: abcabaabcabac, Pattern: abaa\n");
    char* str_text = "abcabaabcabac";
    char* str_pattern = "abaa";
    naiveStringMatcher(str_text, str_pattern);

    printf("Text: 000010001010001, Pattern: 0001\n");
    char* str_text1 = "000010001010001";
    char* str_pattern1 = "0001";
    naiveStringMatcher(str_text1, str_pattern1);

    printf("Text: abcabaabcabac, Pattern: bac(all chars are different)\n");
    char* str_text2 = "abcabaabcabac";
    char* str_pattern2 = "bac";
    matchDiffPattern(str_text2, str_pattern2);

    printf("Text: abccbacbacab, Pattern: ab*ba*c(contain gap character '*')\n");
    char* str_text3 = "abccbacbacab";
    char* str_pattern3 = "ab*ba*c";
    bool ret = matchGapCharacter(str_text3, str_pattern3);
    printf(ret ? "True" : "False");
    printf("\n");

    return 0;
}
