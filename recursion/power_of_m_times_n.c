#include <stdio.h>

// int power_of_m_times_n(int m, int n)
// {
//     if (n == 0)
//         return 1;

//     return m * power_of_m_times_n(m, n - 1);
// }

// int power_of_m_times_n(int m, int n)
// {
//     int i, power = 1;

//     for (i = 0; i < n; i++)
//         power *= m;

//     return power;
// }

// int power_of_m_times_n(int m, int n)
// {
//     if (n == 0)
//         return 1;

//     if (n % 2 == 0)
//         return power_of_m_times_n(m * m, n / 2);

//     return m * power_of_m_times_n(m * m, (n - 1) / 2);
// }

int power_of_m_times_n(int m, int n)
{
    int result = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
            result *= m;

        m *= m;
        n /= 2;
    }

    return result;
}

int main()
{
    printf("%d\n", power_of_m_times_n(2, 10));

    return 0;
}