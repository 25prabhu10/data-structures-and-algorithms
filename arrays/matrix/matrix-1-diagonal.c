#include <stdio.h>

struct Matrix
{
    int A[10];
    int n;
};

// Diagonal matrix
void Set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}

// Diagonal matrix
int Get(struct Matrix *m, int i, int j)
{
    if (i == j)
        return m->A[i - 1];

    return 0;
}

void Display(struct Matrix m)
{
    int i, j;

    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
            if (i == j)
                printf("%d ", m.A[i]);
            else
                printf("0 ");

        printf("\n");
    }
}

int main()
{
    struct Matrix m;

    m.n = 4;

    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 7);
    Set(&m, 3, 3, 4);
    Set(&m, 4, 4, 9);

    printf("\n(3, 3): %d \n\n", Get(&m, 3, 3));

    Display(m);

    return 0;
}