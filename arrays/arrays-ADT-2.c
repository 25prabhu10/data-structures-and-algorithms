#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// struct Array
// {
//     int A[20];
//     int size;
//     int length;
// };

struct Array
{
    int *A;
    int size;
    int length;
};

// void Initialize(struct Array *arr)
// {
//     int n, i;
//     printf("Enter the size of the array: ");
//     scanf("%d", &arr->size);

//     arr->A = (int *)malloc(arr->size * sizeof(int));
//     arr->length = 0;

//     printf("Enter number of elements to be entered: ");
//     scanf("%d", &n);

//     printf("Enter all elements\n");

//     for (i = 0; i < n; i++)
//         scanf("%d", &arr->A[i]);

//     arr->length = n;
// }

void Display(struct Array arr)
{
    int i;

    printf("All elements are:\n");

    for (i = 0; i < arr.length; i++)
        printf("(%d, %d) ", i, arr.A[i]);
}

void Append(struct Array *arr, int newElement)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = newElement;
}

void Insert(struct Array *arr, int index, int newElement)
{
    int i;

    if (index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[index] = newElement;
        arr->length++;
    }

    // else
    // {
    //     arr->A[index] = newElement;
    //     arr->length = index + 1;
    // }
}

int Delete(struct Array *arr, int index)
{
    int x = -1, i;

    // for (i = 0; i < arr->length; i++)
    // {
    //     if (arr->A[i] == element)
    //     {
    //         index = i;
    //         break;
    //     }
    // }

    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];

        for (i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }

        arr->length--;
    }

    return x;
}

int Linear_search(struct Array arr, int key)
{
    int i;

    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int Linear_search_transposition(struct Array *arr, int key)
{
    int i;

    for (i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            arr->A[i] = arr->A[i - 1];
            arr->A[i - 1] = key;
            return i;
        }
    }

    return -1;
}

int Linear_search_move_front(struct Array *arr, int key)
{
    int i;

    for (i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            arr->A[i] = arr->A[0];
            arr->A[0] = key;
            return i;
        }
    }

    return -1;
}

int Binary_search(struct Array arr, int key)
{
    int low = 0, mid, high = arr.length - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr.A[mid] == key)
            return mid;

        else if (arr.A[mid] > key)
            high = mid - 1;

        else
            low = mid + 1;

        mid = low + high / 2;
    }

    return -1;
}

int Binary_search_recursion(int A[], int low, int high, int key)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high) / 2;

        if (A[mid] == key)
            return mid;

        else if (A[mid] > key)
            return Binary_search_recursion(A, low, mid - 1, key);

        else
            return Binary_search_recursion(A, mid + 1, high, key);
    }

    return -1;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];

    return -1;
}

void Set(struct Array *arr, int index, int key)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = key;
}

int Max(struct Array arr)
{
    int i = 0, max = arr.A[i];

    for (; i < arr.length; i++)
        if (max < arr.A[i])
            max = arr.A[i];

    return max;
}

int Min(struct Array arr)
{
    int i = 0, min = arr.A[i];

    for (; i < arr.length; i++)
        if (min > arr.A[i])
            min = arr.A[i];

    return min;
}

int Sum(struct Array arr)
{
    int i, sum = 0;

    for (i = 0; i < arr.length; i++)
        sum += arr.A[i];

    return sum;
}

int Sum_recursive(int A[], int n)
{
    if (n < 0)
        return 0;

    return Sum_recursive(A, n - 1) + A[n];
}

float Average(struct Array arr)
{
    int i, sum = 0;

    for (i = 0; i < arr.length; i++)
        sum += arr.A[i];

    return (float)sum / arr.length;
}

void Reverse_auxilary_array(struct Array *arr)
{
    int i, j, *B;

    B = (int *)malloc(arr->length * sizeof(int));

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];

    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void Reverse(struct Array *arr)
{
    // int i, temp;

    // for (i = 0; i < arr->length / 2; i++)
    // {
    //     temp = arr->A[i];

    //     arr->A[i] = arr->A[arr->length - i - 1];

    //     arr->A[arr->length - i - 1] = temp;
    // }

    int i, j, temp;

    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];

        arr->A[i] = arr->A[j];

        arr->A[j] = temp;
    }
}

void Left_shift(struct Array *arr)
{
    int i;

    // for (i = 0; i < places; i++)

    for (i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];

    arr->length -= 1;
}

void Left_rotate(struct Array *arr)
{
    int i, temp;

    // for (i = 0; i < places; i++)

    temp = arr->A[0];

    for (i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];

    arr->A[arr->length - 1] = temp;
}

void Right_shift(struct Array *arr)
{
    int i;

    // for (i = 0; i < places; i++)

    for (i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];

    arr->length -= 1;
}

void Right_rotate(struct Array *arr)
{
    int i, temp;

    // for (i = 0; i < places; i++)
    temp = arr->A[arr->length - 1];

    for (i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];

    arr->A[0] = temp;
}

void Insert_in_sorted_order(struct Array *arr, int key)
{
    int i = arr->length - 1;

    if (arr->length < arr->size)
    {
        while (arr->A[i] > key && i >= 0)
        {
            arr->A[i + 1] = arr->A[i];
            i--;
        }

        arr->A[i + 1] = key;
        arr->length++;
    }
}

int Is_sorted(struct Array arr)
{
    int i;

    for (i = 0; i < arr.length - 2; i++)
        if (arr.A[i] > arr.A[i + 1])
            return 0;

    return 1;
}

void Rearrange(struct Array *arr)
{
    int i, j, temp;
    i = 0;
    j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;

        if (i < j)
        {
            temp = arr->A[i];

            arr->A[i] = arr->A[j];

            arr->A[j] = temp;
        }
    }
}

struct Array *Merge(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];

        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = arr1.length + arr2.length;
    arr3->size = 20;

    return arr3;
}

struct Array *Union(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];

        else if (arr1.A[i] > arr2.A[j])
            arr3->A[k++] = arr2.A[j++];

        else
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}

struct Array *Union_unsorted(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    for (; i < arr1.length; i++, k++)
    {
        arr3->A[k] = arr1.A[i];
        arr3->length++;
    }

    for (; j < arr1.length; j++)
    {
        if (Linear_search(*arr3, arr2.A[j]) == -1)
        {
            arr3->A[k] = arr2.A[j];
            k++;
            arr3->length++;
        }
    }

    return arr3;
}

struct Array *Intersection(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            i++;

        else if (arr1.A[i] > arr2.A[j])
            j++;

        else if (arr1.A[i] == arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 20;

    // for (i = 0; i < arr1.length; i++)
    // {
    //     for (j = 0; j < arr2.length; j++)
    //     {
    //         if (arr1.A[i] == arr2.A[j])
    //         {
    //             arr3->A[k] = arr1.A[i];
    //             arr3->length++;
    //             k++;
    //         }
    //     }
    // }

    return arr3;
}

struct Array *Difference(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];

        else if (arr1.A[i] > arr2.A[j])
            j++;

        else if (arr1.A[i] == arr2.A[j])
        {
            i++;
            j++;
        }
    }

    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];

    arr3->length = k;
    arr3->size = 20;

    // for (i = 0; i < arr1.length; i++)
    // {
    //     found = 0;

    //     for (j = 0; j < arr2.length; j++)
    //     {
    //         if (arr1.A[i] == arr2.A[j])
    //         {
    //             found = 1;
    //             break;
    //         }
    //     }

    //     if (found == 0)
    //     {
    //         arr3->A[k] = arr1.A[i];
    //         arr3->length++;
    //         k++;
    //     }
    // }

    return arr3;
}

int main()
{
    // struct Array arr = {{-1, 0, -3, 5, 7, -11, 13, 17}, 20, 8};
    // struct Array sorted_arr = {{1, 2, 3, 5, 7, 11, 13, 17}, 20, 8};
    // struct Array sorted_arr_2 = {{5, 17, 99, 11}, 20, 4};
    // struct Array *merged_arr;
    // struct Array *unsorted_union_arr;
    // struct Array *intersected_arr;
    // struct Array *difference_arr;

    // Append(&arr, 25);

    // Insert(&arr, 2, 99);
    // Insert(&arr, 10, 99);
    // Insert(&arr, 13, 99);

    // printf("\n\nLength: %d\n", arr.length);

    // printf("Deleted: %d\n\n", Delete(&arr, 10));

    // Display(arr);
    // printf("\n\nFound 17 at %d normal\n", Linear_search(arr, 17));
    // printf("Found 17 at %d normal\n", Linear_search(arr, 17));
    // printf("Found 17 at %d normal\n", Linear_search(arr, 17));
    // printf("Found 5 at %d normal\n", Linear_search(arr, 5));
    // printf("Found 17 at %d normal\n\n", Linear_search(arr, 17));

    // Display(arr);
    // printf("\n\nFound 17 at %d transpostion\n", Linear_search_transposition(&arr, 17));
    // printf("Found 17 at %d transpostion\n", Linear_search_transposition(&arr, 17));
    // printf("Found 17 at %d transpostion\n", Linear_search_transposition(&arr, 17));
    // printf("Found 5 at %d transpostion\n", Linear_search_transposition(&arr, 5));
    // printf("Found 17 at %d transpostion\n\n", Linear_search_transposition(&arr, 17));

    // Display(arr);
    // printf("\n\nFound 17 at %d move front\n", Linear_search_move_front(&arr, 17));
    // printf("Found 17 at %d move front\n", Linear_search_move_front(&arr, 17));
    // printf("Found 17 at %d move front\n", Linear_search_move_front(&arr, 17));
    // printf("Found 5 at %d move front\n", Linear_search_move_front(&arr, 5));
    // printf("Found 17 at %d move front\n\n", Linear_search_move_front(&arr, 17));

    // // printf("Found 17 at %d\n", Linear_search(arr, 17));
    // // printf("Found 10 at %d\n", Linear_search(arr, 100));

    // printf("\n\nFound 17 at %d binary\n", Binary_search(sorted_arr, 17));
    // printf("Found 2 at %d binary\n", Binary_search(sorted_arr, 99));
    // printf("Found 5 at %d binary\n", Binary_search(sorted_arr, 1));
    // printf("\nFound 17 at %d binary_recursive\n", Binary_search_recursion(sorted_arr.A, 0, arr.length - 1, 17));
    // printf("Found 2 at %d binary_recursive\n", Binary_search_recursion(sorted_arr.A, 0, arr.length - 1, 99));
    // printf("Found 5 at %d binary_recursive\n", Binary_search_recursion(sorted_arr.A, 0, arr.length - 1, 1));

    // Set(&arr, 5, 29);

    // printf("\n\nGet element at 5: %d\n", Get(arr, 5));

    // printf("\nMax Value: %d\n", Max(arr));
    // printf("Min Value: %d\n", Min(arr));
    // printf("Total Sum: %d\n", Sum(arr));
    // printf("Total Sum Recursively: %d\n", Sum_recursive(arr.A, arr.length));
    // printf("Average: %f\n\n", Average(arr));

    // Display(arr);
    // printf("\n\nReverse:");
    // Reverse(&arr);

    // Display(arr);
    // printf("\n\nReverse auxilary array:");
    // Reverse_auxilary_array(&arr);

    // Display(arr);
    // printf("\n\nLeft Shift 4:");
    // Left_shift(&arr);

    // Display(arr);
    // printf("\n\nRight Shift 4:");
    // Right_shift(&arr);

    // Display(arr);

    // printf("\n\nSorted:");
    // Display(sorted_arr);
    // Insert_in_sorted_order(&sorted_arr, 12);
    // Display(sorted_arr);

    // printf("\n\nSorted: %d\n", Is_sorted(arr));
    // printf("Sorted: %d\n", Is_sorted(sorted_arr));

    // printf("\n\nRearrange:");
    // Display(arr);
    // Rearrange(&arr);
    // Display(arr);

    // printf("\n\nMerging:");
    // Display(sorted_arr);
    // Display(sorted_arr_2);
    // merged_arr = Merge(sorted_arr_2, sorted_arr);
    // Display(*merged_arr);

    // printf("\n\nUnion:");
    // Display(arr);
    // Display(sorted_arr_2);
    // unsorted_union_arr = Union_unsorted(arr, sorted_arr_2);
    // Display(*unsorted_union_arr);

    // printf("\n\nIntersection:");
    // intersected_arr = Intersection(sorted_arr, sorted_arr_2);
    // Display(*intersected_arr);

    // printf("\n\nDifference:");
    // difference_arr = Difference(sorted_arr, sorted_arr_2);
    // Display(*difference_arr);

    // char welcome[10] = "welcome...";

    // // // while (1 == 1)
    // // // {
    // // //     printf("%s\n", welcome);

    // // //     int i, temp;

    // // //     temp = welcome[0];

    // // //     for (i = 0; i < 10; i++)
    // // //         welcome[i] = welcome[i + 1];

    // // //     welcome[9] = temp;

    // // //     sleep(1);
    // // // }

    struct Array arr1;
    int ch = 0;
    int x, index;

    printf("Enter Size of Array: ");
    scanf("%d", &arr1.size);

    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    do
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value and index:\n");
            scanf("%d%d", &x, &index);

            Insert(&arr1, index, x);
            break;

        case 2:
            printf("Enter index of the value to delete: ");
            scanf("%d", &index);

            Delete(&arr1, index);
            break;

        case 3:
            printf("Enter element to search: ");
            scanf("%d", &x);

            index = Linear_search(arr1, x);

            printf("Element found at index: %d\n", index);
            break;

        case 4:
            printf("Sum is: %d\n", Sum(arr1));
            break;

        case 5:
            Display(arr1);
        }
    } while (ch >= 0 && ch < 6);

    return 0;
}