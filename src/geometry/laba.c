#include <libgeometry/geometry.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int Quantity;
    scanf("%d", &Quantity);
    struct geometry* g = create(Quantity + 1);
    for (int i = 0; i <= Quantity; ++i) {
        char* str = malloc(sizeof(char) * 1000);
        gets(str);
        circle(str, g);
        free(str);
    }
    for (int i = 0; i < Quantity; ++i) {
        printf("%d круг пересекается с : ", i + 1);
        for (int j = 0; j < Quantity; ++j) {
            if (i != j) {
                if (intersections(g, i, j)) {
                    printf("%d  ", j + 1);
                }
            }
        }
        printf("\n");
    }
    free_g(g);
    return 0;
}
