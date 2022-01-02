#include <stdio.h>

// void fibonacci_series(int n)
// {
//     int x = 0, y = 1;

//     for (; n >= 0; n--)
//     {
//         printf("%d ", x);
//         x = x + y;
//         y = x - y;
//     }
// }

// int fibonacci_series(int n)
// {
//     int x = 0, y = 1;

//     if (n <= 1)
//         return n;

//     for (; n >= 2; n--)
//     {
//         y = x + y;
//         x = y - x;
//     }

//     return y;
// }

// int fibonacci_series(int n)
// {
//     if (n <= 1)
//         return n;

//     return fibonacci_series(n - 2) + fibonacci_series(n - 1);
// }

int cache[10] = {[0 ... 9] = -1};

int fibonacci_series(int n)
{
    if (n < 2)
    {
        cache[n] = n;
        return n;
    }

    else
    {
        if (cache[n - 2] == -1)
            cache[n - 2] = fibonacci_series(n - 2);

        if (cache[n - 1] == -1)
            cache[n - 1] = fibonacci_series(n - 1);
    }

    cache[n] = cache[n - 2] + cache[n - 1];

    return cache[n];
}

int main()
{
    printf("%d\n", fibonacci_series(7));

    return 0;
}