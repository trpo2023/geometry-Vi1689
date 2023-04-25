#include <libgeometry/calc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

double perimeter(double a)
{
    double per;
    per = 2 * PI * a;
    if (per * -1 > 0) {
        per *= -1;
    }
    return per;
}

double area(double a)
{
    double s;
    s = PI * a * a;
    return s;
}