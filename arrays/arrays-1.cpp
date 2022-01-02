#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int A[n];

    // int A[5] = {1, 2, 3, 4, 5};

    cout << sizeof(A) << endl;
    printf("%d\n", sizeof(A));

    for (int x : A)
    {
        cout << x << endl;
    }

    return 0;
}