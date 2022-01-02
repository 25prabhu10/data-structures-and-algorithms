#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node();
};

Node::Node()
{
    next = NULL;
    data = 0;
}

class Stack
{
private:
    Node *top;

public:
    Stack();
    ~Stack();
    void Push(int);
    int Pop();
    void Display();
    int Peek(int);
    int stackTop();
    int isEmpty();
    int isFull();
};

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    Node *temp = top;

    while (temp)
    {
        top = temp->next;
        delete temp;
        temp = top->next;
    }
}

void Stack::Display()
{
    Node *p = top;

    while (p)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
}

void Stack::Push(int x)
{
    Node *t = new Node();

    if (!t)
    {
        printf("\nStack-overflow!!!\n\n");
        return;
    }

    t->data = x;
    t->next = top;

    top = t;
}

int Stack::Pop()
{
    int x = -1;
    Node *t = top;

    if (!t)
    {
        printf("\nStack-underflow!!!\n\n");
        return x;
    }

    x = t->data;

    top = t->next;

    delete t;

    return x;
}

int Stack::Peek(int pos)
{
    int i = 0;

    Node *t = top;

    if (!t)
        return -1;

    for (i = 1; i < pos; i++)
        t = t->next;

    return t->data;
}

int Stack::stackTop()
{
    if (!top)
    {
        printf("\nStack is Empty!\n");
        return -1;
    }

    return top->data;
}

int Stack::isEmpty()
{
    return top == NULL;
}

int Stack::isFull()
{
    Node *t = new Node();

    if (!t)
        return 1;

    delete t;
    return 0;
}

int main()
{
    int i, x, n;

    Stack stack;

    printf("Enter the number of elements in the Stack: ");
    scanf("%d", &n);

    printf("\nStack is Empty: %d\n", stack.isEmpty());
    printf("Stack is Full: %d\n\n", stack.isFull());

    printf("Enter Elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        stack.Push(x);
    }

    stack.Display();

    printf("\nPopped: %d\n\n", stack.Pop());

    stack.Display();

    printf("\nStack is Empty: %d\n", stack.isEmpty());
    printf("Stack is Full: %d\n\n", stack.isFull());

    printf("Stack Top: %d\n", stack.stackTop());
    printf("Peek: %d\n", stack.Peek(2));

    return 0;
}
