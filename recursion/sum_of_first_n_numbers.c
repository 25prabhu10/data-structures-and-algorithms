#include <stdio.h>

// int sum_of_first_n_numbers(int n)
// {
//     if (n == 1)
//         return 1;
//     else
//         return n + sum_of_first_n_numbers(n - 1);
// }

// int sum_of_first_n_numbers(int n)
// {
//     return n * (n + 1) / 2;
// }

int sum_of_first_n_numbers(int n)
{
    int i, s = 0;

    for (i = 1; i <= n; i++)
        s += i;

    return s;
}

int main()
{
    int n;

    n = sum_of_first_n_numbers(10);
    printf("%d\n", n);

    return 0;
}