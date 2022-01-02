#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *A;
};

void Push(struct Stack *stack, char x)
{
    stack->top++;
    stack->A[stack->top] = x;
}

char Pop(struct Stack *stack)
{
    char x;

    x = stack->A[stack->top];
    stack->A[stack->top] = 0;
    stack->top--;

    return x;
}

int isEmpty(struct Stack stack)
{
    return stack.top == -1;
}

int isBalance(char *exp)
{
    struct Stack stack;
    int i;

    stack.size = strlen(exp);
    stack.top = -1;

    stack.A = (char *)malloc(stack.size * sizeof(char));

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            Push(&stack, exp[i]);

        else if (exp[i] == ')')
        {
            if (isEmpty(stack))
                return 0;

            Pop(&stack);
        }
    }

    return isEmpty(stack);
}

int main()
{
    char A[15] = {0};

    printf("Enter formula: ");
    scanf("%s", A);

    printf("\n\nIs balanced: %d\n", isBalance(A));

    return 0;
}