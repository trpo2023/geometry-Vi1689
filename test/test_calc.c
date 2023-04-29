#include <ctest.h>
#include <libgeometry/calc.h>
#include <math.h>

#define PI 3.1415

CTEST(calc, perimeter)
{
    const float radius = 3;
    float expected = 2 * PI * radius;
    float result = perimeter(radius);
    ASSERT_EQUAL(expected, result);
}

CTEST(calc, area)
{
    const float radius = 3;
    float expected = PI * radius * radius;
    float result = area(radius);
    ASSERT_EQUAL(expected, result);
}
