#include <stdio.h>
#include <string.h>

int string_validity(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
            return 1;

    return 0;
}

int main()
{
    // char S[] = "Howareyou?";
    // char A[] = "Painter";
    // char B[] = "Painting";
    // int i, H = 0, x = 0;

    // int i, count = 0;

    // for (i = 0; S[i] != '\0'; i++)
    // {
    //     if (S[i] >= 65 && S[i] <= 90)
    //         S[i] = S[i] + 32;

    //     else if (S[i] >= 97 && S[i] <= 122)
    //         S[i] = S[i] - 32;
    // }

    // for (i = 0; S[i] != '\0'; i++)
    // {
    //     if (S[i] == 65 || S[i] == 69 || S[i] == 73 || S[i] == 79 || S[i] == 85 || S[i] == 97 || S[i] == 101 || S[i] == 105 || S[i] == 111 || S[i] == 117)
    //         v++;

    //     else if ((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122))
    //         c++;
    // }

    // for (i = 0; S[i] != '\0'; i++)
    //     if (S[i] == 32 && S[i + 1] != 32)
    //         count++;

    // for (j = 0; S[j] != '\0'; j++)
    // {
    // }

    // j--;

    // for (i = 0; i < j; i++, j--)
    // {
    //     temp = S[i];
    //     S[i] = S[j];
    //     S[j] = temp;
    // }

    // for (i = 0; A[i] != '\0' && B[i] != '\0'; i++)
    // {
    //     if (A[i] != B[i])
    //     {
    //         printf("Not same\n");

    //         if (A[i] < B[i])
    //             printf("A is smaller than B\n");

    //         else if (A[i] > B[i])
    //             printf("B is smaller than A\n");

    //         break;
    //     }
    // }

    // Find Duplicate
    // for (i = 0; B[i] != '\0'; i++)
    // {
    //     x = 1;
    //     x = x << (B[i] - 97);

    //     printf("%c: %d: %d: H:%d\n", B[i], B[i], x & B[i], x & H);

    //     if ((x & H) > 0)
    //     {
    //         printf("%c is duplicate\n", B[i]);
    //     }

    //     else
    //         H = x | H;
    // }

    char A[] = "decimal";
    char B[] = "medical";
    // char C[] = "medical";

    int i, j, H[26] = {0};

    for (i = 0; A[i] != '\0'; i++)
        H[A[i] - 97] += 1;

    for (j = 0; B[j] != '\0'; j++)
    {
        H[B[j] - 97] -= 1;
        if (H[B[j] - 97] < 0)
        {
            printf("Not anagrams\n");
            break;
        }
    }

    return 0;
}
