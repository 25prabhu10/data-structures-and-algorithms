#include <iostream>

using namespace std;

int main()
{
    int a = 10;

    int &r = a;

    printf("sizeof(r) = %lu\n", sizeof(r));
    printf("sizeof(a) = %lu\n", sizeof(a));

    printf("r = %d\n", r);
    printf("a = %d\n", a);
}