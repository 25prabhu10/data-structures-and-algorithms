#include <stdio.h>

int i = 1;

void recursion_3_tree(int n)
{
    if (n > 0)
    {
        // printf("n = %d\n\n", n);
        recursion_3_tree(n - 1);
        recursion_3_tree(n - 1);
        printf("%d ", n);
        // printf("============================================================ %d\n\n", i);
        i++;
    }
}

int main()
{
    recursion_3_tree(6);
    printf("\n");

    recursion_3_tree(5);
    printf("\n");

    recursion_3_tree(4);
    printf("\n");

    recursion_3_tree(3);
    printf("\n");

    recursion_3_tree(2);
    printf("\n");

    recursion_3_tree(1);
    printf("\n");

    return 0;
}