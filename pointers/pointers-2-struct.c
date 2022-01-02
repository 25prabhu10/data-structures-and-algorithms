#include <stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r = {10, 5};
    struct Rectangle *p = &r;

    r.length = 15;
    (*p).breadth = 25; // *p IS ENCLOSED INSIDE A BRACKET BECAUSE `.` HAS HIGHER PRIORITY THAN `*`
    p->length = 25;    // ALTERNATIVE METHOD

    printf("%d %d\n", r.length, r.breadth);
    printf("%d %d\n", (*p).length, (*p).breadth);
    printf("%d %d\n", p->length, p->breadth);
    // printf("%d\n", r);
}