#include <stdio.h>

// int factorial(int x)
// {
//     if (x == 0)
//         return 1;

//     return x * factorial(x - 1);
// }

// int combinations(int n, int r)
// {
//     return factorial(n) / (factorial(r) * factorial(n - r));
// }

int combinations(int n, int r)
{
    if (r == 0 || r == n)
        return 1;

    return combinations(n - 1, r - 1) + combinations(n - 1, r);
}

int main()
{
    int n, r;

    scanf("%d", &n);
    scanf("%d", &r);

    printf("combination = %d\n", combinations(n, r));
    return 0;
}