#include <stdio.h>

void func1(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        func1(n - 1);
    }
}

int main()
{
    int n = 3;

    func1(3);

    return 0;
}