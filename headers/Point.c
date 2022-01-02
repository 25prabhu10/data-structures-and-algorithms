// echo "" | gcc -o3 -E -Wp, -v -

// objdump -d arrays-ADT-2.o // ASSEMBLY CODE OF THE OBJECT
// objdump -t arrays-ADT-2.o

#include <stdio.h>

#include "Point.h"

Point Point_value(double x, double y)
{
    Point initialized = {x, y};
    return initialized;
}

void Point_print(Point *self)
{
    printf("(%f, %f)\n", self->x, self->y);
}

int main()
{
    return 0;
}