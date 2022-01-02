#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    t->prev = NULL;
    t->data = A[0];
    t->next = NULL;
    head = t;

    for (i = 1; i < n; i++)
    {
        t->next = (struct Node *)malloc(sizeof(struct Node));
        t->next->prev = t;
        t->next->data = A[i];
        t->next->next = NULL;
        t = t->next;
    }
}

void display()
{
    struct Node *t = head;

    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }

    printf("\n");
}

int length()
{
    int count = 0;
    struct Node *t = head;

    while (t != NULL)
    {
        count++;
        t = t->next;
    }

    return count;
}

void insert(int x, int index)
{
    if (index < 0 || index > length())
        return;

    int i;
    struct Node *n = NULL, *t = NULL;

    n = (struct Node *)malloc(sizeof(struct Node));

    n->prev = NULL;
    n->data = x;
    n->next = NULL;

    if (index == 0)
    {
        n->next = head;
        head->prev = n;
        head = n;
    }

    else
    {
        t = head;

        for (i = 1; i < index; i++)
            t = t->next;

        n->prev = t;
        n->next = t->next;

        if (t->next != NULL)
            t->next->prev = n;

        t->next = n;
    }
}

void Delete(int index)
{
    if (index < 1 || index > length())
        return;

    int i;
    struct Node *t = head;

    if (index == 1)
    {
        t = t->next;

        free(head);

        if (t != NULL)
            t->prev = NULL;

        head = t;
    }

    else
    {
        for (i = 1; i < index; i++)
            t = t->next;

        t->prev->next = t->next;

        if (t->next != NULL)
            t->next->prev = t->prev;
    }
}

void Reverse()
{
    struct Node *p, *t = head;

    while (t->next != NULL)
    {
        p = t->next;
        t->next = t->prev;
        t->prev = p;

        t = t->prev;
    }

    t->next = t->prev;
    t->prev = NULL;

    head = t;
}

int pr = 2;
int wa = 2;

int temp()
{
    return pr++ || wa++;
}

int main()
{
    int A[] = {1, 5, 9, 7, 69, 8, 3};

    create(A, 7);

    printf("\nLength: %d\n", length());
    display();

    insert(30, 4);
    printf("\nLength: %d\n", length());
    display();

    Delete(6);
    printf("\nLength: %d\n", length());
    display();

    printf("\nReversed:\n");
    Reverse();
    display();

    printf("\n\nWhat-->  %d\n", temp());
    printf("Ness-->  %d\n", pr);
    printf("Ness-->  %d\n", wa);

    return 0;
}