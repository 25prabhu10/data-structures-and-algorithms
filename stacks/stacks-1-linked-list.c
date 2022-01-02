#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void Display()
{
    struct Node *p = top;

    while (p)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
}

void Push(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if (!t)
    {
        printf("\nStack-overflow!!!\n\n");
        return;
    }

    t->data = x;
    t->next = top;

    top = t;
}

int Pop()
{
    int x = -1;
    struct Node *t = top;

    if (!t)
    {
        printf("\nStack-underflow!!!\n\n");
        return x;
    }

    x = t->data;

    top = t->next;

    free(t);

    return x;
}

int Peek(int pos)
{
    int i = 0;

    struct Node *t = top;

    if (!t)
        return -1;

    for (i = 1; i < pos; i++)
        t = t->next;

    return t->data;
}

int stackTop()
{
    if (!top)
    {
        printf("\nStack is Empty!\n");
        return -1;
    }

    return top->data;
}

int isEmpty()
{
    return top == NULL;
}

int isFull()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if (!t)
        return 1;

    free(t);
    return 0;
}

int main()
{
    int i, x, n;

    printf("Enter the number of elements in the Stack: ");
    scanf("%d", &n);

    printf("\nStack is Full: %d\n", isFull());
    printf("Stack is Empty: %d\n\n", isEmpty());

    printf("Enter Elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Push(x);
    }

    Display();

    printf("\nPopped: %d\n\n", Pop());

    Display();

    printf("\nStack is Full: %d\n", isFull());
    printf("Stack is Empty: %d\n\n", isEmpty());

    printf("Stack Top: %d\n", stackTop());
    printf("Peek: %d\n", Peek(2));

    return 0;
}
