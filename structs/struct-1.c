#include <stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{

    struct Rectangle r1;

    r1.length = 10;
    r1.breadth = 20;

    printf("%lu\n", sizeof(r1));
    printf("%d\n", r1.length);
    printf("%d\n", r1.breadth);

    return 0;
}