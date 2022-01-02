#include <stdio.h>

// Fnding single missing element(s) in an array

// 1. If the array contains sequence of natural number starting from 1
// O(n)

void find_single_missing_1(int A[], int n)
{
    int i, sum1, sum2 = 0;

    sum1 = (n * (n - 1)) / 2;

    for (i = 0; i < n; i++)
        sum2 += A[i];

    printf("Missing Element: %d\n", sum1 - sum2);
}

// 2. If the array contains sequence of natural number starting from 6
// O(n)

void find_single_missing_2(int A[], int n)
{
    int i, difference;

    difference = A[0] - 0;

    for (i = 0; i < n; i++)
        if (A[i] - i != difference)
        {
            printf("Missing Element: %d\n", difference + i);
            break;
        }
}

// 3. If the array contains sequence of natural number starting from 6
// O(n)

void find_multiple_missing_2(int A[], int n)
{
    int i, difference;

    difference = A[0] - 0;

    for (i = 0; i < n; i++)
        if (A[i] - i != difference)
            while (difference < A[i] - 1)
            {
                printf("Missing Element: %d\n", difference + i);

                difference++;
            }
}

// 4. If the array contains sequence of natural number in random order
// Simple or example HashTable/Bitset
// O(n)

void find_multiple_missing_1(int A[], int n)
{
    int i, temp[n];

    for (i = 0; i < n; i++)
        temp[A[i - 1]]++;

    for (i = 0; i < n; i++)
        if (temp[i] == 0)
            printf("Missing Element: %d\n", i + 1);
}

void find_and_count_duplicates_sorted(int A[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
        if (A[i] == A[i + 1])
        {
            j = i + 1;

            while (A[j] == A[i])
                j++;

            // if (A[i] != A[i - 1])
            printf("Found Duplicate Element: %d, %d times\n", A[i], j - i);

            i = j - 1;

            // count++;
        }
}

void find_and_count_duplicates_sorted_simple_hash(int A[], int n)
{
    int i, B[10] = {0};

    for (i = 0; i < n - 1; i++)
        if (A[i] == A[i + 1])
            B[A[i] - 1]++;

    for (i = 0; i < n; i++)
        if (B[i] > 0)
            printf("Found Duplicate Element: %d, %d times\n", i + 1, B[i]);
}

int main()
{
    int A[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    find_and_count_duplicates_sorted(A, 10);
    find_and_count_duplicates_sorted_simple_hash(A, 10);
    return 0;
}