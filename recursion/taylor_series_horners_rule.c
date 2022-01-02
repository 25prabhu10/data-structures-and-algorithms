#include <stdio.h>

double e(double x, double n)
{
    double s = 1;

    for (; n > 0; n--)
        s = 1 + (x / n) * s;

    return s;
}

// double e(double x, double n)
// {
//     static double s = 1;

//     if (n == 0)
//         return s;

//     s = 1 + (x / n) * s;

//     return e(x, n - 1);
// }

int main()
{
    printf("%f\n", e(2, 4));

    return 0;
}