#include <stdio.h>

int a = 10;

void func1(int n)
{
    if (n > 0)
    {
        a--;
        printf("n = %d \n", n);
        func1(n - 1);
        printf("a = %d \n", a);
    }
}

int func2(int n)
{
    // static int x = 0;

    if (n > 0)
    {
        // x++;
        printf("n = %d \n", n);
        // printf("x = %d \n", x);
        return func2(n - 1) + n;
    }

    return 0;
}

int func3(int n)
{
    static int x = 0;

    if (n > 0)
    {
        x++;
        printf("n = %d \n", n);
        printf("x = %d \n", x);
        return func3(n - 1) + x;
    }

    return 0;
}

int main()
{
    int b = 3;

    printf("n = %d \n", func3(3));
    printf("n = %d \n", func3(3));

    return 0;
}