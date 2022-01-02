#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *A;
};

void Display(struct Stack *stack)
{
    int i;

    for (i = 0; i <= stack->top; i++)
        printf("%d \n", stack->A[i]);
}

//! Push into Stack
//!
//! @param stack Pointer to the Stack
//! @param x The element that needs to be Pushed into the Stack
void Push(struct Stack *stack, int x)
{
    if (stack->top >= stack->size - 1)
        printf("\nStack-overflow!!!\n\n");
    // return;

    stack->top++;
    stack->A[stack->top] = x;
}

int Pop(struct Stack *stack)
{
    int x = -1;

    if (stack->top < 0)
    {
        printf("\nStack-underflow!!!\n\n");
        return x;
    }

    x = stack->A[stack->top];

    stack->A[stack->top] = 0;
    stack->top--;

    return x;
}

int Peek(struct Stack stack, int pos)
{
    if (stack.top - pos + 1 < 0)
    {
        printf("\nInvalid Position\n");
        return -1;
    }

    return stack.A[stack.top - pos + 1];
}

int stackTop(struct Stack stack)
{
    if (stack.top < 0)
    {
        printf("\nStack is Empty\n");
        return -1;
    }

    return stack.A[stack.top];
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->size - 1;
}

int main()
{
    int i, x, n;

    // struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    struct Stack stack;

    printf("Enter the size of the Stack: ");
    scanf("%d", &stack.size);

    printf("Enter the number of elements in the Stack: ");
    scanf("%d", &n);

    stack.A = (int *)malloc(stack.size * sizeof(int));
    stack.top = -1;

    printf("\nStack is Full: %d\n", isFull(&stack));
    printf("Stack is Empty: %d\n\n", isEmpty(&stack));

    printf("Enter Elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Push(&stack, x);
    }

    Display(&stack);

    printf("\nPopped: %d\n\n", Pop(&stack));

    Display(&stack);

    printf("\nStack is Full: %d\n", isFull(&stack));
    printf("Stack is Empty: %d\n\n", isEmpty(&stack));

    printf("Stack Top: %d\n", stackTop(stack));
    printf("Peek: %d\n", Peek(stack, 2));

    return 0;
}
