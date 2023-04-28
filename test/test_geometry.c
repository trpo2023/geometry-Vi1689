#include <ctest.h>
#include <libgeometry/calc.h>
#include <libgeometry/geometry.h>
#include <math.h>

CTEST(geometry, intersections)
{
    // int intersections(struct geometry* g, int count, int i)
    //  пересекаются
    struct geometry* g = create(2);
    g_insert(g, 1, 1, 2);
    g_insert(g, 2, 2, 2);
    int expected = 1;
    int result = intersections(g, 0, 1);
    ASSERT_EQUAL(expected, result);
    free_g(g);

    // не пересекаются
    struct geometry* gg = create(2);
    g_insert(gg, 100, -100, 2);
    g_insert(gg, 2, 2, 2);
    expected = 0;
    result = intersections(g, 0, 1);
    free_g(gg);
    ASSERT_EQUAL(expected, result);
}

CTEST(geometry, circle)
{
    // int circle(char* string, int Quantity, struct geometry* g);
    // 1 неправильное название
    int Quantity = 8;
    struct geometry* g = create(Quantity);
    char string1[20] = "cirsle(12 12, 12)";
    int expected = 0;
    int result = circle(string1, g);
    ASSERT_EQUAL(expected, result);

    // 2 отсутвие (
    char string2[20] = "circle)12 12, 12)";
    result = circle(string2, g);
    ASSERT_EQUAL(expected, result);

    // 3 отсутвие )
    char string3[20] = "circle(12 12, 12(";
    result = circle(string3, g);
    ASSERT_EQUAL(expected, result);

    // 4 неправильный символ в скобках
    char string4[20] = "circle(12 12, g)";
    result = circle(string4, g);
    ASSERT_EQUAL(expected, result);

    // 5 скобка не рядом с названием
    char string5[20] = "circle (12 12, 12)";
    result = circle(string5, g);
    ASSERT_EQUAL(expected, result);

    // 6 символ после скобок
    char string6[30] = "circle(12 12, 12)12";
    result = circle(string6, g);
    ASSERT_EQUAL(expected, result);

    // 7 правильная строка
    char string7[20] = "circle(12 12, 12)";
    result = circle(string7, g);
    expected = 1;
    free_g(g);
    ASSERT_EQUAL(expected, result);
}