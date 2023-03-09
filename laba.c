#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14

int main()
{
    char* string = malloc(sizeof(char) * 200);
    char* string1 = malloc(sizeof(char) * 200);
    int k = 0, l = 0, r = 0, p = 0, flag = 0;
    gets(string);
    char* string2 = malloc(sizeof(char) * strlen(string));
    memset(string2, ' ', sizeof(char) * strlen(string));
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == '(') {
            l = i;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        string2[6] = '^';
        printf("%s", string2);
        printf("\nError at column 6: expected '('");
        return 0;
    }
    flag = 0;
    for (int i = l; i < strlen(string); ++i) {
        if (string[i] == ')') {
            r = i;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        string2[15] = '^';
        printf("%s", string2);
        printf("\nError at column 15: expected ')'");
        return 0;
    }
    for (int i = r + 1; i < strlen(string); ++i) {
        if (string[i] != ' ') {
            string2[i] = '^';
            printf("%s", string2);
            printf("\nError at column %d: unexpected token", i);
            return 0;
        }
    }
    for (int i = 0; i < r; ++i) {
        if (string[i] != ' ') {
            string1[k++] = string[i];
        }
    }
    if (!((string1[0] == 'c' || string1[0] == 'C')
          && (string1[1] == 'i' || string1[1] == 'I')
          && (string1[2] == 'r' || string1[2] == 'R')
          && (string1[3] == 'c' || string1[3] == 'C')
          && (string1[4] == 'L' || string1[4] == 'l')
          && (string1[5] == 'e' || string1[5] == 'E') && (string[6] == '('))) {
        string2[0] = '^';
        printf("%s", string2);
        printf("\nError at column 0: expected 'circle'");
        return 0;
    }
    printf("%s\n", string);
    for (int i = l; i <= r; ++i) {
        if (string[i] == ' ') {
            string[i] = ',';
        }
    }
    for (int i = l + 1; i < r; ++i) {
        if ((string[i] != ',' && string[i] != '.' && string[i] != '1'
             && string[i] != '2' && string[i] != '3' && string[i] != '4'
             && string[i] != '5' && string[i] != '6' && string[i] != '7'
             && string[i] != '8' && string[i] != '9' && string[i] != '0')) {
            string2[i] = '^';
            printf("%s", string2);
            printf("\nError at column %d: expected '<double>'", i);
            return 0;
        }
    }
    k = 0;
    char* number = malloc(sizeof(char) * (r - l));
    float* number1 = malloc(sizeof(float) * (r - l));
    for (int i = 7; i < r - 1; ++i) {
        if (string1[i] != ',') {
            number[p++] = string1[i];
        } else {
            number1[k++] = atof(number);
            p = 0;
            memset(number, 0, sizeof(char) * (r - l));
        }
    }
    number1[k] = atof(number);
    float per = 0, s = 0;
    per = 2 * PI * number1[k];
    if (per * -1 > 0) {
        per *= -1;
    }
    s = PI * number1[k] * number1[k];
    printf(" %f\n %f", per, s);
    free(string);
    free(string1);
    free(number);
    free(number1);
    free(string2);
    return 0;
}