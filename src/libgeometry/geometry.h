#pragma once

struct coor {
    double x;
    double y;
    double r;
};

struct geometry {
    int maxsize;
    int size;
    struct coor* node;
};

struct geometry* create(int maxsize);
void free_g(struct geometry* g);
int g_insert(struct geometry* g, double xx, double yy, double rr);
int circle(char* string, struct geometry* g);
int intersections(struct geometry* g, int count, int i);