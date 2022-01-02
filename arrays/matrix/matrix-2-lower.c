#include <stdio.h>
#include <stdlib.h>

struct Lower
{
    int *A;
    int n;
};

void Set(struct Lower *m, int i, int j, int x)
{
    if (i >= j)
        m->A[((i * (i - 1)) / 2) + (j - 1)] = x;
}

int Get(struct Lower *m, int i, int j)
{
    if (i >= j)
        return m->A[((i * (i - 1)) / 2) + (j - 1)];

    return 0;
}

void Display(struct Lower m)
{
    int i, j;

    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
            if (i >= j)
                printf("%d ", m.A[((i * (i - 1)) / 2) + (j - 1)]);
            else
                printf("0 ");

        printf("\n");
    }
}

int main()
{
    struct Lower m;
    int i, j, temp = 0;

    printf("Enter Dimensions: ");
    scanf("%d", &m.n);
    // m.n = 4;

    m.A = (int *)malloc(((m.n * (m.n - 1)) / 2) * sizeof(int));

    printf("Enter all elements:\n");

    for (i = 1; i <= m.n; i++)
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &temp);
            Set(&m, i, j, temp);
        }

    printf("\n\n\n(3, 3): %d \n\n", Get(&m, 3, 3));

    Display(m);

    return 0;
}