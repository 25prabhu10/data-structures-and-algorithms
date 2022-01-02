#include <iostream>

using namespace std;

class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal(int n);
    ~Diagonal();

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

Diagonal::Diagonal(int n)
{
    A = new int[n];
    this->n = n;
}

Diagonal::~Diagonal()
{
    delete[] A;
}

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

int Diagonal::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];

    return 0;
}

void Diagonal::Display()
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (i == j)
                printf("%d ", A[i]);
            else
                printf("0 ");

        printf("\n");
    }
}

int main()
{
    Diagonal m(4);

    m.Set(1, 1, 5);
    m.Set(2, 2, 7);
    m.Set(3, 3, 4);
    m.Set(4, 4, 9);

    printf("\n(3, 3): %d \n\n", m.Get(3, 3));

    m.Display();

    return 0;
}