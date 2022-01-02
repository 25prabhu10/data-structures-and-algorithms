#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *A;
};

void Display(struct Queue queue)
{
    int i = queue.front + 1;

    printf("\n\nQueue:\n");

    do
    {
        printf("%d \n", queue.A[i]);
        i = (i + 1) % queue.size;
    } while (i != (queue.rear + 1) % queue.size);
}

void Enqueue(struct Queue *queue, int x)
{
    if ((queue->rear + 1) % queue->size == queue->front)
    {
        printf("\nStack-overflow!!!\n\n");
        return;
    }

    queue->rear = (queue->rear + 1) % queue->size;
    queue->A[queue->rear] = x;
}

int Dequeue(struct Queue *queue)
{
    int x;

    if (queue->rear == queue->front)
    {
        printf("\nStack-underflow!!!\n\n");
        return -1;
    }

    queue->front = (queue->front + 1) % queue->size;

    x = queue->A[queue->front];
    queue->A[queue->front] = 0;

    return x;
}

int isEmpty(struct Queue *queue)
{
    return queue->rear == queue->front;
}

int isFull(struct Queue *queue)
{
    return (queue->rear + 1) % queue->size == queue->front;
}

int main()
{
    int i, x, n;

    struct Queue queue;

    printf("Enter the size of the queue: ");
    scanf("%d", &queue.size);

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    queue.A = (int *)malloc(queue.size * sizeof(int));
    queue.rear = -1;
    queue.front = -1;

    printf("\nqueue is Full: %d\n", isFull(&queue));
    printf("queue is Empty: %d\n\n", isEmpty(&queue));

    printf("Enter Elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        Enqueue(&queue, x);
    }

    Display(queue);

    printf("\nPopped: %d\n", Dequeue(&queue));

    Display(queue);

    printf("\n\nEnter new Element:\n");
    scanf("%d", &x);
    Enqueue(&queue, x);

    Display(queue);

    printf("\nPopped: %d\n", Dequeue(&queue));

    Display(queue);

    return 0;
}
