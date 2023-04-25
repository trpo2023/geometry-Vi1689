#include <libgeometry/geometry.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* string = malloc(sizeof(char) * 200);
    gets(string);
    circle(string);
    return 0;
}