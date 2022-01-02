#include <iostream>

using namespace std;

int main()
{
    int *p;

    p = new int[5];

    p[0] = 10;

    printf("*p = %d\n", *p);
    printf("p[1] = %d\n", p[1]);

    delete[] p;

    return 0;
}