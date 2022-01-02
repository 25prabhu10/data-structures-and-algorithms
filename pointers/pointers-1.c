#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a = 10;
    int *p;

    p = &a;

    printf("size of a = %lu\n", sizeof(a));
    printf("size of p = %lu\n", sizeof(p));

    printf("A = %d\n", a);
    printf("*p = A = %d\n", *p);
    // printf("%lu\n", p);  // address of a
    // printf("%lu\n", &a); // address of a

    int A[5] = {2, 4, 6, 8, 10};
    int *p1;
    int *p2;

    // A ITSELF POINTS TO THE FIRST ELEMENT OF THE ARRAY
    p1 = A;
    p2 = &A[3];

    // PRINT DATA PRESENT IN a
    // printf("%d\n", A);
    printf("*p1 = %d\n", *p1);
    printf("p1[0] = %d\n", p1[0]);
    printf("*A = %d\n", *A);
    printf("A[0] = %d\n", A[0]);
    printf("*p2 = %d\n", *p2);

    int *p3;

    p3 = (int *)malloc(5 * sizeof(int));

    p3[0] = 10;

    printf("*p3 = %d\n", *p3);
    printf("p3[1] = %d\n", p3[1]);

    free(p3);

    return 0;
}