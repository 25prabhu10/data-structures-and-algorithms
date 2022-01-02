#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack
{
    int size;
    int top;
    int *A;
};

void Push(struct Stack *stack, int x)
{
    if (stack->top == stack->size - 1)
    {
        printf("stack over flow\n");
        return;
    }

    stack->top++;
    stack->A[stack->top] = x;
}

int Pop(struct Stack *stack)
{
    int x;

    if (stack->top < 0)
    {
        printf("stack under flow\n");
        return ' ';
    }

    x = stack->A[stack->top];
    stack->A[stack->top] = 0;
    stack->top--;

    return x;
}

int stackTop(struct Stack stack)
{
    if (stack.top < 0)
        return ' ';

    return stack.A[stack.top];
}

int isEmpty(struct Stack stack)
{
    return stack.top == -1;
}

int precedence(char x, int outStack)
{
    if (x == '+' || x == '-')
        return outStack ? 1 : 2;

    else if (x == '*' || x == '/')
        return outStack ? 3 : 4;

    else if (x == '^')
        return outStack ? 6 : 5;

    else if (x == '(')
        return outStack ? 7 : 0;

    return 0;
}

// char *infix_to_postfix(char *infix)
// {
//     struct Stack stack;
//     char temp;
//     int i = 0, j = 0;

//     stack.size = strlen(infix);
//     stack.top = -1;
//     char *postfix = (char *)malloc((stack.size + 20) * sizeof(char));

//     stack.A = (char *)malloc(stack.size * sizeof(char));

//     while (infix[i] != '\0')
//     {
//         if (isdigit(infix[i]))
//             postfix[j++] = infix[i++];

//         else
//         {
//             if (precedence(infix[i], 1) > precedence(stackTop(stack), 0))
//             {
//                 postfix[j++] = ' ';
//                 Push(&stack, infix[i++]);
//             }
//             else
//             {
//                 temp = Pop(&stack);
//                 if (temp == '(')
//                     i++;
//                 else
//                     postfix[j++] = temp;
//             }
//         }
//     }

//     while (!isEmpty(stack))
//         postfix[j++] = Pop(&stack);

//     postfix[j] = '\0';

//     return postfix;
// }

int doMath(char op, int op1, int op2)
{
    switch (op)
    {
    case '+':
        return op1 + op2;

    case '-':
        return op1 - op2;

    case '*':
        return op1 * op2;

    case '/':
        return op1 / op2;
    }

    return 0.0;
}

int evaluatePostfix(char *postfix)
{
    int i, num;
    int result;
    int operand2, operand1;
    struct Stack stack;

    stack.size = strlen(postfix);
    stack.top = -1;

    stack.A = (int *)malloc(stack.size * sizeof(int));

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] == ' ')
            continue;

        else if (isdigit(postfix[i]))
        {
            num = 0;

            while (isdigit(postfix[i]))
            {
                num = num * 10 + (int)(postfix[i] - '0');
                i++;
            }
            i--;

            Push(&stack, num);
        }

        else
        {
            operand2 = Pop(&stack);
            operand1 = Pop(&stack);
            result = doMath(postfix[i], operand1, operand2);
            Push(&stack, result);
        }
    }

    return Pop(&stack);
}

int main()
{
    char A[15] = {0};

    printf("Enter postfix form: ");
    fgets(A, 15, stdin);

    A[strlen(A) - 1] = '\0';

    // printf("Enter infix form: ");
    // scanf("%s", A);

    // char *result = infix_to_postfix(A);

    // printf("\n\nPostfix form: %s\n", result);

    printf("\n\nResult: %d\n", evaluatePostfix(A));

    return 0;
}