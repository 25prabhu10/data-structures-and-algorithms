#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void Display(struct Queue *queue)
{
    struct Node *temp = queue->front;

    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

void Enqueue(struct Queue *queue, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (!temp)
    {
        printf("Stack over flow!!!\n\n");
        return;
    }

    temp->data = x;
    temp->next = NULL;

    if (queue->front == NULL)
        queue->front = temp;
    else
        queue->rear->next = temp;

    queue->rear = temp;
}

int Dequeue(struct Queue *queue)
{
    int x = -1;
    struct Node *temp = queue->front;

    if (temp == NULL)
    {
        printf("Stack under flow!!!\n\n");
        return x;
    }

    x = temp->data;

    queue->front = temp->next;

    free(temp);

    return x;
}

int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

int main()
{
    int i, x, n;

    struct Queue queue;

    queue.front = NULL;
    queue.rear = NULL;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("queue is Empty: %d\n\n", isEmpty(&queue));

    printf("Enter Elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Enqueue(&queue, x);
    }

    Display(&queue);

    printf("\nPopped: %d\n", Dequeue(&queue));
    printf("\nPopped: %d\n", Dequeue(&queue));

    Display(&queue);

    Enqueue(&queue, 25);
    // Enqueue(&queue10);

    printf("\n\nEnter new Element:\n");
    scanf("%d", &x);
    Enqueue(&queue, x);

    Display(&queue);

    printf("\nPopped: %d\n", Dequeue(&queue));

    Display(&queue);
    return 0;
    return 0;
}