#include <stdio.h>

int power(int x, int n)
{
    if (n == 0)
        return 1;

    else if (n % 2 == 0)
        return power(x * x, n / 2);

    return x * power(x * x, (n - 1) / 2);
}

int factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

double taylor_series(int x, int n)
{
    static double temp = 0;

    if (n == 0)
        return 1;

    temp = (double)power(x, n) / (double)factorial(n);

    return temp + taylor_series(x, n - 1);
}

// ALTERNATE METHOD
double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;

    if (n == 0)
        return 1;

    r = e(x, n - 1);
    p = p * x;
    f = f * n;

    return r + (p / f);
}

int main()
{
    double n;

    n = e(4, 100);
    printf("%f\n", n);

    return 0;
}