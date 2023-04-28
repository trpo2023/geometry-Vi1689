#include <libgeometry/calc.h>
#include <libgeometry/geometry.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define kv(x) (x) * (x)

#define PI 3.1415

struct geometry* create(int maxsize)
{
    struct geometry* g = malloc(sizeof(*g));
    if (g != NULL) {
        g->maxsize = maxsize;
        g->size = 0;
        g->node = malloc(sizeof(*g->node) * maxsize);
        if (!(g->node)) {
            free(g);
            return NULL;
        }
    }
    return g;
}

void free_g(struct geometry* g)
{
    if (g->node != NULL) {
        free(g->node);
        free(g);
    }
}

int g_insert(struct geometry* g, double xx, double yy, double rr)
{
    if (g->size > g->maxsize) {
        return -1;
    }
    g->node[g->size].x = xx;
    g->node[g->size].y = yy;
    g->node[g->size].r = rr;
    g->size++;
    return 0;
}

int circle(char* string, struct geometry* g)
{
    char* string1 = malloc(sizeof(char) * 1000);
    int k = 0, l = 0, r = 0, p = 0, flag = 0;
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
        printf("\nError at column 6: expected '('\n");
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
        printf("\nError at column 15: expected ')'\n");
        return 0;
    }
    for (int i = r + 1; i < strlen(string); ++i) {
        if (string[i] != ' ') {
            string2[i] = '^';
            printf("%s", string2);
            printf("\nError at column %d: unexpected token\n", i);
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
        printf("\nError at column 0: expected 'circle'\n");
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
             && string[i] != '8' && string[i] != '9' && string[i] != '0'
             && string[i] != '-')) {
            string2[i] = '^';
            printf("%s", string2);
            printf("\nError at column %d: expected '<double>'\n", i);
            return 0;
        }
    }
    k = 0;
    char* number = malloc(sizeof(char) * (r - l));
    float* number1 = malloc(sizeof(float) * (r - l));
    // printf("\n%s\n", string);
    for (int i = 7; i < r; ++i) {
        if (string[i] != ',') {
            number[p++] = string[i];
        } else {
            number1[k++] = atof(number);
            p = 0;
            memset(number, 0, sizeof(char) * (r - l));
        }
    }
    number1[k] = atof(number);
    float* number2 = malloc(sizeof(float) * 3);
    number2[0] = 0;
    number2[1] = 0;
    number2[2] = 0;
    for (int i = 0, q = 0; i < r; ++i) {
        if (number1[i] != 0) {
            number2[q++] = number1[i];
        }
    }
    if (g_insert(g, number2[0], number2[1], number2[2])) {
        printf("Не записалось\n");
        return 0;
    }
    // printf("%f %f %f\n",g->node[g->size - 1].x,g->node[g->size -
    // 1].y,g->node[g->size - 1].r);
    printf("Perimeter = %f\nArea = %f\n",
           perimeter(g->node[g->size - 1].r),
           area(g->node[g->size - 1].r));
    free(string1);
    free(number);
    free(number1);
    free(number2);
    free(string2);
    return 1;
}

int intersections(struct geometry* g, int count, int i)
{
    double length_between
            = sqrt(kv(g->node[count].x - g->node[i].x)
                   + kv(g->node[count].y - g->node[i].y));
    if (g->node[count].r + g->node[i].r > length_between) {
        return 1; // пересекаются
    }
    return 0; // не пересекаются
}