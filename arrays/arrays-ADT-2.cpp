#include <iostream>

using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int n)
    {
        size = n;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int newElement);
    int Delete(int index);

    int Linear_search(int key);
    int Binary_search(int key);

    int Get(int index);
    void Set(int index, int key);

    int Max();
    int Min();
    int Sum();
    float Average();

    void Reverse();
    void Left_shift();
    void Left_rotate();
    void Right_shift();
    void Right_rotate();

    void Insert_sort(int key);
    int Is_sorted();
    void Rearrange();

    Array *Merge(Array arr2);
    Array *Union(Array arr2);
    Array *Intersection(Array arr2);
    Array *Difference(Array arr2);
};

void Array::Display()
{
    int i;

    cout << "All elements are:\n";

    for (i = 0; i < length; i++)
        cout << "(" << i << ", " << A[i] << ") ";
}

void Array::Append(int x)
{
    if (length < size)
        A[length++] = x;
}

void Array::Insert(int index, int x)
{
    int i;

    if (index <= length)
    {
        for (i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }

        A[index] = x;
        length++;
    }
}

int Array::Delete(int index)
{
    int x = -1, i;

    if (index >= 0 && index < length)
    {
        x = A[index];

        for (i = index; i < length; i++)
        {
            A[i] = A[i + 1];
        }

        length--;
    }

    return x;
}

int Array::Linear_search(int key)
{
    int i;

    for (i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int Array::Binary_search(int key)
{
    int low = 0, mid, high = length - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (A[mid] == key)
            return mid;

        else if (A[mid] > key)
            high = mid - 1;

        else
            low = mid + 1;

        mid = low + high / 2;
    }

    return -1;
}

int Array::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];

    return -1;
}

void Array::Set(int index, int key)
{
    if (index >= 0 && index < length)
        A[index] = key;
}

int Array::Max()
{
    int i = 0, max = A[i];

    for (; i < length; i++)
        if (max < A[i])
            max = A[i];

    return max;
}

int Array::Min()
{
    int i = 0, min = A[i];

    for (; i < length; i++)
        if (min > A[i])
            min = A[i];

    return min;
}

int Array::Sum()
{
    int i, sum = 0;

    for (i = 0; i < length; i++)
        sum += A[i];

    return sum;
}

float Array::Average()
{
    int i, sum = 0;

    for (i = 0; i < length; i++)
        sum += A[i];

    return (float)sum / length;
}

void Array::Reverse()
{
    int i, j, temp;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = A[i];

        A[i] = A[j];

        A[j] = temp;
    }
}

void Array::Left_shift()
{
    int i;

    for (i = 0; i < length; i++)
        A[i] = A[i + 1];

    length -= 1;
}

void Array::Left_rotate()
{
    int i, temp;

    temp = A[0];

    for (i = 0; i < length; i++)
        A[i] = A[i + 1];

    A[length - 1] = temp;
}

void Array::Right_shift()
{
    int i;

    for (i = length - 1; i > 0; i--)
        A[i] = A[i - 1];

    length -= 1;
}

void Array::Right_rotate()
{
    int i, temp;

    temp = A[length - 1];

    for (i = length - 1; i > 0; i--)
        A[i] = A[i - 1];

    A[0] = temp;
}

void Array::Insert_sort(int key)
{
    int i = length - 1;

    if (length < size)
    {
        while (A[i] > key && i >= 0)
        {
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = key;
        length++;
    }
}

int Array::Is_sorted()
{
    int i;

    for (i = 0; i < length - 2; i++)
        if (A[i] > A[i + 1])
            return 0;

    return 1;
}

void Array::Rearrange()
{
    int i, j, temp;
    i = 0;
    j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;

        if (i < j)
        {
            temp = A[i];

            A[i] = A[j];

            A[j] = temp;
        }
    }
}

Array *Array::Merge(Array arr2)
{
    int i = 0, j = 0, k = 0;

    Array *arr3 = new Array(size + arr2.size);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];

        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = length + arr2.length;
    arr3->size = 20;

    return arr3;
}

Array *Array::Union(Array arr2)
{
    int i = 0, j = 0, k = 0;

    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];

        else if (A[i] > arr2.A[j])
            arr3->A[k++] = arr2.A[j++];

        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}
Array *Array::Intersection(Array arr2)
{
    int i = 0, j = 0, k = 0;

    Array *arr3 = (Array *)malloc(sizeof(Array));

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            i++;

        else if (A[i] > arr2.A[j])
            j++;

        else if (A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}

Array *Array::Difference(Array arr2)
{
    int i = 0, j = 0, k = 0;

    Array *arr3 = (Array *)malloc(sizeof(Array));

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];

        else if (A[i] > arr2.A[j])
            j++;

        else if (A[i] == arr2.A[j])
        {
            i++;
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}

int main()
{
    Array *arr1;
    int ch = 0, size = 0;
    int x, index;

    cout << "Enter Size of Array: ";
    cin >> size;

    arr1 = new Array(size);

    do
    {
        cout << "Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value and index: ";
            cin >> x >> index;

            arr1->Insert(index, x);
            break;

        case 2:
            cout << "Enter index of the value to delete: ";
            cin >> index;

            arr1->Delete(index);
            break;

        case 3:
            cout << "Enter element to search: ";
            cin >> x;

            index = arr1->Linear_search(x);

            cout << "Element found at index: " << index << endl;
            break;

        case 4:
            cout << "Sum is: " << arr1->Sum() << endl;
            break;

        case 5:
            arr1->Display();
        }
    } while (ch >= 0 && ch < 6);

    return 0;
}