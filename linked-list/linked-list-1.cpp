#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() { head = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;

    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = head;

    while (head != NULL)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

void LinkedList::Display()
{
    Node *p = head;

    while (p != NULL)
    {
        cout << p->data << " --> ";
        p = p->next;
    }

    cout << "\n";
}

int LinkedList::Length()
{
    Node *p = head;
    int count = 0;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

void LinkedList::Insert(int index, int x)
{
    if (index < 0 || index > Length())
        return;

    int i;

    Node *p = head;
    Node *t = new Node();

    t->data = x;

    if (index == 0)
    {
        t->next = head;
        head = t;
    }

    else
    {
        for (i = 1; i < index; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index)
{
    if (index < 1 || index > Length())
        return 0;

    int i;

    Node *p = head;
    Node *t = NULL;

    if (index == 1)
        head = p->next;

    else
    {
        for (i = 1; i < index; i++)
        {
            t = p;
            p = p->next;
        }

        t->next = p->next;
    }

    delete p;

    return 1;
}

int main()
{
    int A[] = {10, 11, 15, 15, 20, 20, 20, 25};

    LinkedList *head = new LinkedList(A, 8);

    head->Display();
    cout << "Length: " << head->Length() << "\n";

    head->Insert(8, 8);

    head->Display();
    cout << "Length: " << head->Length() << "\n";

    cout << "\n"
         << head->Delete(4) << "\n\n";

    head->Display();
    cout << "Length: " << head->Length() << "\n";

    return 0;
}
