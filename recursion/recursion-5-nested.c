#include <stdio.h>

int func(int n)
{
    if (n > 100)
    {
        printf("%d\n", n);
        return n - 10;
    }

    else
        func(func(n + 11));

    return 0;
}

int main()
{
    func(95);

    return 0;
}