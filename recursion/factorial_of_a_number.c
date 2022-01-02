#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
        return 1;

    else if (n < 0)
    {
        perror("Invalid input");
        return -1;
    }

    return n * factorial(n - 1);
}

// int factorial(int n)
// {
//     int i, fact = 1;

//     for (i = 1; i <= n; i++)
//         fact *= i;

//     return fact;
// }

// int factorial(int n)
// {
//     if (n == 1)
//         return 1;

//     return n * factorial(n - 1);
// }

int main()
{
    int n;

    n = factorial(-1);
    printf("%d\n", n);

    return 0;
}